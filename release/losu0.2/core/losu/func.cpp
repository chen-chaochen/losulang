string trmate(string a)
{
    return a;
}
long double val(string a)
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
void ls_sleep(long ms)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
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
string tostring(double a)
{
    string _tmp = to_string(a);
    string _int_sub,_double_sub;
    int _pos,_pos_e;
    int conf =0;
	for (int i = 1; i <= _tmp.length(); i++)
    {
        if (mid(_tmp,i,1) == ".")
        {
            conf = 1;
            _pos = i;
            break;
        }
    }
    _int_sub = mid(_tmp,1,_pos);
    if (conf == 0)
    {
        return _int_sub;
    }
    for (int i = _tmp.length(); i > _pos; i--)
    {
        if (mid(_tmp,i,1) != "0")
        {
            _pos_e = i;
            break;
        }
    }
    _double_sub = mid(_tmp,_pos + 1,_pos_e - _pos);
    if (atoi(_double_sub.c_str()) == 0)
    {
        return to_string(atoi(_tmp.c_str()));
    }
    return _int_sub + _double_sub.c_str();
}

