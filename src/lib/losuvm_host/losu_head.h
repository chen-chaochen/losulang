#define LS_PLAT 1
//1 = windows 2 = linux
using namespace std;

#include<stdio.h>
#include<algorithm>
#include<iostream>
#include <string>
#include<fstream> 
#include<vector>
#include <unistd.h>
#include <string.h>
#include<stdlib.h>
#include<thread>
#include<pthread.h>
#include<cstdio>
#include<sstream>



//windows
#include<windows.h>
string LS_ROOT = "C:/Losu/";
string LS_LIB_PATH = "C:/Losu/lib/";
string LS_LSI_PATH = "C:/Losu/lsi/";
string LS_VM_PATH  = "C:/Losu/lvm/";
//

/* linux
#include<dlfcn.h>
string LS_ROOT = "/usr/local/lib/losu/";
string LS_LIB_PATH = "/usr/local/lib/Losu/lib/";
string LS_LSI_PATH = "/usr/local/lib/Losu/lsi/";
string LS_VM_PATH  = "/usr/local/lib/Losu/lvm/";
*/

string mainfile;
const char* _mainflie;

