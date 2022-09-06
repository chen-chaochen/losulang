/*
LPK 1.0 LTS SP1 1.0.1
Losu Program-language Kits 1.0 LTS
Powered by chen-chaochen
https://gitee.com/chen-chaochen/lpk
*/


#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

typedef string ls_io; 
#define ls_men vector
#define ls_out_file ofstream 
#define ls_in_file ifstream 

ls_men<ls_io> ls_losuh_losuvm,ls_losuh_losusi,ls_losuh_losuei;




int main(int ls_losuh_argc, const char** ls_losuh_argv)
{
    try
    {
        if (ls_losuh_argc == 1)
        {
            throw "洛书编程语言 1.0 LTS\nLosu Program Kits Losu 1.0 LTS\n组件:   洛书模块生成器\n(c) 陈朝臣\n遵循 洛书使用协议,第一版\n";
        }
        ls_io ls_losuh_mainfile = ls_losuh_argv[1];
        ls_io ls_losuh_tmp;
        ls_in_file ls_losuh_ifile;
        ls_out_file ls_losuh_ofile;
        bool ls_losuh_conf;
        ls_losuh_conf = 0;
        ls_losuh_ifile.open(ls_losuh_mainfile,ios::in);
        do
        {
            ls_losuh_ifile>>ls_losuh_tmp;
            if (ls_losuh_tmp == "push")
            {
                getline(ls_losuh_ifile,ls_losuh_tmp);
                getline(ls_losuh_ifile,ls_losuh_tmp);
                continue;
            }
            if (ls_losuh_tmp == "lvm")
            {
                ls_losuh_ifile>>ls_losuh_tmp;
                ls_losuh_ofile.open(("losuvm_"+ls_losuh_tmp+".cpp").c_str(),ios::out);
                ls_losuh_ofile<<"#include<string>\nusing namespace std;\n"<<"typedef string ls_io;\ntypedef const char* ls_post;\n";
                ls_losuh_ofile.close();
                ls_losuh_ifile>>ls_losuh_tmp;
                continue;
            }
            if (ls_losuh_tmp == "lsi")
            {
                ls_losuh_ifile>>ls_losuh_tmp;
                ls_losuh_ofile.open(("losusi_"+ls_losuh_tmp+".cpp").c_str(),ios::out);
                ls_losuh_ofile<<"#include<string>\nusing namespace std;\n"<<"typedef string ls_io;\ntypedef const char* ls_post;\n";
                ls_losuh_ofile.close();
                ls_losuh_ifile>>ls_losuh_tmp;
                continue;
            }
            if (ls_losuh_tmp == "lei")
            {
                ls_losuh_ifile>>ls_losuh_tmp;
                ls_losuh_ofile.open((ls_losuh_tmp+".c").c_str(),ios::out);
                ls_losuh_ofile<<"typedef const char* ls_io;\ntypedef const char* ls_post;\n";
                ls_losuh_ofile.close();
                ls_losuh_ifile>>ls_losuh_tmp;
                continue;
            }
            
        } while (ls_losuh_ifile.eof()==0);
        ls_losuh_ifile.close();
        ls_losuh_ifile.open(ls_losuh_mainfile,ios::in);
        do
        {
            ls_losuh_conf = 0;
            ls_losuh_ifile>>ls_losuh_tmp;
            if (ls_losuh_tmp == "push")
            {
                getline(ls_losuh_ifile,ls_losuh_tmp);
                getline(ls_losuh_ifile,ls_losuh_tmp);
                continue;
            }
            if (ls_losuh_tmp == "lvm")
            {
                ls_losuh_ifile>>ls_losuh_tmp;
                ls_losuh_ofile.open(("losuvm_"+ls_losuh_tmp+".cpp").c_str(),ios::app);
                ls_losuh_ifile>>ls_losuh_tmp;
                for (int i = 0; i < ls_losuh_losuvm.size(); i++)
                {
                    if (ls_losuh_tmp == ls_losuh_losuvm[i])
                    {
                        ls_losuh_conf = 1;
                        break;
                    }
                }
                if (ls_losuh_conf == 0)
                {
                    ls_losuh_ofile<<"extern \"C\" ls_io "<<ls_losuh_tmp<<"(ls_post);"<<endl;   
                }
                ls_losuh_ofile.close();
                continue;
            }
            if (ls_losuh_tmp == "lsi")
            {
                ls_losuh_ifile>>ls_losuh_tmp;
                ls_losuh_ofile.open(("losusi_"+ls_losuh_tmp+".cpp").c_str(),ios::app);
                ls_losuh_ifile>>ls_losuh_tmp;
                for (int i = 0; i < ls_losuh_losusi.size(); i++)
                {
                    if (ls_losuh_tmp == ls_losuh_losusi[i])
                    {
                        ls_losuh_conf = 1;
                        break;
                    }
                }
                if (ls_losuh_conf == 0)
                {
                    ls_losuh_ofile<<"extern \"C\" ls_io "<<ls_losuh_tmp<<"(ls_post);"<<endl;   
                }
                ls_losuh_ofile.close();
                continue;
            }
            if (ls_losuh_tmp == "lei")
            {
                ls_losuh_ifile>>ls_losuh_tmp;
                ls_losuh_ofile.open((ls_losuh_tmp+".c").c_str(),ios::app);
                ls_losuh_ifile>>ls_losuh_tmp;
                for (int i = 0; i < ls_losuh_losuei.size(); i++)
                {
                    if (ls_losuh_tmp == ls_losuh_losuei[i])
                    {
                        ls_losuh_conf = 1;
                        break;
                    }
                }
                if (ls_losuh_conf == 0)
                {
                    ls_losuh_ofile<<"extern \"C\" ls_io "<<ls_losuh_tmp<<"(ls_post);"<<endl;   
                }
                ls_losuh_ofile.close();
                continue;
            }
            
        } while (ls_losuh_ifile.eof()==0);
        ls_losuh_ifile.close();
        
    }
    catch(const char* ls_losuh_errinf)
    {
        cout<<ls_losuh_errinf;
        exit(0);
    }
    
    return 0;
}
