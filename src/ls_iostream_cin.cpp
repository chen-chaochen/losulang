#include<iostream>
#include<string>
#include<string.h>
using namespace std;
extern "C"
{
	const char* ls_iostream_cin()
	{
		string a;
		cin>> a;
		return a.c_str();	
	}	
} 
