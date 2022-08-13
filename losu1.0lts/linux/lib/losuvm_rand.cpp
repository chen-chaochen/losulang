#include <iostream>
#include <cstdlib>
#include <ctime>
#define random(a,b) (rand()%(b + 1 -a)+a) 

using namespace std;
extern "C"{

string ls_rand(const char* _begin,const char* _end)
{
	clock_t _t;
	_t = clock();
    srand(_t);  
    return to_string(random(atoi(_begin),atoi(_end)));
}
}
