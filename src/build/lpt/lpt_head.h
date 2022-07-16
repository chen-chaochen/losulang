#define LS_PLAT 1
//1 = WINDOWS 2 = LINUX
#include <iostream>
#include <string>
#include <unistd.h>
#include <fstream>
#include <vector>
using namespace std;

#if (LS_PLAT == 1)
    string LS_ROOT = "C:/losu0.1/";
#endif
#if (LS_PLAT == 2)
    string LS_ROOT = "/usr/local/lib/losu0.1/";
#endif

int main_argc;
const char** main_argv;
int max_path = 260000;

string curdir()
{
	string a;
	const char* _a;
	char b[max_path];
 	getcwd(b,max_path);
	_a = b;
	a = _a;
	a = a + "/";
	return a;	
}
string _com_mod()
{
	if (main_argc > 1)
	{
		return main_argv[1];
	}
	return "";
}
string _com_pac()
{
    if (main_argc > 1)
	{
		return main_argv[2];
	}
	return "";
}
void _lpt_install(string _pac)
{
	string _cur_inc = curdir() + _pac + "/inc/*.lsc";
	string _path_inc = LS_ROOT + "inc/";
	string _cur_lvm = curdir() + _pac + "/lvm/*.lsd";
	string _path_lvm = LS_ROOT + "lvm/";
	string _cur_lsi = curdir() + _pac + "/inc/*.lsd";
	string _path_lsi = LS_ROOT + "lsi/";
	#if (LS_PLAT == 1)
		string _com_inc = "copy " + _cur_inc + "  " + _path_inc;
		string _com_lvm = "copy " + _cur_lvm + "  " + _path_lvm;
		string _com_lsi = "copy " + _cur_lsi + "  " + _path_lsi;
	#endif
	#if (LS_PLAT == 2)
		string _com_inc = "sudo cp " + _cur_inc + "  " + _path_inc;
		string _com_lvm = "sudo cp " + _cur_lvm + "  " + _path_lvm;
		string _com_lsi = "sudo cp " + _cur_lsi + "  " + _path_lsi;
	#endif
	const char* com_inc = _com_inc.c_str();
	const char* com_lsi = _com_lsi.c_str();
	const char* com_lvm = _com_lvm.c_str();
	system(com_inc);
	system(com_lvm);
	system(com_lsi);
}

void _lpt_scan(string _pac)
{
	int conf;
	conf = 0;
	string tmp,_lvm,_lsi,_lei;
	vector<string> lvm;
	vector<string> lsi;
	vector<string> lei;
	lvm.push_back("");
	lsi.push_back("");
	lei.push_back("");
	ifstream _fin;
	_fin.open(_pac);
	if (_fin.is_open() == 0)
	{
		cout<< "找不到指定文件"<<endl;
		return;
	}
	do
	{
		_fin>> tmp;
		if (tmp == "lvm")
		{
			_fin>> _lvm;
			for (int i = 0; i < lvm.size(); i++)
			{
				if (lvm[i] == _lvm)
				{
					conf = 1;
					break;	
				}
			}
			if (conf == 0)
			{
				lvm.push_back("losuvm_" + _lvm + ".lsd");
			}
			conf = 0;
		}
		if (tmp == "lsi")
		{
			_fin>> _lsi;
			for (int i = 0; i < lsi.size(); i++)
			{
				if (lsi[i] == _lsi)
				{
					conf = 1;
					break;	
				}
			}
			if (conf == 0)
			{
				lsi.push_back(_lsi + ".lsd");
			}
			conf = 0;
		}
		if (tmp == "lei")
		{
			_fin>> _lei;
			for (int i = 0; i < lei.size(); i++)
			{
				if (lei[i] == _lei)
				{
					conf = 1;
					break;	
				}
			}
			if (conf == 0)
			{
				lei.push_back(_lei);
			}
			conf = 0;
		}
		if (_fin.eof() == 1)
		{
			break;
		}
	} while (1);
	cout<< "洛书程序:";
	cout<< _pac;
	cout<< "所需支持库有："<<endl;

	cout<< "所需LVM:"<<endl;
	for (long i = 0; i < lvm.size(); i++)
	{
		cout<< "	";
		cout<< lvm[i]<<endl;
	}
	
	cout<< "所需LSI:"<<endl;
	for (long i = 0; i < lsi.size(); i++)
	{
		cout<< "	";
		cout<< lsi[i]<<endl;
	}
	
	cout<< "所需LEI:"<<endl;
	for (long i = 0; i < lei.size(); i++)
	{
		cout<< "	";
		cout<< lei[i]<<endl;
	}
	
}

