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
string trmate(const char* a);
string _trmate(const char* a);
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
string curdir()
{
	//返回值示例 D:\source
	string a;
	const char* _a;
	char b[max_path];
 	getcwd(b,max_path);
	_a = b;
	a = _a;
	a = a + "/";
	return a;	
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
    string c,d;
    c = str_sign_92() + "N";
    d = replace_all(d," ",c);
	return d;
}
string trmate(string a)
{
    string b,c,d;
    b = str_sign_92() + "n";
    c = str_sign_92() + "N";
    d = replace_all(a,b,ls_endl());
    d = replace_all(d,c," ");
	return d;
}
string _trmate(const char* a)
{
    string c,d,e;
	e = a;
    c = str_sign_92() + "N";
    d = replace_all(e," ",c);
	return d;
}
string trmate(const char* a)
{
    string b,c,d,e;
	e = a;
    b = str_sign_92() + "n";
    c = str_sign_92() + "N";
    d = replace_all(e,b,ls_endl());
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
