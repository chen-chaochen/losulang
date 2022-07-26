GPL-3.0
以一个小型的井字棋游戏为例
展示一下洛书与C/C++的交互能力

使用了cls依赖，linux请改为clear

编译方法
1.编译  chessgame.cpp 为 chessgame.lsd
2.编译 井字棋.losu
3.编译 井字棋游戏.losu
3.运行 井字棋游戏lsc

快速命令
g++ -o chessgame.lsd chessgame.cpp
losuc 井字棋
losuc 井字棋游戏
losu 井字棋游戏