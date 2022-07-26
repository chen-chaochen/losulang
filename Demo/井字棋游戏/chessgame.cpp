#include<iostream>
#include<string>
using namespace std;
extern "C"
{
	string board[10]={" "," "," "," "," "," "," "," "," "," "};
	const char* cg_board()
	{
		string _tmp;
		_tmp = board[1]+board[2]+board[3]+"\n"+board[4]+board[5]+board[6]+"\n"+board[7]+board[8]+board[9]+"\n";
		return _tmp.c_str();
	} 
	const char* cg_set(const char* _place,const char* _chess)
	{
		if(board[atoi(_place)] == " " && atoi(_place) <= 9 && atoi(_place) >= 1)
		{
			board[atoi(_place)] = _chess;
		}
		else
		{
			throw "洛书运行时错误：错误的走棋方式\n";
		}
		return "1";
	}
	const char* cg_ifend()
	{
		for(int i =1;i<=9;i++)
		{
			if(board[i] == " ")
			{
				return "0";
			}
		}
		return "1";
	}
	const char* cg_ifwin()
	{
		for(int i = 1;i <= 7;i = i+3)
		{
			if(board[i] == board[i+1] && board[i] == board[i+2] && board[i] != " ")
			{
				return board[i].c_str();
			}
		}
		for(int i = 1;i <= 3;i++)
		{
			if(board[i] == board[i+3] && board[i] == board[i+6] && board[i] != " ")
			{
				return board[i].c_str();
			}
		}
		if(board[1] == board[5] && board[1] == board[9] && board[1] != " ")
		{
			return board[1].c_str();
		}
		if(board[3] == board[5] && board[3] == board[7] && board[3] != " ")
		{
			return board[3].c_str();
		}
		if(cg_ifend() == "1")
		{
			return "-1";	
		} 
		return "0";
	}
}
