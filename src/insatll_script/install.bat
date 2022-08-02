@echo off
echo 洛书编程语言
echo ********************************
echo *       Losu Program Kits      *
echo *         Instaling...         *
echo *        Version  0.2.2        *
echo *           GPL_3.0            *
echo *               chen-chaochen  *
echo *                    2022/8/1  *
echo ********************************
mkdir C:\losu
mkdir C:\losu\lvm
mkdir C:\losu\bin
mkdir C:\losu\inc
mkdir C:\losu\inc\洛书

::安装可执行文件
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/windows/bin/losuc.cpp
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/windows/bin/losu.cpp
g++ -o losu.exe losu.cpp -ldl -lpthread
g++ -o losuc.exe losuc.cpp
copy .\losu.exe C:\losu\bin\losu.exe
copy .\losuc.exe C:\losuc\bin\losuc.exe
del .\*.exe
del .\*.cpp
C:\losu\bin\losu.exe
C:\losu\bin\losuc.exe
::安装标准插件
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/windows/lib/losuvm_io.cpp
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/windows/lib/losuvm_file.cpp
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/windows/lib/losuvm_mark.cpp
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/windows/lib/losuvm_math.cpp
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/windows/lib/losuvm_md5.cpp
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/windows/lib/losuvm_rand.cpp
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/windows/lib/losuvm_string.cpp
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/windows/lib/losuvm_time.cpp
g++ -shared -fPIC -o losuvm_io.lsd losuvm_io.cpp
g++ -shared -fPIC -o losuvm_file.lsd losuvm_file.cpp
g++ -shared -fPIC -o losuvm_mark.lsd losuvm_mark.cpp
g++ -shared -fPIC -o losuvm_math.lsd losuvm_math.cpp
g++ -shared -fPIC -o losuvm_md5.lsd losuvm_md5.cpp
g++ -shared -fPIC -o losuvm_rand.lsd losuvm_rand.cpp
g++ -shared -fPIC -o losuvm_string.lsd losuvm_string.cpp
g++ -shared -fPIC -o losuvm_time.lsd losuvm_time.cpp
copy .\*.lsd C:\losu\lvm\*.lsd
del .\*.lsd
del .\*.cpp
::安装基本类
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/windows/inc/MD5.losu
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/windows/inc/MD转换器.losu
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/windows/inc/标准流.losu
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/windows/inc/时间.losu
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/windows/inc/数学.losu
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/windows/inc/数组.losu
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/windows/inc/随机数.losu
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/windows/inc/文件.losu
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/windows/inc/线程.losu
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/windows/inc/字符串.losu
C:\losu\bin\losuc.exe MD5
C:\losu\bin\losuc.exe MD转换器
C:\losu\bin\losuc.exe 标准流
C:\losu\bin\losuc.exe 时间
C:\losu\bin\losuc.exe 数学
C:\losu\bin\losuc.exe 数组
C:\losu\bin\losuc.exe 随机数
C:\losu\bin\losuc.exe 文件
C:\losu\bin\losuc.exe 线程
C:\losu\bin\losuc.exe 字符串
copy .\*.lsc C:\losu\inc\洛书\*.lsc
del .\*.lsc
del .\*.losu
::结束安装
C:\losu\bin\losu.exe
C:\losu\bin\losuc.exe
echo 洛书汉语编程语言 安装结束
echo 请将C:\losu\bin 目录添加到path环境变量下
pause