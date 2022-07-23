用freebasic编写的洛书拓展模块
作为对洛书拓展性的验证
遵循GPL-3.0开源协议

安装方法
1.下载源码包losuvm_cmdsys.zip
2.安装编译工具freebasic 
3.用如下命令编译生成动态库
	fbc -dll -o losuvm_cmdsys.lsd losuvm_cmd.bas
4.将动态库复制到LS_VM_ROOT 即(LS_ROOT/lvm目录下)
5.编译洛书代码 控制台.losu、系统.losu，将生成的lsc文件复制到./inc/下您想要的位置

关于fb与洛书交互的注意事项

洛书的lvm 对应const chat*
fb的zstring对应unsigned char*
当洛书向fb传递信息时，这两者可以兼容
但FB的function不支持zstring，只能用string
FB的string类型对应一个char[]组成的类型
FB向洛书传递信息时会丢失信息
这个问题的改进需要修改FB编译器
