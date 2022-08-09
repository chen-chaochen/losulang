# 洛书重启
### 重启
移除原有的代码及发行版,放弃原有软件架构，更换了新的开源许可证<br>
QQ交流群 805995065<br>
Demo 见expand分支
文档 见wiki与doc分支

### 定位
+ 自主设计，中文编程    洛书源代码 ——> 洛书指令 ——> 洛书程序
+ 跨平台支持    兼容主流操作系统
+ 开放透明    C++实现，源码，架构及工作原理完全开放
+ 简单高效    语法简捷，"胶水语言"，支持调用标准C/C++等函数库
+ 多用途      编程入门，自动化脚本，网络编程，物联网设备，嵌入式编程
+ 语法糖架构    所有的编译器与前端都是在 洛书指令语言 基础上进行加糖，通过加糖，可以构建不同语法的洛书语言

打造开源，简单，强大的国产中文(utf-8/gbk)编程语言
![洛书在国产系统上运行的截图](%E6%B4%9B%E4%B9%A6%E7%A4%BA%E4%BE%8B%E4%BB%A3%E7%A0%81/%E6%B4%9B%E4%B9%A6%E7%A8%8B%E5%BA%8F/%E5%BC%80%E6%94%BE%E9%BA%92%E9%BA%9F.jpg)
![输入图片说明](%E6%B4%9B%E4%B9%A6%E7%A4%BA%E4%BE%8B%E4%BB%A3%E7%A0%81/%E6%B4%9B%E4%B9%A6%E7%A8%8B%E5%BA%8F/%E9%BA%92%E9%BA%9F.jpg)

<br>开放麒麟运行洛书
### 洛书编程组件 losu programme kit
开发洛书时的工作环境
+ losu   VM解释器
+ losuc 编译器
+ lpt 洛书包管理器
### 安装&更新
洛书采用类似镜像源的安装方式，通过一行命令，即可快速安装,更新洛书的最新版本
+ windows

```
wget https://gitee.com/chen-chaochen/lpk/raw/release/update/install.bat&install.bat
```

+ linux

```
wget https://gitee.com/chen-chaochen/lpk/raw/release/update/install.sh&&sudo bash ./install.sh
```


### Demo
#### [1. 嵌入式编程](https://gitee.com/chen-chaochen/lpk/tree/expand/Demo/%E7%89%A9%E8%81%94%E7%BD%91-%E6%99%BA%E8%83%BD%E5%AE%B6%E5%B1%85%E9%9B%8F%E5%BD%A2)

```
//文件 ./cgi-bin/洛书的家.losu
+导入 洛书·引脚
+实例 引脚 引脚18
+类 洛书的家
{
    //用接在gpio18上的LED灯模拟客厅顶灯
    +方法 客厅顶灯()
    {
        +方法 点亮()
        {
            引脚18·设定("18","1")
            引脚18·写入("1")
        }
        +方法 熄灭()
        {
            引脚18·设定("18","1")
            引脚18·写入("0")
            引脚18·卸载()
        }
    }
}
```
[[运行视频]](https://gitee.com/chen-chaochen/lpk/raw/expand/Demo/%E7%89%A9%E8%81%94%E7%BD%91-%E6%99%BA%E8%83%BD%E5%AE%B6%E5%B1%85%E9%9B%8F%E5%BD%A2/%E8%BF%90%E8%A1%8C%E8%A7%86%E9%A2%91.mp4)

```
//文件 ./cgo-bin/light_on.losu
+加载 开始
+导入 洛书·标准流
+实例 标准流 标准流
+引用 洛书的家
+实例 洛书的家 洛书的家
+方法 开始()
{
    洛书的家·客厅顶灯·点亮()
}
```

#### [2. 宇宙文明模拟器](https://gitee.com/chen-chaochen/lpk/tree/expand/Demo/%E5%AE%87%E5%AE%99%E6%96%87%E6%98%8E%E6%A8%A1%E6%8B%9F%E5%99%A8)
![模拟器](https://gitee.com/chen-chaochen/lpk/raw/expand/Demo/%E5%AE%87%E5%AE%99%E6%96%87%E6%98%8E%E6%A8%A1%E6%8B%9F%E5%99%A8/运行截图.png)
![终端](https://gitee.com/chen-chaochen/lpk/raw/expand/Demo/%E5%AE%87%E5%AE%99%E6%96%87%E6%98%8E%E6%A8%A1%E6%8B%9F%E5%99%A8/运行截图2.png)

#### [3. 宇宙文明模拟器服务器版本](https://gitee.com/chen-chaochen/lpk/tree/expand/Demo/宇宙文明模拟器服务器版)
![输入图片说明](Demo/%E9%BB%91%E6%9A%97%E6%A3%AE%E6%9E%97%E6%88%AA%E5%9B%BE.png)
![输入图片说明](%E9%BB%91%E6%9A%97%E6%A3%AE%E6%9E%97%E6%88%AA%E5%9B%BE2.png)
![输入图片说明](Demo/%E9%BB%91%E6%9A%97%E6%A3%AE%E6%9E%97%E6%9C%8D%E5%8A%A1%E5%99%A8.png)

#### [4. 洛书CGI编程](https://gitee.com/chen-chaochen/lpk/blob/master/%E6%B4%9B%E4%B9%A6CGI%E7%BC%96%E7%A8%8B.md)
![输入图片说明](Demo/CGI.png)

#### [5. 洛书服务器](https://gitee.com/chen-chaochen/lpk/tree/expand/%E6%B4%9B%E4%B9%A6%E6%9C%8D%E5%8A%A1%E5%99%A8)
![服务器服务端](Demo/%E6%9C%8D%E5%8A%A1%E5%99%A8.png)
![服务器客户端](Demo/%E6%9C%8D%E5%8A%A1%E5%99%A82.png)

### 加入洛书
1. 加入仓库,参与洛书标准的制定及LPK组件的开发
2. 在expand分支提交pr，参与洛书拓展库的开发
3. fork本仓库
4. 加入讨论群，共同进步
#### 示例代码
demo 请见 [[链接]](https://gitee.com/chen-chaochen/lpk/tree/expand/Demo)

入门示例请见 [[链接]](https://gitee.com/chen-chaochen/lpk/tree/master/%E6%B4%9B%E4%B9%A6%E7%A4%BA%E4%BE%8B%E4%BB%A3%E7%A0%81)

![输入图片说明](%E6%B4%9B%E4%B9%A6%E7%A4%BA%E4%BE%8B%E4%BB%A3%E7%A0%81/%E6%B4%9B%E4%B9%A6%E7%A8%8B%E5%BA%8F/3.png)
![输入图片说明](%E6%B4%9B%E4%B9%A6%E7%A4%BA%E4%BE%8B%E4%BB%A3%E7%A0%81/%E6%B4%9B%E4%B9%A6%E7%A8%8B%E5%BA%8F/%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE%202022-07-25%20102106.png)
![输入图片说明](%E6%B4%9B%E4%B9%A6%E7%A4%BA%E4%BE%8B%E4%BB%A3%E7%A0%81/%E6%B4%9B%E4%B9%A6%E7%A8%8B%E5%BA%8F/2.png)
![输入图片说明](%E6%B4%9B%E4%B9%A6%E7%A4%BA%E4%BE%8B%E4%BB%A3%E7%A0%81/%E6%B4%9B%E4%B9%A6%E7%A8%8B%E5%BA%8F/%E5%A4%9A%E7%BA%BF%E7%A8%8B.png)
![输入图片说明](%E6%B4%9B%E4%B9%A6%E7%A4%BA%E4%BE%8B%E4%BB%A3%E7%A0%81/%E6%B4%9B%E4%B9%A6%E7%A8%8B%E5%BA%8F/%E6%A0%91%E8%8E%93%E6%B4%BE.png)
### 补充条款
#### 关于商用
在遵顼以下条款的前提下,洛书及其源代码被允许用作商业用途
1. 从本仓库授权开发者手中获得商业使用授权
2. 在您的商用版本中标注商用授权

#### 关于洛书支持库
一般情况下,洛书拓展库不被视为洛书的一部分,无论是否由本仓库成员开发,不用遵循洛书所遵循的开源协议<br>
但如果您希望将其开源<br>
您可以选择将其提交到本仓库，并注明所用开源协议。

特殊的<br>
对于losuvm_host 与 losuvm_comilper 这两个支持库<br>
因其涉及到洛书的解释，编译算法,两者遵守LGPL-3.0 开源协议