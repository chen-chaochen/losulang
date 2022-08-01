### markdown文件转html小工具
基于C++开发，封装了洛书的调用接口。<br>
可以将markdown格式转换为html格式；<br>
支持用户拓展自己的md标签
#### 使用方法

```
g++ -shared -fPIC -o losuvm_mark.lsd losuvm_mark.cpp
losuc MD转换器
```
将生成的文件复制到LS_ROOT/lvm,LS_ROOT/inc目录下

_在后期版本中，这个工具会被包含在基本类中_
 

chen-chaochen
2022/8/1