int linenum,loopnum,ifnum,threadnum,open_sign_num,close_sign_num;
string mainfile,outfile,classlib,objlib,outtmp,_outfile;
ifstream fs_in;
ofstream fs_out;
class lsc
{
    public:
    void compile(string _file);
    void makefile(string _endsign,string _valfore,string _extends); 
    string findclass(string _classname);
    string findclass_exp(string _classname);
    void ana_math_exp(string _exp,string _valfore);
    void includelib(string _libname);
    void addlib(string _libname);
    void loadlib(string _falib,string _sonlib);
    string get_formate(string _exp);
    void backfast(string _srcfile,string _outfile);
};
