/*
基于洛书的一个第三方编译器
将河图代码编译为洛书标准代码
兼容洛书1.0LTS标准
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define 字符串 string

字符串 替换(字符串 src, 字符串 老字符串,字符串 新字符串);
字符串 截取(字符串 a,long b,long c);
字符串 替换(字符串 src,字符串 老字符串,字符串 新字符串) 
{
    long i;
	字符串 rep;
	i = 1;
	do
	{
		if (截取(src,i,老字符串.length()) == 老字符串 )
		{
			i = i + 老字符串.length() -1;
			rep = rep + 新字符串;
		}
		else
		{
			rep = rep + 截取(src,i,1);
		}
		i++;
		if (i > src.length())
		{
			rep = rep + 截取(src,i,1);
			break;
		}
	} while (1 < 2);
	return rep;
}
字符串 截取(字符串 a,long start_pos,long len_pos)
{
    if (start_pos > a.length())
    {
        return "";
    }
	return a.substr(start_pos - 1,len_pos);
}
字符串 mid(字符串 a,long start_pos,long len_pos)
{
    if (start_pos > a.length())
    {
        return "";
    }
	return a.substr(start_pos - 1,len_pos);
}
字符串 replace_all(字符串 src,字符串 老字符串,字符串 新字符串) 
{
    long i;
	字符串 rep;
	i = 1;
	do
	{
		if (截取(src,i,老字符串.length()) == 老字符串 )
		{
			i = i + 老字符串.length() -1;
			rep = rep + 新字符串;
		}
		else
		{
			rep = rep + 截取(src,i,1);
		}
		i++;
		if (i > src.length())
		{
			rep = rep + 截取(src,i,1);
			break;
		}
	} while (1 < 2);
	return rep;
}
string space(string a,int b)
{
    string tmp;
    for(int i = 0;i<b;i++)
    {
        tmp = tmp + " ";
    }
    tmp = tmp + a;
    return tmp;
}
int tab;
long linenum;
void 预编译(字符串 文件)
{
    linenum = 0;
    ifstream fs_in;
    ofstream fs_out;
    try
    {
        //打开mainfile
        fs_in.open(文件+".hetu");
        fs_out.open(文件+".losu");
        do
        {
            字符串 tmp;
            getline(fs_in,tmp);
            linenum++;
            int i;
            i = 1;
            if(replace_all(tmp," ","") == "")
            {
                continue;
            }
            do
            {
                if(mid(tmp,i,1) != " ")
                {
                    break;
                }
                i++;
            }while(i<=tmp.length());
            if(mid(tmp,i,1) == "#")
            {
                tmp = mid(tmp,1,i-1)+"+"+mid(tmp,i+1,tmp.length()-i);
            }
            if(mid(tmp,i,2) == "/*")
            {
                tmp = mid(tmp,1,i-1)+"/{"+mid(tmp,i+2,tmp.length()-i-1);
            }
            if(i == tab + 4)
            {  
                fs_out<<"{"<<endl;
                fs_out<<tmp<<endl;
                tab=tab+4;
            }
            else if((i-1) % 4 == 0 && i < tab)
            {
                for (int j = i;j < tab; j = j+4)
                {
                    fs_out<<"}"<<endl;
                }
                fs_out<<tmp<<endl;
                tab = i;
            }
            else if(i == tab)
            {
                fs_out<<tmp<<endl;
            }
            else
            {
                throw "错误的缩进格式\n";
            }

        }while(fs_in.eof()==0);
        if (tab != 1)
        {
            for(int k = 1;k < tab; k=k+4)
            {
                fs_out<<"}"<<endl;
            }
        }
        fs_in.close();
        fs_out.close();

    }
    catch(const char* 错误信息)
    {
        fs_in.close();
        fs_out.close();
        cout<< "河图编译器\n####错误####\n在源文件 "<<文件<<".hetu 中\n第: "<<linenum<<" 行\n";
        cout<<错误信息<<endl;
        remove((文件+".losu").c_str());
        exit(linenum);
    }
    return;
}

int main(int argc,const char** argv)
{
    tab = 1;
    if(argc == 2)
    {
        字符串 mainfile = argv[1];
        预编译(mainfile);
        ifstream i;
        i.open((mainfile+".hetu").c_str());
        if(i.is_open()==0)
        {
            cout<<"没有指定文件"<<endl;
            exit(0);
        }
        if(system(("losuc "+ mainfile).c_str())!=0)
        {
            return 1;
        }
        //remove((mainfile+".losu").c_str());
        return 0;
    }
    cout<<"河图编译器 1.0"<<endl;
    return 0;
}