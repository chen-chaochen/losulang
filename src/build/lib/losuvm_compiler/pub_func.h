//Declare Val

int main_argc;
const char** main_argv;
int max_path = 32000;


//Declare Function
string replace_all(string src, string old_value,string new_value);
string curdir();
string command();
string mid(string a,long b,long c);
string trmate(string a);
string _trmate(string a);
int val_int(string a);
double val(string a);
int ls_asc(char a);
string ls_endl();
string str_sign_34();
string str_sign_92();




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
string _trmate(string a)
{
	string b = " ";
	string c = replace_all(a,b,"|空格|");
    return c;
}
string trmate(string a)
{
    string b,c,d;
    b = "|换行|";
    c = "|空格|";
    d = replace_all(a,b,ls_endl());
    d = replace_all(d,c," ");
	return d;
}
double val(string a)
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
