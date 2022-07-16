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
	
	
	const char* ls_string_mid(const char* _string,const char* _spos,const char* _len)
	{
		string _str_string = _string;
		long _int_spos = atoi(_spos);
		long _int_len = atoi(_len);
		if (_int_spos > _str_string.length())
		{
			return "";
		}
		return _str_string.substr(_int_spos -1,_int_len).c_str();
	}
	const char* ls_string_length(const char* _string)
	{
		string _str_string = _string;
		return to_string(_str_string.length()).c_str();
	}
	const char* ls_string_size(const char* _string)
	{
		string _str_string = _string;
		return to_string(_str_string.size()).c_str();
	}
	const char* ls_string_replacestr(const char* _string,const char* _substr,const char* _repstr)
	{
		string _str_string = _string;
		string _str_substr = _substr;
		string _str_repstr = _repstr;
		return replace_all(_str_string,_str_substr,_str_repstr).c_str();
	}
	const char* ls_string_replacepos(const char* _string,const char* _spos,const char* _epos, const char* _substr)
	{
		string _str_string = _string;
		long _int_spos = atoi(_spos);
		long _int_epos = atoi(_epos);
		return _str_string.replace(_int_spos,_int_epos,_substr).c_str();
	}
	const char* ls_string_insert(const char* _string,const char* _pos,const char* _substr)
	{
		string _str_string = _string;
		long _int_pos = atoi(_pos);
		_str_string.insert(_int_pos,_substr);
	}
	const char* ls_string_erase(const char* _string,const char* _pos,const char* _len)
	{
		string _str_string = _string;
		long _int_pos = atoi(_pos);
		long _int_len = atoi(_len);
		if (_int_len < 0)
		{
			_str_string.erase(_int_pos);
			return _str_string.c_str();
		}
		_str_string.erase(_int_pos,_int_len);
		return _str_string.c_str();
	}
}
