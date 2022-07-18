#include "losu_head.h"
#include "pub_func.h"
#include "ls_func.h"
using namespace std;
extern "C"{
const char* ls_host(const char* _file)
{
	ls_vm vim; 
	vim.hostfile(mainfile,getcsip());
	pthread_exit(NULL);
	return "";
}
}

