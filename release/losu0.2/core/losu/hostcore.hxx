vector<string> vaname; 
vector<string> vavalue; 
vector<string> arrayname;
vector< vector<string> > array_mem;
void cthread(string _thname);
void create_new_th(string _th_name);
void array_start();
void array_new(string a);
void array_set(string a,long b,string c);
string array_get(string a,long b);
void array_clear(string a);
string getcsip();

class ls_vm
{
    public:
        int conf = 0;
        string csip;
        const char* _csip;
        ifstream _fin;
        vector<string> stack;
        int _stack_top;
        void start();
        void clear_st();
        void push(string a);
        void pop();
        string top();
        void add(string vname);
        void mov(string vname);
        void clear(string vname);
        void get_csip();
        string lvm(const char* _vm,const char* _func);
        string lsi(const char* _vm);
        string lei(const char* _vm,const char* _func);
        void hostfile(string _file,string _sign);
        void goto_ip(const char* _ip);
        const char* _nextip();
        string api(string apiname);
};
