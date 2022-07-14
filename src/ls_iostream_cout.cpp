#include<iostream>
#include<string>
#include<string.h>
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

	const char* ls_iostream_cout(const char* a)
	{
		cout<< trmate(a);
		return "";	
	}	
} 
