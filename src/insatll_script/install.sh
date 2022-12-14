echo "
洛书编程语言
********************************
*       Losu Program Kits      *
*         Instaling...         *
*        Version  0.2.2        *
*           GPL_3.0            *
*               chen-chaochen  *
*                    2022/8/1  *
********************************
"
mkdir /usr/local/lib/losu
#安装可执行文件
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/linux/bin/losuc.cpp
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/linux/bin/losu.cpp
g++ -o losu losu.cpp -ldl -lpthread
g++ -o losuc losuc.cpp
cp ./losu /usr/local/bin/
cp ./losuc /usr/local/bin/
rm ./losu
rm ./losuc
rm ./*.cpp
losu
losuc
#安装标准插件
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/linux/lib/losuvm_io.cpp
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/linux/lib/losuvm_file.cpp
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/linux/lib/losuvm_mark.cpp
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/linux/lib/losuvm_math.cpp
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/linux/lib/losuvm_md5.cpp
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/linux/lib/losuvm_rand.cpp
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/linux/lib/losuvm_string.cpp
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/linux/lib/losuvm_time.cpp
g++ -shared -fPIC -o losuvm_io.lsd losuvm_io.cpp
g++ -shared -fPIC -o losuvm_file.lsd losuvm_file.cpp
g++ -shared -fPIC -o losuvm_mark.lsd losuvm_mark.cpp
g++ -shared -fPIC -o losuvm_math.lsd losuvm_math.cpp
g++ -shared -fPIC -o losuvm_md5.lsd losuvm_md5.cpp
g++ -shared -fPIC -o losuvm_rand.lsd losuvm_rand.cpp
g++ -shared -fPIC -o losuvm_string.lsd losuvm_string.cpp
g++ -shared -fPIC -o losuvm_time.lsd losuvm_time.cpp
mkdir /usr/local/lib/losu/lvm
cp ./*.lsd /usr/local/lib/losu/lvm/
rm ./*.lsd
rm ./*.cpp
#安装基本类
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/linux/inc/MD5.losu
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/linux/inc/MD转换器.losu
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/linux/inc/标准流.losu
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/linux/inc/时间.losu
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/linux/inc/数学.losu
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/linux/inc/数组.losu
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/linux/inc/随机数.losu
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/linux/inc/文件.losu
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/linux/inc/线程.losu
wget https://gitee.com/chen-chaochen/lpk/raw/release/losu0.2/linux/inc/字符串.losu
losuc MD5
losuc MD转换器
losuc 标准流
losuc 时间
losuc 数学
losuc 数组
losuc 随机数
losuc 文件
losuc 线程
losuc 字符串
mkdir /usr/local/lib/losu/inc
mkdir /usr/local/lib/losu/inc/洛书
cp ./*.lsc /usr/local/lib/losu/inc/洛书/
rm ./*.losu
rm ./*.lsc
losuc
losu

echo "洛书汉语编程语言 安装结束"

