#include<iostream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
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
		
		string tmp;
		tmp = a;
		vector<string> _src={"\\n","\\r","\\'","\\a","\\b","\\f","\\v","\\t"};
		vector<string> _aim={"\n" , "\r", "\"", "\a", "\b", "\f", "\v", "\t"};
		for (int i = 0; i < _src.size(); i++)
		{
			tmp = replace_all(tmp,_src[i],_aim[i]);
		}
		return tmp;
	}

	const char* ls_webui_ul(const char* ul_str)
	{
		string tmp = ul_str;
		tmp = replace_all(tmp," || ","</li><li>");
		tmp = "<li>"+tmp+"</li>";
		return tmp.c_str();		
	}
	const char* ls_webui_select(const char* ul_str)
	{
		string tmp = ul_str;
		tmp = replace_all(tmp," || ","</option><option>");
		tmp = "<option>"+tmp+"</option>";
		return tmp.c_str();		
	}
}
