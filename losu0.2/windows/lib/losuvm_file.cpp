#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<fstream> 
using namespace std;
fstream _losu_file_sys[10001];

extern "C"
{
	string mid(string a,long start_pos,long len_pos)
	{
    	if (start_pos > a.length())
    	{
        	return "";
    	}
		return a.substr(start_pos - 1,len_pos);
	}
	string replace_all(string src,string old_value,string new_value) 
	{
    	long i;
		string rep;
		i = 1;
		do
		{
			if (mid(src,i,old_value.length()) == old_value )
			{
				i = i + old_value.length() -1;
				rep = rep + new_value;
			}
			else
			{
				rep = rep + mid(src,i,1);
			}
			i++;
			if (i > src.length())
			{
				rep = rep + mid(src,i,1);
				break;
			}
		} while (1 < 2);
		return rep;
	}
	string trmate(string a)
	{
		string b;
		string b1;
		string c;
		string d;
		b = "\n";
		d = "\\n";
		c = replace_all(a ,d, b);
		return c;
	}

	const char* losuvm_file_open(const char* filename,const char* filenum,const char* mod)
	{
		if (atoi(filenum) > 10000 || atoi(filenum) < 0)
		{
			throw "洛书运行时错误:	文件编号溢出";
		}
		if (_losu_file_sys[atoi(filenum)].is_open() == 1)
		{
			throw "洛书运行时错误:	重复指定的编号";
		}
		if (atoi(mod) == -1)
		{
			_losu_file_sys[atoi(filenum)].open(filename,ios::in);
		}
		if (atoi(mod) == 0)
		{
			_losu_file_sys[atoi(filenum)].open(filename,ios::out);
		}
		if (atoi(mod) == 1)
		{
			_losu_file_sys[atoi(filenum)].open(filename,ios::app);
		}
		return "1";
	}
	const char* losuvm_file_print(const char* filenum,const char* str)
	{
		if (atoi(filenum) > 10000 || atoi(filenum) < 0)
		{
			throw "洛书运行时错误:	文件编号溢出";
		}
		if (_losu_file_sys[atoi(filenum)].is_open() == 0)
		{
			throw "洛书运行时错误:	未指定的编号";
		}
		_losu_file_sys[atoi(filenum)]<<str;
		return "1";
	}
	const char* losuvm_file_input(const char* filenum)
	{
		string _tmp;
		if (atoi(filenum) > 10000 || atoi(filenum) < 0)
		{
			throw "洛书运行时错误:	文件编号溢出";
		}
		if (_losu_file_sys[atoi(filenum)].is_open() == 0)
		{
			throw "洛书运行时错误:	未指定的编号";
		}
		_losu_file_sys[atoi(filenum)]>>_tmp;
		return _tmp.c_str();
	}
	const char* losuvm_file_lineinput(const char* filenum)
	{
		string _tmp;
		if (atoi(filenum) > 10000 || atoi(filenum) < 0)
		{
			throw "洛书运行时错误:	文件编号溢出";
		}
		if (_losu_file_sys[atoi(filenum)].is_open() == 0)
		{
			throw "洛书运行时错误:	未指定的编号";
		}
		getline(_losu_file_sys[atoi(filenum)],_tmp);
		return _tmp.c_str();
	}
	const char* losuvm_file_eof(const char* filenum)
	{
		if (atoi(filenum) > 10000 || atoi(filenum) < 0)
		{
			throw "洛书运行时错误:	文件编号溢出";
		}
		if (_losu_file_sys[atoi(filenum)].is_open() == 0)
		{
			throw "洛书运行时错误:	未指定的编号";
		}
		return to_string(_losu_file_sys[atoi(filenum)].eof()).c_str();
	}
	const char* losuvm_file_close(const char* filenum)
	{
		if (atoi(filenum) > 10000 || atoi(filenum) < 0)
		{
			throw "洛书运行时错误:	文件编号溢出";
		}
		_losu_file_sys[atoi(filenum)].close();
		return "1";
	}
	const char* losuvm_file_freefile()
	{
		string _tmp;
		for (int i = 0; i < 10000; i++)
		{
			if (_losu_file_sys[i].is_open() == 0)
			{
				_tmp = to_string(i);
				break;
			}
		}
		return _tmp.c_str();
	}
}
