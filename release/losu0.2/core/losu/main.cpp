int main(int argc,const char** argv)
{
    try
    {
        main_argc = argc;
        main_argv = argv;
        ls_vm vim;
        if (command() == "")
        {
            throw "洛书汉语编程开发组件\nLosu Program Kits\nLosu 0.2.2\n洛书解释器\n(c) Chen-chaochen\nLicense GPL-3.0\n";
        }
        mainfile = command();
        array_start();
        vim.hostfile(mainfile,getcsip()); 
		pthread_exit(NULL);
    }
    catch(const char* _errinfo)
    {

    	cout<< _errinfo;
    }
    

}