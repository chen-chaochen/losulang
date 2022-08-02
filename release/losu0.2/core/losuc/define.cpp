#define LS_PLAT 0
//1 == Windows 2 == Linux
#if (LS_PLAT == 1)
string LS_INC = "C:/losu/inc/";
#endif
#if (LS_PLAT == 2)
string LS_INC = "/usr/local/lib/losu/inc/";
#endif
