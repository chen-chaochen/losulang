/*
LPK 1.0 LTS
Losu Program-language Kits 1.0 LTS
Powered by chen-chaochen
https://gitee.com/chen-chaochen/lpk 

*/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string mid(string a,long start_pos,long len_pos)
{
    if (start_pos > a.length())
    {
        return "";
    }
	return a.substr(start_pos - 1,len_pos);
}
string replace_all(string src,string old_string,string new_string) 
{
    long i;
	string rep;
	i = 1;
	do
	{
		if (mid(src,i,old_string.length()) == old_string )
		{
			i = i + old_string.length() -1;
			rep = rep + new_string;
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
string space(string a,int b)
{
    string tmp;
    for(int i = 0;i<b;i++)
    {
        tmp = tmp + " ";
    }
    tmp = tmp + a;
    return tmp;
}
int tab;
long linenum;
void forecompiler(string _file)
{
    linenum = 0;
    ifstream fs_in;
    ofstream fs_out;
    try
    {
        //打开mainfile
        fs_in.open(_file+".hetu");
        fs_out.open(_file+".losu");
        do
        {
            string tmp;
            getline(fs_in,tmp);
            linenum++;
            int i;
            i = 1;
            if(replace_all(tmp," ","") == "")
            {
                continue;
            }
            do
            {
                if(mid(tmp,i,1) != " ")
                {
                    break;
                }
                i++;
            }while(i<=tmp.length());
            if(mid(tmp,i,1) == "#")
            {
                tmp = mid(tmp,1,i-1)+"+"+mid(tmp,i+1,tmp.length()-i);
            }
            if(mid(tmp,i,2) == "/*")
            {
                tmp = mid(tmp,1,i-1)+"/{"+mid(tmp,i+2,tmp.length()-i-1);
            }
            if(i == tab + 4)
            {  
                fs_out<<"{"<<endl;
                fs_out<<tmp<<endl;
                tab=tab+4;
            }
            else if((i-1) % 4 == 0 && i < tab)
            {
                for (int j = i;j < tab; j = j+4)
                {
                    fs_out<<"}"<<endl;
                }
                fs_out<<tmp<<endl;
                tab = i;
            }
            else if(i == tab)
            {
                fs_out<<tmp<<endl;
            }
            else
            {
                throw "错误的缩进格式\n";
            }

        }while(fs_in.eof()==0);
        if (tab != 1)
        {
            for(int k = 1;k < tab; k=k+4)
            {
                fs_out<<"}"<<endl;
            }
        }
        fs_in.close();
        fs_out.close();

    }
    catch(const char* errinf)
    {
        fs_in.close();
        fs_out.close();
        cout<< "河图编译器\n####错误####\n在源_file "<<_file<<".hetu 中\n第: "<<linenum<<" 行\n";
        cout<<errinf<<endl;
        remove((_file+".losu").c_str());
        exit(linenum);
    }
    return;
}

int main(int argc,const char** argv)
{
    tab = 1;
    if(argc == 2)
    {
        string mainfile = argv[1];
        ifstream i;
        i.open((mainfile+".hetu").c_str());
        if(i.is_open()==0)
        {
            cout<<"河图编译器    找不到指定_file!\n";
            exit(0);
        }
        i.close();
        forecompiler(mainfile);
        if(system(("losuc "+ mainfile).c_str())!=0)
        {
            return 1;
        }
        //remove((mainfile+".losu").c_str());
        return 0;
    }
    cout<<"洛书编程语言 1.0 LTS\nLosu Program Kits Losu 1.0 LTS\n组件:   河图编译器\n(c) 陈朝臣\n遵循 洛书使用协议,第一版\n";
    return 0;
}