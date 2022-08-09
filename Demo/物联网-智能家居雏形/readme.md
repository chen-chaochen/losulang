### 案例说明
有关洛书物联网的完整设计文档 见 https://gitee.com/chen-chaochen/lpk/blob/expand/物联网

本例中 
+ 树莓派4b 模拟 洛书物联网服务器
+ LED灯泡  模拟 物联网设备(客厅顶灯)
+ 跳线     模拟 信息传输通道
+ 洛书APP  模拟 控制软件

向您展示洛书用于物联网、嵌入式领域的可行性

### 运行视频
见本目录

### 源代码
+ 服务器

```
//文件 ./服务器.losu
+加载 开始
+导入 洛书·标准流
+实例 标准流 标准流
+导入 洛书·服务器
+实例 服务器 服务器
+方法 开始()
{
    服务器·设置文件(".html","text/html")
    标准流·运行("ip addr show")
    标准流·输出("服务器已运行于 8888 端口\n")
    服务器·启动("8888")
}
```
+支持类

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


+ CGI程序

```
//文件 ./cgi-bin/main.losu
+加载 开始
+导入 洛书·标准流
+实例 标准流 标准流
+方法 开始()
{
    标准流·输出("Content-type:text/html\r\n\r\n")
    标准流·输出("<!DOCTYPE html><html>")
    标准流·输出("<head><meta charset = utf8></head>")
    标准流·输出("<body><center>")
    标准流·输出("<h1><p style = color:green>洛书·物联网</p></h1>")
    标准流·输出("<h2><a href =\'./light_on.lsc\'><p style = color:drakgray>[打开顶灯]</p></a>")
    标准流·输出("<a href =\'./light_off.lsc\'><p style = color:drakgray>[关闭顶灯]</p></a></h2>")
    标准流·输出("</center><body></html>")
}
```

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

    //输出网页
    标准流·输出("Content-type:text/html\r\n\r\n")
    标准流·输出("<!DOCTYPE html><html>")
    标准流·输出("<head><meta charset = utf8></head>")
    标准流·输出("<body>")
    标准流·输出("<center><h1><p style = color:green>洛书·物联网</p></h1><h2><p style = color:green>[顶灯已打开]</p>")
    标准流·输出("<a href = \'./light_off.lsc\'><p style = color:darkgray>[关闭顶灯]</p></a></h2></center>")
    标准流·输出("<body></html>")
}
```

```
//文件 ./cgi-bin/light_off.losu
+加载 开始
+导入 洛书·标准流
+实例 标准流 标准流
+引用 洛书的家
+实例 洛书的家 洛书的家
+方法 开始()
{
    洛书的家·客厅顶灯·熄灭()

    //输出网页
    标准流·输出("Content-type:text/html\r\n\r\n")
    标准流·输出("<!DOCTYPE html><html>")
    标准流·输出("<head><meta charset = utf8></head>")
    标准流·输出("<body>")
    标准流·输出("<center><h1><p style = color:green>洛书·物联网</p></h1> <a href =\'./light_on.lsc\'><h2><p style = color:drakgray>[打开顶灯]</p></a></h2>")
    标准流·输出("<h2><p style = color:green>[顶灯已关闭]</p></h2></center>")
    标准流·输出("<body></html>")
}
```

