/*
洛书拓展    服务器模组
适用于Linux系统
移植在windows时可采用 Cygwin或Win API
开发者 c & fsh 
2022/7/27
遵循GLP-3.0开源协议
*/


/*
用于搭建简易的服务器模组
可以支持静态/动态网页(CGI)
适用于利用洛书快速构建web服务
已经集成在洛书0.2.4+ Linux版本的基本类中
*/

#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <cstddef>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string>
#include <cstring>
#include <wait.h>
using namespace std;



int MAXLINE = 100;
vector<string> _ls_filetype,_ls_filename;

ssize_t rio_writen(int fd, void *userbuf, size_t n)
{
    size_t nleft = n;
    ssize_t nwrite;
    char *bufp = (char*)userbuf;


    while(nleft > 0)
    {
        if((nwrite = write(fd, bufp, nleft))<0)
        {
            if(errno == EINTR)
                nwrite = 0;
            else
                return -1;
        }


        nleft -= nwrite;
        bufp += nwrite;
    }

    return n;

}

static const int RIO_BUFSIZE = 8192;

struct rio_t
{
    int     rio_fd;             
    int     rio_cnt;            
    char    *rio_bufptr;        
    char    rio_buf[RIO_BUFSIZE];
};

void rio_readinitb(rio_t *rp, int fd)
{
    rp->rio_fd = fd;
    rp->rio_cnt = 0;
    rp->rio_bufptr = rp->rio_buf;
}

ssize_t rio_read(rio_t *rp, void *userbuf, size_t n)
{


    while(rp->rio_cnt <= 0)
    {
        rp->rio_cnt = read(rp->rio_fd, rp->rio_buf, sizeof(rp->rio_buf));

        if(rp->rio_cnt < 0)
        {
            if(errno != EINTR)
                return -1;
        }
        else if (rp->rio_cnt == 0)
            return 0;
        else
            rp->rio_bufptr = rp->rio_buf;
    }



    size_t cnt = n > rp->rio_cnt ? rp->rio_cnt : n;


    memcpy(userbuf, rp->rio_bufptr, cnt);

    rp->rio_bufptr += cnt;
    rp->rio_cnt -= cnt;

    return cnt;
}

ssize_t rio_readlineb(rio_t *rp, void *userbuf, size_t maxlen)
{
    ssize_t readn;
    char c;
    char *buf = (char*)userbuf;
    int i;
    for(i = 1; i < maxlen; ++i)
    {
        readn = rio_read(rp, &c, 1);
        if(readn < 0)
            return -1;
        else if (readn == 0)
        {
            if(i == 1)
                return 0;
            else
                break;
        }
        else
        {
            *buf++ = c;
            if(c == '\n')
            {
                ++i;
                break;
            }
        }



    }

    *buf = 0;
    return i-1;

}

int open_listenfd(const char *port)
{
    addrinfo hints, *listp, *p;
    int listenfd, optval = 1;

    memset(&hints, 0, sizeof(addrinfo));
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE | AI_ADDRCONFIG;
    hints.ai_flags |= AI_NUMERICSERV;
    getaddrinfo(NULL, port, &hints, &listp);

    for(p = listp; p; p = p->ai_next)
    {
        if((listenfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0)
            continue;

        setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(int));

        if(bind(listenfd, p->ai_addr, p->ai_addrlen) == 0)
            break;

        close(listenfd);
    }

    freeaddrinfo(listp);
    if(!p)
        return -1;

    if(listen(listenfd, 3) < 0)
    {
        close(listenfd);
        return -1;
    }

    return listenfd;
}


void doit(int fd);                  
void read_requesthdrs(rio_t *rp);   
int  parse_uri(char *uri, char *filename, char *cgiargs);   
void serve_static(int fd, char *filename, int filesize);   
void get_filetype(char *filename, char *filetype);        
void serve_dynamic(int fd, char *filename, char *cgiargs); 
void clienterror(int fd, char *cause, int errnum, std::string shortmsg, std::string longmsg); 


void doit(int fd)
{
    int is_static;
    struct stat sbuf;
    char buf[MAXLINE], method[MAXLINE], uri[MAXLINE], version[MAXLINE];
    char filename[MAXLINE], cgiargs[MAXLINE];
    rio_t rio;


    rio_readinitb(&rio, fd);
    rio_readlineb(&rio, buf, MAXLINE);
    printf("Request headers:\n");
    printf("%s\n", buf);
    sscanf(buf, "%s %s %s",method, uri, version);
   
    if(strcasecmp(method, "GET"))
    {
        clienterror(fd, method, 501, "Not implemented", "losu does not implement this method");
        return;

    }
    read_requesthdrs(&rio);

    is_static = parse_uri(uri, filename, cgiargs);


    
    if(stat(filename, &sbuf) < 0)
    {

        clienterror(fd, filename, 404, "Not Found", "losu couldn't find the file");
        return;
    }
   
    if(is_static)
    {
        if(!(S_ISREG(sbuf.st_mode)) || !(S_IRUSR & sbuf.st_mode))
        {
            clienterror(fd, filename, 403, "Forbidden", "losu couldn't read the file");
            return;
        }


        serve_static(fd, filename, sbuf.st_size);
    }
    else
    {
        if(!(S_ISREG(sbuf.st_mode)) || !(S_IXUSR & sbuf.st_mode))
        {
            clienterror(fd, filename, 403, "Forbidden", "losu couldn't run the CGI program");
            return;
        }
      
        serve_dynamic(fd, filename, cgiargs);
    }



}


void clienterror(int fd, char *cause, int errnum, std::string shortmsg, std::string longmsg)
{
    char buf[MAXLINE], body[MAXLINE];

    sprintf(body, "<html><title>losu ERROR</title>");
    sprintf(body, "%s<body bgcolor=""ffffff"">\r\n", body);
    sprintf(body, "%s%d: %s\r\n", body, errnum, shortmsg.c_str());
    sprintf(body, "%s<p>%s: %s\r\n", body, longmsg.c_str(), cause);
    sprintf(body, "%s<hr><em>The losu Web server</em>\r\n", body);

    sprintf(buf, "HTTP/1.0 %d %s\r\n",errnum, shortmsg.c_str());
    rio_writen(fd, buf, strlen(buf));
    sprintf(buf, "Content-type: text/html\r\n");
    rio_writen(fd, buf, strlen(buf));
    sprintf(buf, "Content-length: %d\r\n\r\n", (int)strlen(body));
    rio_writen(fd, buf, strlen(buf));
    rio_writen(fd, body, strlen(body));

}

void read_requesthdrs(rio_t *rp)
{
    char buf[MAXLINE];

    rio_readlineb(rp, buf, MAXLINE);
   
    while(strcmp(buf, "\r\n"))
    {
        rio_readlineb(rp, buf, MAXLINE);

    }
    return;
}

int parse_uri(char *uri, char *filename, char *cgiargs)
{
    /*
    这个函数定义了获取文件路径的方式
    wwwroot =  ./
    CGI = ./cgi-bin/
    index = index.html
    */


    char *ptr;
    if(!strstr(uri, "cgi-bin"))
    {
        strcpy(cgiargs, "");
        strcpy(filename, ".");
        strcat(filename, uri);
        if(uri[strlen(uri)-1] == '/')
            strcat(filename, "index.html");

        return 1;


    }
    else
    {
        ptr = index(uri, '?');

        if(ptr)
        {
            strcpy(cgiargs, ptr+1);
            *ptr = '\0';
        }
        else
        {
            strcpy(cgiargs, "");
        }

        strcpy(filename, ".");
        strcat(filename, uri);
        return 0;
    }
}


void get_filetype(char *filename, char *filetype)
{
    /*
    这个函数定义了文件类型
    你可以在其中添加所需的类型
    */
    /*
    if(strstr(filename, ".html"))
        strcpy(filetype, "text/html");
	else if(strstr(filename, ".htm"))
		strcpy(filetype, "text/html");
	else if(strstr(filename, ".css"))
		strcpy(filetype, "text/css");
	else if(strstr(filename, ".js"))
		strcpy(filetype, "text/javascript");
    else if(strstr(filename, ".gif"))
        strcpy(filetype, "image/gif");
    else if(strstr(filename, ".png"))
        strcpy(filetype, "image/png");
    else if(strstr(filename, ".jpg"))
        strcpy(filetype, "image/jpg");
    else
        strcpy(filetype, "application/zip");
    */
    for (int i = 0; i < _ls_filetype.size(); i++)
    {
        if(strstr(filename,_ls_filename[i].c_str()))
        {
            strcpy(filetype, "text/html");
            return;
        }
    }
    strcpy(filetype, "application/zip");
}

void serve_static(int fd, char *filename, int filesize)
{

    char *srcp, filetype[MAXLINE], buf[MAXLINE];

    get_filetype(filename, filetype);

    sprintf(buf, "HTTP/1.0 200 OK\r\n");
    sprintf(buf, "%sServer: losu Web Server\r\n", buf);
    sprintf(buf, "%sConnection: close\r\n", buf);
    sprintf(buf, "%sContent-length: %d\r\n", buf, filesize);
    sprintf(buf, "%sContent-type: %s\r\n\r\n", buf, filetype);
    rio_writen(fd, buf, strlen(buf));
    printf("Response headers:\n");
    printf("%s", buf);
    int srcfd = open(filename, O_RDONLY, 0);
    srcp = (char*)mmap(0, filesize, PROT_READ, MAP_PRIVATE, srcfd, 0);
    close(srcfd);
    rio_writen(fd, srcp, filesize);
    munmap(srcp, filesize);

}

void serve_dynamic(int fd, char *filename, char *cgiargs)
{
    char buf[MAXLINE], *emptylist[] = {NULL};
    char *envp[]={0,NULL};

    sprintf(buf, "HTTP/1.0 200 OK\r\n");
    rio_writen(fd, buf, strlen(buf));
    sprintf(buf, "Server: losu Web Server\r\n");
    rio_writen(fd, buf, strlen(buf));
    if(fork() == 0)
    {
        setenv("QUERY_STRING", cgiargs, 1);
        dup2(fd, STDOUT_FILENO);
        execve(filename, emptylist, envp);
		return;
    }
    wait(NULL);
}

extern "C"
{
	string ls_httpd_start(const char* com) 
    {
        if (conf == 1)
        {
            return "";
        }
        conf = 1;
    	int listenfd, connfd;
    	char hostname[MAXLINE], port[MAXLINE];
    	socklen_t clientlen;
    	sockaddr_storage clientaddr;
    	listenfd = open_listenfd(com);  
		while(1<2)    
    	{
    	    clientlen = sizeof(clientaddr);
    	    connfd = accept(listenfd, (sockaddr*)&clientaddr, &clientlen);
    	    getnameinfo((sockaddr*)&clientaddr, clientlen, hostname, MAXLINE, port, MAXLINE, 0);       
    	    printf("Accepted connection from (%s, %s)\n", hostname, port);
	        doit(connfd);
    	    close(connfd);
	    }
	    return "";
    }
    string ls_httpd_addconf(const char* filename,const char* filetype)
    {
        string tmp;
        tmp = filename;
        _ls_filename.push_back(tmp);
        tmp = filetype;
        _ls_filetype.push_back(tmp);
        return "1";
    }

}

