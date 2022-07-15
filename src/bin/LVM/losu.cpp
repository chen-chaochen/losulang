#include "losu_head.h"
#include "pub_func.h"
#include "ls_func.h"
using namespace std;
extern "C"{
int main(int argc,const char** argv)
{
    try
    {
        main_argc = argc;
        main_argv = argv;
        if (command() == "")
        {
            throw "¬Â È∫∫”Ô±‡≥Ã\nLosu 0.1\n(c) Chen-chaochen\nMaked by GNU C++\nStd = IOS14\nLicense GPL-3.0\n";
        }
        mainfile = curdir() + command() + ".lsc";
        ls_vm vim;
        array_start();
        vim.hostfile(mainfile,getcsip()); 
		pthread_exit(NULL);
    }
    catch(const char* _errinfo)
    {
       cout<< trmate(_errinfo);
    }
    

}
}

