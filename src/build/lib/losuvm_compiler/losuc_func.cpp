void lsc::backfast(string _srcfile,string _outfile)
{
    /*
    后端的去空行优化
    */
    ifstream fin;
    ofstream fout;
    string tmp;
    fin.open(_srcfile);
    fout.open(_outfile);
    if (fin.is_open() == 0 || fout.is_open() == 0)
    {
        throw "编译链出错\n";
    }
    do
    {
        getline(fin,tmp);
        if (replace_all(tmp," ","") == "")
        {
            continue;
        }
        fout<<tmp<<endl;
    } while (fin.eof() == 0);
}
string lsc::get_formate(string _exp)
{
    string exp = _exp;
    string keyword[8] = {"+","-","*","&","/","\\","|","="};
    string _keyword[8] = {" + "," - "," * ","  &  "," / "," \\ "," | "," = "};
    for (int i = 0; i < 8; i++)
    {
        exp = replace_all(exp,keyword[i],_keyword[i]);
    }
    return exp;
}
void lsc::loadlib(string _falib,string _sonlib)
{
    ofstream fout;
    fout.open(objlib,ios::app);
    fout<<ls_endl()<<replace_all(findclass(_falib),"[此类]·",_sonlib + "·")<<endl;
    fout.close();
}
void lsc::includelib(string _libname)
{
    ifstream fin;
    ofstream fout;
    string tmp;
    string libname = LS_INC + _libname + ".lsc";
    fin.open(libname);
    fout.open(classlib,ios::app);
    fout<<ls_endl();
    do
    {
        getline(fin,tmp);
        fout<<tmp<<ls_endl();
    } while (fin.eof() == 0);
    fin.close();
    fout.close();
}
void lsc::ana_math_exp(string _exp,string _valfore)
{
    string exp_ = get_formate(_exp);
    string keyword[8] = {"+","-","*","&","/","\\","|","="};
    string tmp,_tmp;
    int pos,conf;
    conf = 0;
    pos = 0;
    do
    {
        conf = 0;
        pos++;
        tmp = "";
        if (mid(exp_,pos,1) == " ")
        {
            continue;
        }
        for (int j = 0; j < 8; j++)
        {
            if (mid(exp_,pos,1) == keyword[j])
            {
                _tmp = mid(exp_,pos,1);
                conf = 1; 
                break;
            }
        }
        if (conf == 1)
        {
            continue;
        }
        if (mid(exp_,pos,1) == "\"")
        {
            do
            {
                pos++;
                if (mid(exp_,pos,1) == "\"")
                {
                    break;
                }
                tmp = tmp +  mid(exp_,pos,1);
            } while (pos <= exp_.length());
            tmp = _trmate(tmp);
            fs_out<<" push "<<tmp<<" ";
            fs_out<<"api "<<_tmp<<" ";
        }
        else if (mid(exp_,pos,1) == "<")
        {
            do
            {
                pos++;
                if (mid(exp_,pos,1) == ">")
                {
                    break;
                }
                tmp = tmp +  mid(exp_,pos,1);
            } while (pos <= exp_.length());
            fs_out<<" add "<<tmp<<" ";
            fs_out<<"api "<<_tmp<<" ";
        }
        else
        {
            tmp = tmp + mid(exp_,pos,1);
            do
            {
                pos++;
                if (mid(exp_,pos,1) == " ")
                {
                    break;
                }
                tmp = tmp +  mid(exp_,pos,1);
            } while (pos < exp_.length());
            tmp = _valfore + tmp;
            fs_out<<" add "<<tmp<<" ";
            fs_out<<"api "<<_tmp<<" ";
        }
    } while(pos < exp_.length());
    if (pos > exp_.length())
    {
        throw "错误的变量格式\n";
    }
    
}
string lsc::findclass(string _classname)
{
    /*
    Findclass 
    It will find the class from outfile to classlib;
    */
    string tmp,_rt;
    ifstream fin;
    fin.open(outfile);
    do
    {
        getline(fin,tmp);
        if (tmp == "<" + _classname + ">")
        {
            break;
        }
        if (fin.eof() == 1)
        {
            break;
        }
    } while (1);
    _rt = "";
    do
    {
        getline(fin,tmp);
        if (tmp == "</" + _classname + ">")
        {
            fin.close();
            return _rt;
        }
        if (fin.eof() == 1)
        {
            break;
        }
        _rt = _rt + ls_endl() + tmp;   
    } while (1);
    fin.close();
    fin.open(classlib);
    do
    {
        getline(fin,tmp);
        if (tmp == "<" + _classname + ">")
        {
            break;
        }
        if (fin.eof() == 1)
        {
            throw "找不到所需的类\n";
        }
    } while (1);
    _rt = "";
    do
    {
        getline(fin,tmp);
        if (tmp == "</" + _classname + ">")
        {
            fin.close();
            return _rt;
        }
        if (fin.eof() == 1)
        {
            cout<< "####警告###\n在源文件 "<<mainfile<<" 中\n第 "<<linenum<<" 行\n类 \""<<_classname<<"\" 的结构出现异常";
            return _rt;
        }
        _rt = _rt + ls_endl() + tmp;   
    } while (1);
    fin.close();
    return "";
}
string lsc::findclass_exp(string _classname)
{
    string tmp,_rt;
    ifstream fin;
    fin.open(classlib);
    do
    {
        getline(fin,tmp);
        if (tmp == "<" + _classname + ">")
        {
            break;
        }
        if (fin.eof() == 1)
        {
            break;
        }
    } while (1);
    _rt = "";
    do
    {
        getline(fin,tmp);
        if (tmp == "</" + _classname + ">")
        {
            fin.close();
            return _rt;
        }
        if (fin.eof() == 1)
        {
            break;
        }
        _rt = _rt + ls_endl() + tmp;   
    } while (1);
    fin.close();
    fin.open(outfile);
    do
    {
        getline(fin,tmp);
        if (tmp == "<" + _classname + ">")
        {
            break;
        }
        if (fin.eof() == 1)
        {
            throw "找不到所需的类\n";
        }
    } while (1);
    _rt = "";
    do
    {
        getline(fin,tmp);
        if (tmp == "</" + _classname + ">")
        {
            fin.close();
            return _rt;
        }
        if (fin.eof() == 1)
        {
            cout<< "####警告###\n在源文件 "<<mainfile<<" 中\n第 "<<linenum<<" 行\n类 \""<<_classname<<"\" 的结构出现异常";
            return _rt;
        }
        _rt = _rt + ls_endl() + tmp;   
    } while (1);
    fin.close();
    return "";
}
void lsc::compile(string _file)
{
    /*
    前端的引入
    */
    try
    {
        mainfile = _file + ".losu";
        classlib = _file + ".class.tmp";
        objlib = _file + ".obj.tmp";
        outfile = _file + ".lsi";
        _outfile = _file + ".lsc";
        outtmp = _file + ".out.tmp";
        //test the exisisting of mainfile
        fs_in.open(mainfile,ios::in);
        if (fs_in.is_open() == 0)
        {
            throw "找不到指定文件!\n";
        }
        //open the compiler tmp file
        ofstream f1,f2,f3;
        f1.open(classlib,ios::out);
        f2.open(objlib,ios::out);
        f3.open(outtmp,ios::out);
        if (f1.is_open() == 0 || f2.is_open() == 0||f3.is_open() == 0)
        {
            throw "无法创建编译缓冲文件\n请检查编译器执行权限\n";
        }
        f1.close();
        f2.close();
        f3.close();
        //boot compiler conf
        close_sign_num = 0;
        open_sign_num = 0;
        ifnum = 0;
        loopnum = 0;
        linenum = 0;
        threadnum = 0;
        fs_out.open(outfile,ios::out);
        if (fs_out.is_open() == 0)
        {
            throw "无法创建输出文件\n请检查编译器执行权限\n";
        }
        //start compile
        lsc::makefile("","","");
        fs_out.close();
        fs_in.close();
        lsc::backfast(outfile,_outfile);
        remove(outfile.c_str());
        remove(classlib.c_str());
        remove(objlib.c_str());
        remove(outtmp.c_str());

    }
    catch(const char* errinfo)
    {
        cout<< errinfo;
        exit(-1);
    }
    
}
void lsc::makefile(string _endsign,string _valfore,string _extends)
{
    /*
    编译器核心算法
    */
    string tmp,sign,sign_tmp;
    int _pos,i;
    try
    {
        do
        {
            getline(fs_in,tmp);
            _pos = 0;
            i = 0;
            linenum++;
            sign_tmp = "";
            fs_out<<endl;
            //conditon
            if (replace_all(tmp," ","") == "")
            {
                continue;
            }      
            do
            {
                _pos++;
                if (mid(tmp,_pos,2) == "//")
                {
                    break;
                }
                if (mid(tmp,_pos,1) == "+")
                {
                    sign = "";
                    do
                    {
                        _pos++;
                        if (mid(tmp,_pos,1) == " "||mid(tmp,_pos,1) == "(" )
                        {
                            break;
                        }
                        sign = sign + mid(tmp,_pos,1);
                    } while (_pos < tmp.length());
                    
                    if (replace_all(sign," ","") == "加载")
                    {
                        sign = "";
                        do
                        {
                            _pos++;
                            sign = sign + mid(tmp,_pos,1);
                        } while (_pos < tmp.length());
                        fs_out<< "csip "<<sign<<endl;
                        break;
                    }
                    if (replace_all(sign," ","") == "变量")
                    {
                        break;
                    } 
                    if (replace_all(sign," ","") == "属性")
                    {
                        break;
                    } 
                    if (replace_all(sign," ","") == "跳出")
                    {
                        fs_out<<"exit ";
                        break;
                    }
                    if (replace_all(sign," ","") == "回收")
                    {
                        sign = "";
                        do
                        {
                            _pos++;
                            sign = sign + mid(tmp,_pos,1);
                        } while (_pos < tmp.length());
                        sign = replace_all(sign," ","");
                        if (mid(sign,1,1) == "<")
                        {
                            sign = mid(sign,2,sign.length() - 2);
                        }
                        else
                        {
                            sign = _valfore + sign;
                        }
                        
                        fs_out<< "clear "<<sign<<" ";
                        break;
                    }
                    if (replace_all(sign," ","") == "指令")
                    {
                        getline(fs_in,sign);
                        if (replace_all(sign," ","") != "{")
                        {
                            throw "缺少标识符 \"{\"\n";
                        }
                        open_sign_num++;
                        linenum++;
                        do
                        {
                            getline(fs_in,sign);
                            linenum++;
                            if (replace_all(sign," ","") == "}")
                            {
                                break;
                            }
                            if (fs_in.eof() == 1)
                            {
                                throw "缺少标识符 \"}\"";
                            }
                            i = 0;
                            do
                            {
                                i++;
                                if (mid(sign,i,1) != " ")
                                {
                                    break;
                                }
                            } while (1);
                            sign = mid(sign,i,sign.length() - i + 1);
                            fs_out<<sign<<" "<<endl;
                        } while (1);
                        close_sign_num++;
                        break;
                    }
                    if (replace_all(sign," ","") == "类")
                    {
                        sign = "";
                        do
                        {
                            _pos++;
                            sign = sign + mid(tmp,_pos,1);   
                        } while ( _pos < tmp.length() );
                        sign = replace_all(sign," ","");
                        getline(fs_in,sign_tmp);
                        if (replace_all(sign_tmp," ","") != "{")
                        {
                            throw "缺少标识符 \"{\"\n";
                        }
                        linenum++;
                        open_sign_num++;
                        fs_out<<"<"<<_valfore<<sign<<">"<<endl;
                        makefile(sign,"[此类]·","");
                        break;
                    }
                    if (replace_all(sign," ","") == "方法")
                    {
                        string _voidname,_voidconf;
                        do
                        {
                            _pos++;
                            if (mid(tmp,_pos,1) != " ")
                            {
                                break;
                            }
                        } while (_pos <= tmp.length());
                        _voidname = _voidname + mid(tmp,_pos,1);
                        do
                        {
                            _pos++;
                            if (mid(tmp,_pos,1) == "(")
                            {
                                break;
                            }
                            _voidname = _voidname + mid(tmp,_pos,1);
                        } while (_pos <= tmp.length());
                        _voidname = _valfore + _voidname; 
                        _voidname = replace_all(_voidname," ","");
                        fs_out<<"<" + _voidname + ">"<<endl;
                        _voidconf = "";
                        do
                        {
                            _pos++;
                            if (mid(tmp,_pos,1) == ",")
                            {
                                _voidconf = _voidname + "·" + _voidconf;
                                _voidconf = replace_all(_voidconf," ","");
                                fs_out<<_voidconf<<" ";
                                _voidconf = "";
                                _pos++;
                            }
                            if (mid(tmp,_pos,1) == ")")
                            {
                                _voidconf = _voidname + "·" + _voidconf;
                                _voidconf = replace_all(_voidconf," ","");
                                fs_out<<_voidconf<<" ";
                                _voidconf = "";
                                break;
                            }
                            _voidconf = _voidconf + mid(tmp,_pos,1);
                        } while (_pos <= tmp.length());
                        fs_out<<endl;
                        getline(fs_in,sign_tmp);
                        if (replace_all(sign_tmp," ","") != "{")
                        {
                            throw "缺少标识字符 \"{\"\n";
                        }
                        if (_pos > tmp.length())
                        {
                            throw "缺少标识符\n";
                        }
                        linenum++;
                        open_sign_num++;
                        makefile(_voidname,_voidname + "·","");
                        break;
                    }
                    if (replace_all(sign," ","") == "继承")
                    {
                        string son_class;
                        son_class = "";
                        sign = "";
                        do
                        {
                            _pos++;
                            if (mid(tmp,_pos,1) == " ")
                            {
                                break;   
                            }
                            sign = sign + mid(tmp,_pos,1);   
                        } while ( _pos < tmp.length() );
                        if (_pos == tmp.length())
                        {
                            throw "错误的语法格式\n";
                        }
                        sign = replace_all(sign," ","");
                        do
                        {
                            _pos++;
                            son_class = son_class + mid(tmp,_pos,1);
                        } while (_pos < tmp.length() );
                        son_class = replace_all(son_class," ","");
                        getline(fs_in,sign_tmp);
                        if (replace_all(sign_tmp," ","") != "{")
                        {
                            throw "缺少标识符 \"{\"\n";
                        }
                        linenum++;
                        open_sign_num++;
                        fs_out<<"<"<<_valfore<<son_class<<">"<<endl;
                        makefile(son_class,"[此类]·",findclass_exp(sign));
                        break;
                    }
                    if (replace_all(sign," ","") == "线程")
                    {
                        sign = "";
                        do
                        {
                            _pos++;
                            sign = sign + mid(tmp,_pos,1);   
                        } while ( _pos < tmp.length() );
                        sign = _valfore + sign;
                        sign = replace_all(sign," ","");
                        getline(fs_in,sign_tmp);
                        if (replace_all(sign_tmp," ","") != "{")
                        {
                            throw "缺少标识符 \"{\"\n";
                        }
                        linenum++;
                        open_sign_num++;
                        fs_out<<"push "<<sign<<" thread"<<endl;
                        fs_out<<"<thread."<<sign<<">"<<endl;
                        makefile("thread." + sign,_valfore,"");
                        break;
                    }
                    if (replace_all(sign," ","") == "循环")
                    {
                        string logic_exp1,loopname;
                        loopname = _valfore + to_string(loopnum);
                        loopnum++;
                        logic_exp1 = "";
                        do
                        {
                            _pos++;
                            if (mid(tmp,_pos,1) == ")")
                            {
                                break;
                            }
                            logic_exp1 = logic_exp1 + mid(tmp,_pos,1);
                        } while (_pos <= tmp.length());
                        logic_exp1 = replace_all(logic_exp1,"(","");
                        logic_exp1 = "= " + logic_exp1;
                        ana_math_exp(logic_exp1,_valfore);
                        getline(fs_in,sign_tmp);
                        if (replace_all(sign_tmp," ","") != "{")
                        {
                            throw "缺少标识符 \"{\"\n";
                        }
                        if (_pos > tmp.length())
                        {
                            throw "缺少标识符\n";
                        }
                        linenum++;
                        fs_out<<"loop "<<loopname<<endl;
                        fs_out<<endl<<"<loop."<<loopname<<">"<<endl;
                        makefile("loop." + loopname,_valfore,"");
                        break;
                    }
                    if (replace_all(sign," ","") == "导入")
                    {
                        string incname;
                        incname = "";
                        do
                        {
                            _pos++;
                            incname = incname + mid(tmp,_pos,1);
                        } while (_pos < tmp.length());
                        incname = replace_all(incname," ","");
                        incname = replace_all(incname,"·","/");
                        includelib(incname);
                        break;
                    }
                    if (replace_all(sign," ","") == "实例")
                    {
                        string fa_lib,son_lib;
                        fa_lib = "";
                        do
                        {
                            _pos++;
                            if (mid(tmp,_pos,1) == " ")
                            {
                                break;
                            }
                            fa_lib = fa_lib + mid(tmp,_pos,1);
                        } while (_pos < tmp.length());
                        fa_lib = replace_all(fa_lib," ","");
                        if (_pos ==  tmp.length())
                        {
                            throw "错误的语法格式\n";
                        }
                        son_lib = "";
                        do
                        {
                            _pos++;
                            son_lib = son_lib + mid(tmp,_pos,1);
                        } while (_pos < tmp.length());
                        son_lib = replace_all(son_lib," ","");
                        if (son_lib == "")
                        {
                            throw "错误的语法格式\n";
                        }
                        loadlib(fa_lib,son_lib);
                        break;
                    }
                    if (replace_all(sign," ","") == "如果")
                    {
                        string logic_exp1,logic_exp2,ifname,ifsign;
                        ifname = _valfore + to_string(ifnum);
                        ifnum++;
                        ifsign = "";
                        logic_exp1 = "";
                        do
                        {
                            _pos++;
                            if (mid(tmp,_pos,1) == ")")
                            {
                                break;
                            }
                            logic_exp1 = logic_exp1 + mid(tmp,_pos,1);
                        } while (_pos <= tmp.length());
                        logic_exp1 = replace_all(logic_exp1,"(","");
                        logic_exp1 = "= " + logic_exp1;
                        ana_math_exp(logic_exp1,_valfore);
                        fs_out<<" mov logic1 pop "; 
                        ifsign = "";
                        do
                        {
                            _pos++;
                            if (mid(tmp,_pos,1) == "(")
                            {
                                break;
                            }
                            ifsign = ifsign + mid(tmp,_pos,1);
                        } while (_pos <= tmp.length());
                        ifsign = replace_all(ifsign," ","");
                        logic_exp2 = "";
                        do
                        {
                            _pos++;
                            if (mid(tmp,_pos,1) == ")")
                            {
                                break;
                            }
                            logic_exp2 = logic_exp2 + mid(tmp,_pos,1);
                        } while (_pos <= tmp.length());
                        logic_exp2 = replace_all(logic_exp2,"(","");
                        logic_exp2 = "= " + logic_exp2;
                        ana_math_exp(logic_exp2,_valfore);
                        fs_out<<" mov logic2 pop ";
                        fs_out<<"add logic1 push "<<ifsign<<" add logic2 logic "<<ifname<<endl;
                        fs_out<<"<logic."<<ifname<<">"<<endl;
                        getline(fs_in,sign_tmp);
                        if (_pos > tmp.length())
                        {
                            throw "错误的条件格式\n";
                        }                       
                        if (replace_all(sign_tmp," ","") != "{")
                        {
                            throw "缺少标识符 \"{\"\n";
                        }
                        linenum++;
                        open_sign_num++;
                        makefile("logic." + ifname,_valfore,"");
                        break;
                    }

                }
                if (mid(tmp,_pos,1) == "}")
                {
                    fs_out<<endl<<_extends<<endl;
                    fs_out<<"</"<<_endsign<<">"<<endl;
                    close_sign_num++;
                    return;
                }
                if (mid(tmp,_pos,1) == "=")
                {
                    string _finnalval;
                    _finnalval = replace_all(mid(tmp,1,_pos - 1)," ","");
                    string _val_exp;
                    _val_exp = mid(tmp,_pos,tmp.length() - _pos + 1);
                    ana_math_exp(_val_exp,_valfore);
                    if (mid(_finnalval,1,1) == "<")
                    {
                        _finnalval = mid(_finnalval,2,_finnalval.length() -2 );
                    }
                    else
					{
						_finnalval = _valfore + _finnalval;	
					} 
                    fs_out<<" mov "<<_finnalval<<" ";
                    break;
                }
                if (mid(tmp,_pos,1) == "(")
                {
                    string voidtmp;
                    string voidname = replace_all(mid(tmp,1,_pos - 1)," ","");
                    ifstream _tmp_fin;
                    _tmp_fin.close();
                    _tmp_fin.open(objlib);
                    do
                    {
                        getline(_tmp_fin,sign_tmp);
                        if (replace_all(sign_tmp," ","") == "<" + voidname + ">")
                        {
                            break;
                        }
                        if (_tmp_fin.eof() == 1)
                        {
                            sign_tmp = "找不到指定方法\n" + voidname + "\n";
                            throw sign_tmp.c_str();
                        }
                    } while (1);
                    sign_tmp = "";
                    do
                    {
                        _pos++;
                        if (mid(tmp,_pos,1) == ",")
                        {
                            _tmp_fin>>voidtmp;
                            sign_tmp = "= " + sign_tmp;
                            ana_math_exp(sign_tmp,_valfore);
                            fs_out<<" mov "<<voidtmp<<" ";
                            sign_tmp = "";
                        }
                        if (mid(tmp,_pos,1) == ")")
                        {
                            _tmp_fin>>voidtmp;
                            sign_tmp = "= " + sign_tmp;
                            ana_math_exp(sign_tmp,_valfore);
                            fs_out<<" mov "<<voidtmp<<" ";
                            sign_tmp = "";
                            break;
                        }
                        sign_tmp = sign_tmp + mid(tmp,_pos,1);
                    } while (_pos <= tmp.length());
                    if (_pos > tmp.length())
                    {
                        throw "缺少标识符 \")\"\n";
                    }
                    do
                    {
                        getline(_tmp_fin,sign_tmp);
                        //_tmp_fin>>sign_tmp;
                        if (replace_all(sign_tmp," ","") == "</" + voidname + ">")
                        {
                            break;
                        }
                        if (_tmp_fin.eof() == 1)
                        {
                            cout<< "####警告####\n在源文件: "<<mainfile<<" 中\n第: "<<linenum<<" 行\n调用 "<<voidname<<" 方法时发现\n";
                            cout<< "该方法所对应的引入文件格式错误\n";
                        }
                        fs_out<<sign_tmp<<endl;
                    } while (1);
                    _tmp_fin.close();
                    break;
                }
                
            } while (_pos <= tmp.length());
            if (_pos > tmp.length())
            {
                throw "无法识别为有效的信息\n";
            }
            
        } while (fs_in.eof() == 0);
        if (open_sign_num != close_sign_num)
        {
            throw "错误的语法树\n";
        }
        
    }
    catch(const char* errinfo)
    {
        cout<< "####错误####\n在源文件: "<<mainfile<<" 中\n第: "<<linenum<<" 行\n";
        cout<< errinfo;
        exit(linenum);
    }
        
}


