### 洛书的服务器模块
已经集成在 0.2.4+ Linux版本的基本类中<br>
用于快速搭建个人简易网络服务器
#### 用法
1. 安装/升级 洛书

```
wget https://gitee.com/chen-chaochen/lpk/raw/release/update/install.sh&&sudo bash ./install.sh
```
2. 找一个工作目录，创建以下文件

```
//文件名 index.html
//主页


<html>
    <head>
        <meta charset = "utf-8">
    </head>
    <body>
     洛书服务器！
     <hr>
     <p>你好，洛书</p><br>
     <a href = "https://gitee.com/chen-chaochen/lpk"><p>洛书首页</p></a>
    </body>
</html>
```

```
//文件名 服务.losu
//UTF-8 LF换行


+加载 开始
+导入 洛书·服务器
+实例 服务器 服务器
+导入 洛书·标准流
+实例 标准流 标准流
+方法 开始()
{
    服务器·设置文件(".html","text/html")
    服务器·设置文件(".htm","text/html")
    服务器·设置文件(".css","text/css")
    服务器·设置文件(".js","text/javascript")
    服务器·设置文件(".gif","image/gif")
    服务器·设置文件(".png","image/png")
    服务器·设置文件(".jpg","image/jpg")
    标准流·运行("ip addr show")
    标准流·输出("服务器已运行于 8080 端口\n")
    服务器·启动("8080")
    //访问你的本机IP 加端口号8080查看效果
}

```
3.编译执行

```
losuc 服务
losu 服务.lsc
```
4. 访问一下吧

#### 注意事项 
+ 洛书服务器的cgi执行目录为./cgi-bin
+ 洛书服务器模块未考虑网络攻防，请谨慎用于敏感项目