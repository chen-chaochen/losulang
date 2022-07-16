
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
	if (apiname == "+")
	{
		return to_string(val(stack[2]) + val(top()));
	}
	if (apiname == "-")
	{
		return to_string(val(stack[2]) - val(top()));
	}
	if (apiname == "*")
	{
		return to_string(val(stack[2]) * val(top()));
	}
	if (apiname == "/")
	{
		return to_string(val(stack[2]) / val(top()));
	}
	if (apiname == "&")
	{
		return stack[2] + top();
	}
	if (apiname == str_sign_92()) //sign_92指 "\" 符号
	{
		return to_string(val_int(stack[2]) % val_int(top()));
	}
	if (apiname == "|")
	{
		return to_string((val_int(stack[2]) - (val_int(stack[2]) % val_int(top()))) / val_int(top()));
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
    for (long i = 0; i < vaname.size(); i++)
	{
		if (vaname[i] == "")
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
			vaname[i] = "";
            vavalue[i] = "";
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
		FreeLibrary(_ptr_dll);
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
		dlclose(_ptr_dll);
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
		FreeLibrary(_ptr_dll);
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
		dlclose(_ptr_dll);
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
		FreeLibrary(_ptr_dll);
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
		dlclose(_ptr_dll);
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
                    if (sign == "ls_lable<" + label + ">")
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
            if (sign == "push")
            {
                _fin>> sign;
                push(trmate(sign));
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
                push(trmate(lvm(_lvm.c_str(),_lvm_func.c_str())));
            }
            if (sign == "lsi")
            {
                _fin>>_lvm;
                push(trmate(lsi(_lvm.c_str())));
            }
            if (sign == "lei")
            {
                _fin>>_lvm;
                _fin>>_lvm_func;
                push(trmate(lei(_lvm.c_str(),_lvm_func.c_str())));
            }
            if (sign == "api")
			{
				_fin>> sign;
				push(trmate(api(sign)));
			}
            if (sign == "loop")
            {
                _fin>> sign;
                _loop = atoi(top().c_str());
                if (_loop != 0)
                {
                    for (long i = _loop; i > 0 || i < 0; i--)
                    {
                        hostfile(mainfile,"loop." + sign);
                        if (conf == 1)
                        {
                            break;
                        }
                        if (i < 0)
                        {
                            i++;
                        }
                        
                    }
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
                if (1)
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
        cout<< trmate(_errinfo);
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
