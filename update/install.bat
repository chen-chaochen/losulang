@echo off
echo 洛书编程语言 1.0 LTS
echo ********************************
echo *       Losu Program Kits      *
echo *         Instaling...         *
echo *        Version  1.0          *
echo *           L  T  S            *
echo *               chen-chaochen  *
echo *                    2022/8/1  *
echo ********************************
mkdir C:\losu
mkdir C:\losu\lvm
mkdir C:\losu\bin
mkdir C:\losu\inc
mkdir C:\losu\inc\洛书

::安装可执行文件
wget --no-check-certificate https://gitee.com/chen-chaochen/lpk/raw/release/losu1.0lts/windows/bin/losuc.cpp
wget --no-check-certificate https://gitee.com/chen-chaochen/lpk/raw/release/losu1.0lts/windows/bin/losu.cpp
wget --no-check-certificate https://gitee.com/chen-chaochen/lpk/raw/release/losu1.0lts/windows/bin/hetu.cpp
g++ -std=c++11 -static -o losu.exe losu.cpp -ldl -lpthread
g++ -std=c++11 -static -o losuc.exe losuc.cpp
g++ -std=c++11 -static -o hetu.exe hetu.cpp
copy .\losu.exe C:\losu\bin\losu.exe
copy .\losuc.exe C:\losuc\bin\losuc.exe
copy .\hetu.exe C:\losu\bin\hetu.exe
copy .\hetu.exe C:\losu\bin\河图.exe
del .\*.exe
del .\*.cpp
::安装标准插件
wget --no-check-certificate https://gitee.com/chen-chaochen/lpk/raw/release/losu1.0lts/windows/lib/losuvm_io.cpp
wget --no-check-certificate https://gitee.com/chen-chaochen/lpk/raw/release/losu1.0lts/windows/lib/losuvm_file.cpp
wget --no-check-certificate https://gitee.com/chen-chaochen/lpk/raw/release/losu1.0lts/windows/lib/losuvm_mark.cpp
wget --no-check-certificate https://gitee.com/chen-chaochen/lpk/raw/release/losu1.0lts/windows/lib/losuvm_math.cpp
wget --no-check-certificate https://gitee.com/chen-chaochen/lpk/raw/release/losu1.0lts/windows/lib/losuvm_md5.cpp
wget --no-check-certificate https://gitee.com/chen-chaochen/lpk/raw/release/losu1.0lts/windows/lib/losuvm_rand.cpp
wget --no-check-certificate https://gitee.com/chen-chaochen/lpk/raw/release/losu1.0lts/windows/lib/losuvm_string.cpp
wget --no-check-certificate https://gitee.com/chen-chaochen/lpk/raw/release/losu1.0lts/windows/lib/losuvm_time.cpp
wget --no-check-certificate https://gitee.com/chen-chaochen/lpk/raw/release/losu1.0lts/windows/lib/losuvm_gpio.cpp
wget --no-check-certificate https://gitee.com/chen-chaochen/lpk/raw/release/losu1.0lts/windows/lib/losuvm_webui.cpp
g++ -std=c++11 -shared -fPIC -o losuvm_io.lsd losuvm_io.cpp
g++ -std=c++11 -shared -fPIC -o losuvm_file.lsd losuvm_file.cpp
g++ -std=c++11 -shared -fPIC -o losuvm_mark.lsd losuvm_mark.cpp
g++ -std=c++11 -shared -fPIC -o losuvm_math.lsd losuvm_math.cpp
g++ -std=c++11 -shared -fPIC -o losuvm_md5.lsd losuvm_md5.cpp
g++ -std=c++11 -shared -fPIC -o losuvm_rand.lsd losuvm_rand.cpp
g++ -std=c++11 -shared -fPIC -o losuvm_string.lsd losuvm_string.cpp
g++ -std=c++11 -shared -fPIC -o losuvm_time.lsd losuvm_time.cpp
g++ -std=c++11 -shared -fPIC -o losuvm_gpio.lsd losuvm_gpio.cpp
g++ -std=c++11 -shared -fPIC -o losuvm_webui.lsd losuvm_webui.cpp
copy .\*.lsd C:\losu\lvm\*.lsd
del .\*.lsd
del .\*.cpp
::安装基本类
wget --no-check-certificate https://gitee.com/chen-chaochen/lpk/raw/release/losu1.0lts/windows/inc/MD5.losu
wget --no-check-certificate https://gitee.com/chen-chaochen/lpk/raw/release/losu1.0lts/windows/inc/MD转换器.losu
wget --no-check-certificate https://gitee.com/chen-chaochen/lpk/raw/release/losu1.0lts/windows/inc/标准流.losu
wget --no-check-certificate https://gitee.com/chen-chaochen/lpk/raw/release/losu1.0lts/windows/inc/时间.losu
wget --no-check-certificate https://gitee.com/chen-chaochen/lpk/raw/release/losu1.0lts/windows/inc/数学.losu
wget --no-check-certificate https://gitee.com/chen-chaochen/lpk/raw/release/losu1.0lts/windows/inc/数组.losu
wget --no-check-certificate https://gitee.com/chen-chaochen/lpk/raw/release/losu1.0lts/windows/inc/随机数.losu
wget --no-check-certificate https://gitee.com/chen-chaochen/lpk/raw/release/losu1.0lts/windows/inc/文件.losu
wget --no-check-certificate https://gitee.com/chen-chaochen/lpk/raw/release/losu1.0lts/windows/inc/线程.losu
wget --no-check-certificate https://gitee.com/chen-chaochen/lpk/raw/release/losu1.0lts/windows/inc/字符串.losu
wget --no-check-certificate https://gitee.com/chen-chaochen/lpk/raw/release/losu1.0lts/windows/inc/错误处理.losu
wget --no-check-certificate https://gitee.com/chen-chaochen/lpk/raw/release/losu1.0lts/windows/inc/引脚.losu
wget --no-check-certificate https://gitee.com/chen-chaochen/lpk/raw/release/losu1.0lts/windows/inc/通用引脚.losu
wget --no-check-certificate https://gitee.com/chen-chaochen/lpk/raw/release/losu1.0lts/windows/inc/网页.losu
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
C:\losu\bin\losuc.exe 错误处理
C:\losu\bin\losuc.exe 引脚
C:\losu\bin\losuc.exe 通用引脚
C:\losu\bin\losuc.exe 网页
copy .\*.lsc C:\losu\inc\洛书\*.lsc
del .\*.lsc
del .\*.losu
wget --no-check-certificate https://gitee.com/chen-chaochen/lpk/raw/release/losu1.0lts/sources.tar
::结束安装
C:\losu\bin\losu.exe
C:\losu\bin\losuc.exe
C:\losu\bin\hetu.exe
echo 洛书汉语编程语言 安装结束
echo 请将C:\losu\bin 目录添加到path环境变量下
pause