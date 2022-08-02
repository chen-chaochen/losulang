int main(int argc,const char** argv)
{
    lsc cpr1;
    main_argc = argc;
    main_argv = argv;
    if (argc == 1)
    {
        cout<<"洛书汉语编程开发组件\nLosu Program Kits\nLosu 0.2.2\n洛书编译器\n(c) Chen-chaochen\nLicense GPL-3.0\n";
    }
    else
    {
        cpr1.compile(argv[1]);
    }
    exit(0);
    return 0;
}