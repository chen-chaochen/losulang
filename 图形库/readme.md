### 关于洛书图形库的设想
#### 阶段一
 **LCG**(Losu Console GUI)
##### 要求(最低)
+ 跨平台    在x86架构下至少兼容Windows,linux两种平台
+ 简易      类似Tudo C或Basic，通过简单的代码绘制图形
+ 支持标准控制台调色板

#### 阶段二
 **LGI**(Losu GUI) 
##### 要求
+ 跨平台    支持x86，Risv等多种处理器架构，支持Win,Linux,Unix等支持视窗操作系统
+ 面向UI驱动 可以使用系统的窗口类API  

#### 阶段三
 **LUI**(Losu UI)
+ 跨平台    支持x86，Risv等多种处理器架构，支持Win,Linux,Unix等支持视窗操作系统
+ 独立的UI生成理论    像html一样，通过封装后简单的洛书代码，快速构建UI界面