```
/*
    Information
    LOSU expand_pac  logo_graphic based on EasyX or libgraph
    This can work on losu1.0_LTS+
    (c) chen-chaochen
    MIT

    基本信息
    一个类似于LOGO的拓展库，基于EasyX或者libgrapth封装实现
    适用于 洛书1.0LTS 及以上的版本
    (c) 陈朝臣
    代码遵循 MIT 协议
*/ 

/*
    如何安装
    1.安装C库
        *****WINDOWS*****
            ***从源码安装***
                1. 下载EasyX库，将它添加到编译器里。
                2. 编译losuvm_logo.cpp,生成shared文件losuvm_logo.lsd并复制到C:\losu\lvm目录下
            ***从二进制安装***
                1. 下载合适位数的 losuvm_logo.lsd(x86/x64)，复制到C:\losu\lvm目录下，重命名为 losuvm_logo.lsd
        *****LINUX*****
            ***安装libgrapth***
            ***从源码安装***
                1. 下载losuvm_logo.cpp，编译生成 losuvm_logo.lsd 复制到LS_ROOT/losu/lvm

    2.编译洛书库
        losuc 画图
        将 画图.lsc复制到LS_ROOT/inc下
*/
```