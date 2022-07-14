#include<iostream>
#include<string>
#include<string.h>
#include<fstream> 
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
		string b;
		string b1;
		string c;
		string d;
		b1 = char(10);
		b = b1;
		b1 = char(92);
		d = b1 + "n";
		c = replace_all(a ,d, b);
		return c;
	}

	const char* ls_ifstream_read(const char* _fname,const char* _pos)
	{
		string _tmp;
		ifstream _f;
		_f.open(_fname);
		long _int_pos = atoi(_pos);
		if (_int_pos < 1)
		{
			return "error pos!";
		}
		for(int i = 1;i <= _int_pos;i++)
		{
			_f>> _tmp;
		}
		_f.close();
		return _tmp.c_str();
	}
}
