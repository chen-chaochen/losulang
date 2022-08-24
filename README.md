[![中文编程](https://gitee.com/Program-in-Chinese/overview/raw/master/%E4%B8%AD%E6%96%87%E7%BC%96%E7%A8%8B.svg)](https://gitee.com/Program-in-Chinese/overview)
<a href='https://gitee.com/chen-chaochen/lpk/stargazers'><img src='https://gitee.com/chen-chaochen/lpk/badge/star.svg?theme=dark' alt='star'></img></a>
<a href='https://gitee.com/chen-chaochen/lpk/members'><img src='https://gitee.com/chen-chaochen/lpk/badge/fork.svg?theme=dark' alt='fork'></img></a><a href='https://gitee.com/chen-chaochen/lpk'><img src='https://gitee.com/chen-chaochen/lpk/widgets/widget_1.svg' alt='Fork me on Gitee'></img></a>
### 洛书编程语言
![输入图片说明](%E6%B4%9B%E4%B9%A6%E7%A4%BA%E4%BE%8B%E4%BB%A3%E7%A0%81/%E6%B4%9B%E4%B9%A6%E7%A8%8B%E5%BA%8F/readme.gif)

#### 简介
洛书·Losu(Language Of Systemed Units)，单位系统化编程语言，是一款开源，轻量，跨平台，易拓展的中文编程语言。

针对现阶段国人编程需求与编程门槛的矛盾，致力于提供一种人人参与，快速构建的编程方式。

得益于完全由C++11编写的核心代码，洛书可以在多种平台上直接运行，且可以方便的移植到众多的支持POSIX/GNU标准的平台上，覆盖了从开发板到卡片机到个人计算机等多种设备，具有极大的应用弹性。

洛书支持的 [ **CPU** ](https://gitee.com/chen-chaochen/lpk/blob/doc/platform/CPU_support.md) [ **OS** ](https://gitee.com/chen-chaochen/lpk/blob/doc/platform/OS_support.md) [ **开发板** ](https://gitee.com/chen-chaochen/lpk/blob/doc/platform/board_support.md) 概览

洛书开发 QQ交流群 805995065 讨论，咨询，技术分享欢迎加群<br>
抖音 demo 分享帐号 洛书编程小哥<br>
Demo源码下载见expand分支<br>
初始设计文档见wiki<br>
滚动技术文档见doc分支[[链接]](https://gitee.com/chen-chaochen/lpk/tree/doc/)<br>

#### 特点
+ 开源开放
    - C++实现，源码，架构及工作原理完全开放。
    - 编译生成可阅读的输出文件，自由查看
+ 简单高效    
    + 语法简捷，中文代码，简单易上手，让编程走进千家万户。
    + "胶水语言"，支持调用C/C++/Python等语言编写的支持库,可与现有编程语言进行交互。
+ 跨平台，多用途
    + 从桌面系统到嵌入式设备，物联网控制平台，洛书都可以实现运行并发作用。
    + 洛书支持的 [ **CPU** ](https://gitee.com/chen-chaochen/lpk/blob/doc/platform/CPU_support.md) [ **OS** ](https://gitee.com/chen-chaochen/lpk/blob/doc/platform/OS_support.md) [ **开发板** ](https://gitee.com/chen-chaochen/lpk/blob/doc/platform/board_support.md) 概览
+ 语法糖架构    
    + 所有的编译器与前端都是在 洛书指令语言 基础上进行加糖
    + 通过加糖，可以构建不同语法的洛书语言，必要时还可构建图形化编程界面

#### 常见质疑
如果您直接将中文编程视作笑话，那就没必要向下看了
阅读此文档以反馈常见质疑 [[链接]](https://gitee.com/chen-chaochen/lpk/blob/doc/%E6%B4%9B%E4%B9%A6%201.0%20LTS%20%E6%8A%80%E6%9C%AF%E6%96%87%E6%A1%A3/%E7%AE%80%E4%BB%8B%E6%96%87%E6%A1%A3/%E6%B4%9B%E4%B9%A6%E7%9A%84%E8%AE%BE%E8%AE%A1%E6%83%B3%E6%B3%95.md)
1. 洛书是套壳吗？
+ 不是，至于有人质疑洛书套壳C++，洛书和python一样，是通过调用C/C++库来拓展功能的。胶水语言与套壳语言是不一样的
2. 洛书代码很丑吗？
- 洛书原版的代码是C风格的，长这样
```
+方法 开始()
{
    程序.输出("你好，洛书！")
}
```
- 有朋友开发了一个python风格的前端，长这样

```
#方法 开始()
    程序.输出("你好，洛书！")
```

### 安装&更新
洛书采用类似镜像源的安装方式，通过一行命令，即从源码开始生成最新的版本

在一个空的文件夹内打开终端，输入以下命令(安装有wget与g++编译器)，静待安装结束就OK了
+ windows
```
wget https://gitee.com/chen-chaochen/lpk/raw/release/update/install.bat&install.bat
```
+ linux
```
wget https://gitee.com/chen-chaochen/lpk/raw/release/update/install.sh&&sudo bash ./install.sh&&sudo rm ./install.sh

master分支下的源码仅作预览用途，各发行版源码见release分支
```
### 加入洛书
1. 加入仓库,参与洛书标准的制定及LPK组件的开发
2. 在expand分支提交pr，参与洛书拓展库的开发
3. fork本仓库
4. 加入讨论群，共同进步
5. 使用洛书开发项目/学生开发毕设也OK

### 最新的LTS版本
####  **洛书1.0 LTS** 
关于 **洛书1.0 LTS** 与滚动发行版的区别
可以参照 [ **[文档链接]** ](https://gitee.com/chen-chaochen/lpk/blob/doc/%E6%B4%9B%E4%B9%A6%201.0%20LTS%20%E6%8A%80%E6%9C%AF%E6%96%87%E6%A1%A3/LTS%E4%B8%8E%E6%BB%9A%E5%8A%A8%E7%89%88%E6%9C%AC%E7%9A%84%E4%B8%8D%E5%90%8C.md)<br>
关于 **洛书1.0 LTS** 的介绍，安装。详见发行版 [**[洛书1.0 LTS]**
](https://gitee.com/chen-chaochen/lpk/releases/tag/1.0) <br>
关于 **洛书1.0 LTS** 的技术文档，可参照 [ **[文档链接]** ](https://gitee.com/chen-chaochen/lpk/tree/doc/%E6%B4%9B%E4%B9%A6%201.0%20LTS%20%E6%8A%80%E6%9C%AF%E6%96%87%E6%A1%A3) 
#### 第三方贡献
#####  1. **[河图编译器](https://gitee.com/chen-chaochen/lpk/tree/expand/河图编译器)**
+ 简介 一个采用类型python语法(强制缩进)的洛书衍生版本
+ 示例代码(你好世界.hetu)

```
#加载 开始
#导入 洛书/标准流
#标准流 标准流
#方法 开始()
    标准流.输出("你好，河图！\n")
    /*
        这是河图的多行注释
        也是通过缩进来控制
//这是单行注释
```


### Demo
#### [1. 物联网/嵌入式](https://gitee.com/chen-chaochen/lpk/tree/doc/%E5%B5%8C%E5%85%A5%E5%BC%8F)

[[洛书物联网架构]](https://gitee.com/chen-chaochen/lpk/blob/expand/%E7%89%A9%E8%81%94%E7%BD%91/readme.md)

[[联网报警器]](https://www.douyin.com/user/MS4wLjABAAAAbwjbvNpvRPNnlWf2iHkGvg_dqhVuMdLz4-csIo8ubS0?modal_id=7133415852505976095)<br>
[[网控小灯]](https://v.douyin.com/jNdYkcY)<br>
[[交通灯]](https://v.douyin.com//jyxDJPy)

```
#加载 开始
#导入 洛书/标准流
#引用 交通灯
/*
    一个自动的交通灯控制程序
    红灯 2s
    绿灯 2s
    黄灯 1s 闪烁5次
#标准流 程序
#交通灯 交通灯
#方法 开始()
    交通灯.配置("16","20","21")
    #循环("5")
        交通灯.红灯.点亮()
        程序.等待("2000")
        交通灯.红灯.熄灭()
        交通灯.黄灯.闪烁()
        交通灯.绿灯.点亮()
        程序.等待("2000")
        交通灯.绿灯.熄灭()

    
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

### 示例代码
demo 请见 [[链接]](https://gitee.com/chen-chaochen/lpk/tree/expand/Demo)

入门示例请见 [[链接]](https://gitee.com/chen-chaochen/lpk/tree/master/%E6%B4%9B%E4%B9%A6%E7%A4%BA%E4%BE%8B%E4%BB%A3%E7%A0%81)

![输入图片说明](%E6%B4%9B%E4%B9%A6%E7%A4%BA%E4%BE%8B%E4%BB%A3%E7%A0%81/%E6%B4%9B%E4%B9%A6%E7%A8%8B%E5%BA%8F/3.png)
![输入图片说明](%E6%B4%9B%E4%B9%A6%E7%A4%BA%E4%BE%8B%E4%BB%A3%E7%A0%81/%E6%B4%9B%E4%B9%A6%E7%A8%8B%E5%BA%8F/%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE%202022-07-25%20102106.png)
![输入图片说明](%E6%B4%9B%E4%B9%A6%E7%A4%BA%E4%BE%8B%E4%BB%A3%E7%A0%81/%E6%B4%9B%E4%B9%A6%E7%A8%8B%E5%BA%8F/2.png)
![输入图片说明](%E6%B4%9B%E4%B9%A6%E7%A4%BA%E4%BE%8B%E4%BB%A3%E7%A0%81/%E6%B4%9B%E4%B9%A6%E7%A8%8B%E5%BA%8F/%E5%A4%9A%E7%BA%BF%E7%A8%8B.png)
![输入图片说明](%E6%B4%9B%E4%B9%A6%E7%A4%BA%E4%BE%8B%E4%BB%A3%E7%A0%81/%E6%B4%9B%E4%B9%A6%E7%A8%8B%E5%BA%8F/%E6%A0%91%E8%8E%93%E6%B4%BE.png)


