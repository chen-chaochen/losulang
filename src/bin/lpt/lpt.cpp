#include "lpt_head.h"
using namespace std;
int main(int argc,const char** argv)
{
	main_argc = argc;
	main_argv = argv;
	if (_com_mod() == "-v" || _com_mod() == "")
    {
        cout<< "洛书包管理器"<<endl;
        cout<< "-s   分析洛书程序的依赖库"<<endl;       
		return 0; 
    }    
	if (_com_mod() == "-s")
    {
    	_lpt_scan(_com_pac());
    	return 0;
	}
	cout<< "洛书包管理器"<<endl;
	return 0;
}
