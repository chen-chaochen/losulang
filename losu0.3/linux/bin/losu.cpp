/*
LPK0.3
Losu Program-language Kits 0.3
Powered by chen-chaochen
https://gitee.com/chen-chaochen/lpk
License GPL-3.0 
*/



//请按要求完成源码配置


#define LS_PLAT 2
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



/*  Windows下编译时取消以下注释
#include<windows.h>
string LS_ROOT = "C:/Losu/";
string LS_LIB_PATH = "C:/Losu/lib/";
string LS_LSI_PATH = "C:/Losu/lsi/";
string LS_VM_PATH  = "C:/Losu/lvm/";
*/

// linux下编译时取消以下注释
#include<dlfcn.h>
string LS_ROOT = "/usr/local/lib/losu/";
string LS_LIB_PATH = "/usr/local/lib/losu/lib/";
string LS_LSI_PATH = "/usr/local/lib/losu/lsi/";
string LS_VM_PATH  = "/usr/local/lib/losu/lvm/";
//

//至此，全部配置已完成，可以编译














/*
下面是整合后的解释器源代码
*/


string mainfile;
const char* _mainflie;

//Declare Val

int main_argc;
const char** main_argv;
int max_path = 32000;


//Declare Function
string replace_all(string src, string old_value,string new_value);
string mid(string a,long b,long c);
string trmate(string a);
int val_int(string a);
long double val(string a);
int ls_asc(char a);
string ls_endl();

//Define Function
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

string command()
{
	if (main_argc > 1)
	{
		return main_argv[1];
	}
	return "";
}

string trmate(string a)
{
    return a;
}
long double val(string a)
{
	return atof(a.c_str());
}
int val_int(string a)
{
	return atoi(a.c_str());
}
string mid(string a,long start_pos,long len_pos)
{
    if (start_pos > a.length())
    {
        return "";
    }
	return a.substr(start_pos - 1,len_pos);
}
string str_sign_34()
{
	char a = char(34);
	string b;
	b = a;
	return b;
}
string str_sign_92()
{
	char a = char(92);
	string b;
    b = a;
	return b;
}
string ls_endl()
{
    //不同系统CRLF不一样
    //linux & windows 用 LF即可
    //MAC os 用 CR
    char a = char(10);
    string b;
    b = a;
    /* windows
    a = char(13);
    b = b + a;
    */
   /* mac os
    a = char(13);
    b = a;
   */
    return b;
}
void ls_sleep(long ms)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}
int ls_asc(char a)
{
    return (int)(a);
}
string ls_cr()
{
    //不同系统CRLF不一样
    //linux & windows 用 LF即可
    //MAC os 用 CR
    char a = char(13);
    string b;
    b = a;
    /* windows
    a = char(13);
    b = b + a;
    */
   /* mac os
    a = char(13);
    b = a;
   */
    return b;
}
string tostring(double a)
{
    string _tmp = to_string(a);
    string _int_sub,_double_sub;
    int _pos,_pos_e;
    int conf =0;
	for (int i = 1; i <= _tmp.length(); i++)
    {
        if (mid(_tmp,i,1) == ".")
        {
            conf = 1;
            _pos = i;
            break;
        }
    }
    _int_sub = mid(_tmp,1,_pos);
    if (conf == 0)
    {
        return _int_sub;
    }
    for (int i = _tmp.length(); i > _pos; i--)
    {
        if (mid(_tmp,i,1) != "0")
        {
            _pos_e = i;
            break;
        }
    }
    _double_sub = mid(_tmp,_pos + 1,_pos_e - _pos);
    if (atoi(_double_sub.c_str()) == 0)
    {
        return to_string(atoi(_tmp.c_str()));
    }
    return _int_sub + _double_sub.c_str();
}



vector<string> vaname; 
vector<string> vavalue; 
vector<string> arrayname;
vector< vector<string> > array_mem;
extern "C"{
void cthread(string _thname);
void create_new_th(string _th_name);
void array_start();
void array_new(string a);
void array_set(string a,long b,string c);
string array_get(string a,long b);
void array_clear(string a);
string getcsip();


void array_start()
{
    arrayname.push_back("");
    array_mem.push_back( vector<string>() );
    array_mem[0].push_back("");
}
void array_new(string a)
{
    for (long i = 0; i < arrayname.size(); i++)
    {
        if (arrayname[i] == "")
        {
            arrayname[i] = a;
            array_mem[i].clear();
            array_mem[i].push_back("");
            return;
        }   
    }
	arrayname.push_back(a);
	array_mem.push_back( vector<string>() );
	array_mem[array_mem.size() - 1].push_back("");
}
void array_set(string a,long b,string c)
{
	for (long i = 0; i < arrayname.size(); i++)
	{
		if (arrayname[i] == a)
		{
			if (b < array_mem[i].size())
			{
				array_mem[i][b] = c;
                return;
			}
			else
			{
				do
				{
					array_mem[i].push_back("");
					if (array_mem[i].size() > b)
					{
						array_mem[i][b] = c;
						return;
					}
				} while (1);
			}
		}	
	}
}
string array_get(string a,long b)
{
	for (long i = 0; i < arrayname.size(); i++)
	{
		if (arrayname[i] == a)
		{
            if (b < array_mem[i].size())
            {
                return array_mem[i] [b];   
            }
            return "";
		}
	}
    return "";
}
void array_clear(string a)
{
    for (long i = 0; i < arrayname.size(); i++)
    {
        if (arrayname[i] == a)
        {
            arrayname[i] = "";
            return;
        }
    }
}

class ls_vm
{
    public:
        int conf = 0;
        string csip;
        const char* _csip;
        ifstream _fin;
        vector<string> stack;
        int _stack_top;
        void start();
        void clear_st();
        void push(string a);
        void pop();
        string top();
        void add(string vname);
        void mov(string vname);
        void clear(string vname);
        void get_csip();
        string lvm(const char* _vm,const char* _func);
        string lsi(const char* _vm);
        string lei(const char* _vm,const char* _func);
        void hostfile(string _file,string _sign);
        void goto_ip(const char* _ip);
        const char* _nextip();
        string api(string apiname);
};

string ls_vm::api(string apiname)
{
    string tmp;
	long foo;
	if (apiname == "=")
	{
		return top();
	}
	if (apiname == "+")
	{
		return tostring(val(stack[2]) + val(top()));
	}
	if (apiname == "-")
	{
		return tostring(val(stack[2]) - val(top()));
	}
	if (apiname == "*")
	{
		return tostring(val(stack[2]) * val(top()));
	}
	if (apiname == "/")
	{
		return tostring(val(stack[2]) / val(top()));
	}
	if (apiname == "&")
	{
		return stack[2] + top();
	}
	if (apiname == str_sign_92()) //sign_92指 "\" 符号
	{
		return tostring(val_int(stack[2]) % val_int(top()));
	}
	if (apiname == "|")
	{
		return tostring((val_int(stack[2]) - (val_int(stack[2]) % val_int(top()))) / val_int(top()));
	}
    if (apiname == "array.newarry")
	{
		array_new(top());
		return "";
	}
    if (apiname == "array.clear")
	{
		array_clear(top());
		return "";
	}
	if (apiname == "array.getarry")
	{
		return array_get(stack[2],val_int(top()));
	}
	if (apiname == "array.setarry")
	{
		array_set(stack[3],val_int(stack[2]),top());
		return "";
	}
    return "";
}
void ls_vm::clear_st()
{
    for (int i = 1; i < 17; i++)
    {
        stack[i] = "";
    }
    _stack_top = 0;
}
void ls_vm::start()
{
	for(int i = 0;i< 17;i++)
	{
		stack.push_back("");
	}
    _stack_top = 0;
}
void ls_vm::push(string a)
{
    stack.pop_back();
    stack.emplace(stack.begin() + 1,a);
}
void ls_vm::pop()
{
	if (_stack_top > 0 )
    {
        stack[1] = "";
        _stack_top--;
    }
}
string ls_vm::top()
{
    const char* _top;
    _top = stack[1].c_str();
    return _top;
}
void ls_vm::add(string vname)
{
	for (long i = 0; i < vaname.size(); i++)
	{
		if (vaname[i] == vname)
		{
			push(vavalue[i]);
            return;
		}
	}
    push("");
}
void ls_vm::mov(string vname)
{
	for (long i = 0; i < vaname.size(); i++)
	{
		if (vaname[i] == vname)
		{
			vaname[i] = vname;
			vavalue[i] = top();
			return;
		}
	}
	vaname.push_back(vname);
	vavalue.push_back(top());
	
}
void ls_vm::clear(string vname)
{
    for (long i = 0; i < vaname.size(); i++)
	{
		if (vaname[i] == vname)
		{
            //上一代的清除算法
			//vaname[i] = "";
            //vavalue[i] = "";
            vaname.erase(vaname.begin() + i);
            vavalue.erase(vavalue.begin() + i);
            return;
		}
	}
}
string ls_vm::lvm(const char* _vm,const char* _func)
{
    typedef const char* (*LOSU_API_VOID)( const char* _s1,const char* _s2,const char* _s3,const char* _s4,const char* _s5,const char* _s6,const char* _s7,const char* _s8,const char* _s9,const char* _s10,const char* _s11,const char* _s12,const char* _s13,const char* _s14,const char* _s15,const char* _s16);
    vector<LOSU_API_VOID> _fun;
    string _rt;
    string  _str_dll = LS_VM_PATH;
	_str_dll = _str_dll + "losuvm_" + _vm + ".lsd";
    const char* _dll = _str_dll.c_str();
    #if (LS_PLAT == 1)
        HMODULE _ptr_dll = LoadLibrary(_dll);
        if (_ptr_dll == NULL)
        {
            cout<< "洛书运行时错误: 无法调用函数";
            cout<< _func<<endl;
            return "";
        }
		_fun.push_back( (LOSU_API_VOID)GetProcAddress(_ptr_dll,_func));
		_rt = _fun[0]( top().c_str(), stack[2].c_str(), stack[3].c_str(), stack[4].c_str(), stack[5].c_str(), stack[6].c_str(), stack[7].c_str(), stack[8].c_str(), stack[9].c_str(), stack[10].c_str(), stack[11].c_str(), stack[12].c_str(), stack[13].c_str(), stack[14].c_str(), stack[15].c_str(), stack[16].c_str());
		_fun.pop_back();
		//FreeLibrary(_ptr_dll);
    #endif
    #if (LS_PLAT == 2)
        void* _ptr_dll = dlopen(_dll,RTLD_NOW);
        if (_ptr_dll == NULL)
        {
            cout<< "洛书运行时错误: 无法调用函数";
            cout<< _func<<endl;
            return "";
        }
		_fun.push_back( (LOSU_API_VOID)dlsym(_ptr_dll,_func));
		_rt = _fun[0]( top().c_str(), stack[2].c_str(), stack[3].c_str(), stack[4].c_str(), stack[5].c_str(), stack[6].c_str(), stack[7].c_str(), stack[8].c_str(), stack[9].c_str(), stack[10].c_str(), stack[11].c_str(), stack[12].c_str(), stack[13].c_str(), stack[14].c_str(), stack[15].c_str(), stack[16].c_str());
		_fun.pop_back();
		//dlclose(_ptr_dll);
    #endif
    return _rt;
}
string ls_vm::lei(const char* _vm,const char* _func)
{
    typedef const char* (*LOSU_API_VOID)( const char* _s1,const char* _s2,const char* _s3,const char* _s4,const char* _s5,const char* _s6,const char* _s7,const char* _s8,const char* _s9,const char* _s10,const char* _s11,const char* _s12,const char* _s13,const char* _s14,const char* _s15,const char* _s16);
    vector<LOSU_API_VOID> _fun;
    string _rt;
    string  _str_dll = _vm;
    const char* _dll = _str_dll.c_str();
    #if (LS_PLAT == 1)
        HMODULE _ptr_dll = LoadLibrary(_dll);
        if (_ptr_dll == NULL)
        {
            cout<< "洛书运行时错误: 无法调用函数";
            cout<< _func<<endl;
            return "";
        }
		_fun.push_back( (LOSU_API_VOID)GetProcAddress(_ptr_dll,_func));
		_rt = _fun[0]( top().c_str(), stack[2].c_str(), stack[3].c_str(), stack[4].c_str(), stack[5].c_str(), stack[6].c_str(), stack[7].c_str(), stack[8].c_str(), stack[9].c_str(), stack[10].c_str(), stack[11].c_str(), stack[12].c_str(), stack[13].c_str(), stack[14].c_str(), stack[15].c_str(), stack[16].c_str());
        _fun.pop_back();
		//FreeLibrary(_ptr_dll);
    #endif
    #if (LS_PLAT == 2)
        void* _ptr_dll = dlopen(_dll,RTLD_NOW);
        if (_ptr_dll == NULL)
        {
            cout<< "洛书运行时错误: 无法调用函数";
            cout<< _func<<endl;
            return "";
        }
		_fun.push_back( (LOSU_API_VOID)dlsym(_ptr_dll,_func));
		_rt = _fun[0]( top().c_str(), stack[2].c_str(), stack[3].c_str(), stack[4].c_str(), stack[5].c_str(), stack[6].c_str(), stack[7].c_str(), stack[8].c_str(), stack[9].c_str(), stack[10].c_str(), stack[11].c_str(), stack[12].c_str(), stack[13].c_str(), stack[14].c_str(), stack[15].c_str(), stack[16].c_str());
		_fun.pop_back();
		//dlclose(_ptr_dll);
    #endif
    return _rt;
}
string ls_vm::lsi(const char* _vm)
{
    typedef const char* (*LOSU_API_VOID)( const char* _s1,const char* _s2,const char* _s3,const char* _s4,const char* _s5,const char* _s6,const char* _s7,const char* _s8,const char* _s9,const char* _s10,const char* _s11,const char* _s12,const char* _s13,const char* _s14,const char* _s15,const char* _s16);
    vector<LOSU_API_VOID> _fun;
    string _rt;
    const char* _func = _vm;
    string  _str_dll = LS_LSI_PATH;
	_str_dll = _str_dll + _vm + ".lsd";
    const char* _dll = _str_dll.c_str();
    #if (LS_PLAT == 1)
        HMODULE _ptr_dll = LoadLibrary(_dll);
        if (_ptr_dll == NULL)
        {
            cout<< "洛书运行时错误: 无法调用函数";
            cout<< _func<<endl;
            return "";
        }
		_fun.push_back( (LOSU_API_VOID)GetProcAddress(_ptr_dll,_func));
		_rt = _fun[0]( top().c_str(), stack[2].c_str(), stack[3].c_str(), stack[4].c_str(), stack[5].c_str(), stack[6].c_str(), stack[7].c_str(), stack[8].c_str(), stack[9].c_str(), stack[10].c_str(), stack[11].c_str(), stack[12].c_str(), stack[13].c_str(), stack[14].c_str(), stack[15].c_str(), stack[16].c_str());
		_fun.pop_back();
		//FreeLibrary(_ptr_dll);
    #endif
    #if (LS_PLAT == 2)
        void* _ptr_dll = dlopen(_dll,RTLD_NOW);
        if (_ptr_dll == NULL)
        {
            cout<< "洛书运行时错误: 无法调用函数";
            cout<< _func<<endl;
            return "";
        }
		_fun.push_back( (LOSU_API_VOID)dlsym(_ptr_dll,_func));
		_rt = _fun[0]( top().c_str(), stack[2].c_str(), stack[3].c_str(), stack[4].c_str(), stack[5].c_str(), stack[6].c_str(), stack[7].c_str(), stack[8].c_str(), stack[9].c_str(), stack[10].c_str(), stack[11].c_str(), stack[12].c_str(), stack[13].c_str(), stack[14].c_str(), stack[15].c_str(), stack[16].c_str());
		_fun.pop_back();
		//dlclose(_ptr_dll);
    #endif
    return _rt;
}
void ls_vm::hostfile(string _file,string _sign)
{
    long _loop;
    string label,sign,sign2,_sign_start,_sign_end;
    string _lvm,_lvm_func;
    _sign_start = "<" + _sign+ ">";
    _sign_end = "</" + _sign + ">";
    start();
    try
    {
        _fin.close();
        _fin.open(_file);
        do
        {
            getline(_fin,sign);
            sign = replace_all(sign,ls_cr(),"");
            if (_fin.eof() == 1)
            {
                throw "洛书运行时错误:  找不到加载点\n";
            }
            
            if (sign == _sign_start)
            {
                break;
            }
            
        } while (1);
        do
        {
            if (_fin.eof() == 1)
            {
                throw "洛书运行时错误:  错误的中间码格式\n";
            }
            _fin>> sign;
            sign = replace_all(sign,ls_cr(),"");
            if (mid(sign,1,8) == "<thread.")
			{
				do
				{
					if (_fin.eof() == 1)
					{
						throw "洛书运行时错误:  错误的中间码格式\n";
					}
					getline(_fin,sign2);
					if (mid(sign2,1,9) == "</thread.")
					{
						break;
					}
				} while (1);
				
			}
            if (sign == "exit")
            {
                conf = 1; 
            }
            if (sign == _sign_end)
            {
                return;
            }
            if (sign == "goto")
            {
                _fin>>label;
                _fin.close();
                _fin.open(_file);
                do
                {
                    if (_fin.eof() == 1)
                    {
                        throw "洛书运行时错误:  找不到指定标签\n";
                    }
                    getline(_fin,sign);
                    if (sign == "ls_label<" + label + ">")
                    {
                        break;
                    }
                } while (1);
            }
            if (sign == "add")
            {
                _fin>> sign;
                add(sign);
            }
            if (sign == "sleep")
            {
                ls_sleep(atoi(top().c_str()));
            }
            if (sign == "push")
            {
                getline(_fin,sign);
                getline(_fin,sign);
                push(trmate(sign));
            }
            if (sign == "sys")
            {
                system(top().c_str());
            }
            if (sign == "pop")
            {
                pop();
            }
            if (sign == "clear")
            {
                _fin>>sign;
                clear(sign);
            }
            if (sign == "mov")
            {
                _fin>>sign;
                mov(sign);
            }
            if (sign == "end")
            {
                _fin.close();
                exit(0);
            }
            if (sign == "lvm")
            {
                _fin>>_lvm;
                _fin>>_lvm_func;
                push(lvm(_lvm.c_str(),_lvm_func.c_str()));
            }
            if (sign == "lsi")
            {
                _fin>>_lvm;
                push(lsi(_lvm.c_str()));
            }
            if (sign == "lei")
            {
                _fin>>_lvm;
                _fin>>_lvm_func;
                push(lei(_lvm.c_str(),_lvm_func.c_str()));
            }
            if (sign == "api")
			{
				_fin>> sign;
				push(api(sign));
			}
            if (sign == "loop")
            {
                _fin>> sign;
                _loop = atoi(top().c_str());
                if (_loop != 0)
                {
                    int i = _loop; 
                    do
                    {
                        hostfile(mainfile,"loop." + sign);
                        if (conf == 1)
                        {
                            do
                            {
                                if (_fin.eof() == 1)
                                {
                                    throw "洛书运行时错误:  错误的中间码格式\n";
                                }
                                getline(_fin,sign2);
                                if (sign2 == "</loop." + sign + ">")
                                {
                                    break;
                                }
                            } while (1);
                            break;
                        }
                        if (i > 0)
                        {
                            i--;
                        }
                    }while( i > 0 || i < 0);
                }
                else
                {
                    do
                    {
                        if (_fin.eof() == 1)
                        {
                            throw "洛书运行时错误:  错误的中间码格式\n";
                        }
                        getline(_fin,sign2);
                        if (sign2 == "</loop." + sign + ">")
                        {
                            break;
                        }
                    } while (1);
                }
                conf = 0;
            }
            if (sign == "logic")
            {
                _fin>>sign;
                if (1 < 2)
                {
                    if (val(stack[3]) > val(stack[1]) && stack[2] == ">")
                    {
                        hostfile(mainfile,"logic." + sign);
                        goto logicture;
                    }
                    if (val(stack[3]) >= val(stack[1]) && stack[2] == ">=")
                    {
                        hostfile(mainfile,"logic." + sign);
                        goto logicture;
                    }
                    if (val(stack[3]) < val(stack[1]) && stack[2] == "<")
                    {
                        hostfile(mainfile,"logic." + sign);
                        goto logicture;
                    }
                    if (val(stack[3]) <= val(stack[1]) && stack[2] == "<=")
                    {
                        hostfile(mainfile,"logic." + sign);
                        goto logicture;
                    }
                    if (val(stack[3]) == val(stack[1]) && stack[2] == "==")
                    {
                        hostfile(mainfile,"logic." + sign);
                        goto logicture;
                    }
                    if (val(stack[3]) != val(stack[1]) && stack[2] == "!==")
                    {
                        hostfile(mainfile,"logic." + sign);
                        goto logicture;
                    }
                    if (stack[3] == stack[1] && stack[2] == "=")
                    {
                        hostfile(mainfile,"logic." + sign);
                        goto logicture;
                    }
                    if (stack[3] != stack[1] && stack[2] == "!=")
                    {
                        hostfile(mainfile,"logic." + sign);
                        goto logicture;
                    }
                    sign2 = "";
                    do
                    {
                        if (_fin.eof() == 1)
                        {
                            throw "洛书运行时错误:  错误的中间码格式\n";
                        }
                        getline(_fin,sign2);
                        if (sign2 == "</logic." + sign + ">")
                        {
                            break;
                        }
                    } while (1);
                    logicture:;
                }
                
                
            }
            if (sign == "thread")
            {
                create_new_th(top());
            }
            
        } while (conf == 0);
        

    }
    catch(const char* _errinfo)
    {
        cout<< _errinfo;
        exit(-1);
    }
    
}
void create_new_th(string _th_name)
{
    thread th(cthread,_th_name);
    th.detach();
}
void cthread(string _thname)
{
    ls_vm vim;
    vim.hostfile(mainfile,"thread." + _thname);
}
string getcsip()
{
    ifstream _f;
    string _csip;
    _f.open(mainfile);
    do
    {
        _f>> _csip;
        if (_csip == "csip")
        {
            _f>> _csip;
            return _csip;
        }
        if (_f.eof() == 1 || _f.is_open() == 0)
        {
            cout<< "洛书运行时错误: 缺少CSIP"<<endl;
            exit(1);
        }
    } while (1);
    
}
}


extern "C"{
int main(int argc,const char** argv)
{
    try
    {
        main_argc = argc;
        main_argv = argv;
        ls_vm vim;
        if (command() == "")
        {
            throw "洛书汉语编程开发组件\nLosu Program Kits Losu 0.3\n洛书解释器\n(c) Chen-chaochen\nLicense GPL-3.0\n\a";
        }
        mainfile = command();
        array_start();
        vim.hostfile(mainfile,getcsip()); 
		pthread_exit(NULL);
    }
    catch(const char* _errinfo)
    {

    	cout<< _errinfo;
    }
    

}
}

