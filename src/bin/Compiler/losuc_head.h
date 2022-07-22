#define LS_PLAT 1
//1 == Windows 2 == Linux 
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#if (LS_PLAT == 1)
string LS_INC = "C:/losu/inc/";
#endif
#if (LS_PLAT == 2)
string LS_INC = "/usr/local/losu/inc/";
#endif
