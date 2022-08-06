#include<iostream>
#include<string>
#include<time.h>
using namespace std;

extern "C"
{
	const char* ls_time_clock()
	{
		clock_t _t;
		_t = clock();
		string _str = to_string(_t); 
		return _str.c_str();
	}
	const char* ls_time_localtime_mon()
	{
		
		time_t _t_ptr;
		struct tm *_t ;
		time(&_t_ptr);
		_t = localtime(&_t_ptr);
		int _mon = _t -> tm_mon;
		string _rt = to_string(_mon + 1);
		return _rt.c_str();
	}
	
	const char* ls_time_localtime_mday()
	{
		
		time_t _t_ptr;
		struct tm *_t ;
		time(&_t_ptr);
		_t = localtime(&_t_ptr);
		int _mnday = _t -> tm_mday;
		string _rt = to_string(_mnday); 
		return _rt.c_str();
	}
	string ls_time_localtime_mdays()
	{
		
		time_t _t_ptr;
		struct tm *_t ;
		time(&_t_ptr);
		_t = localtime(&_t_ptr);
		int _mnday = _t -> tm_mday;
		string _rt = to_string(_mnday); 
		return _rt;
	}
	const char* ls_time_localtime_hour()
	{
		
		time_t _t_ptr;
		struct tm *_t ;
		time(&_t_ptr);
		_t = localtime(&_t_ptr);
		int _hour = _t -> tm_hour;
		string _rt = to_string(_hour);
		return _rt.c_str();
	}
	const char* ls_time_localtime_min()
	{
		
		time_t _t_ptr;
		struct tm *_t ;
		time(&_t_ptr);
		_t = localtime(&_t_ptr);
		int _min = _t -> tm_min;
		string _rt = to_string(_min);
		return _rt.c_str();
	}
	const char* ls_time_localtime_sec()
	{
		
		time_t _t_ptr;
		struct tm *_t ;
		time(&_t_ptr);
		_t = localtime(&_t_ptr);
		int _sec = _t -> tm_sec;
		string _rt = to_string(_sec);
		return _rt.c_str();
	}
	const char* ls_time_localtime_year()
	{
		
		time_t _t_ptr;
		struct tm *_t ;
		time(&_t_ptr);
		_t = localtime(&_t_ptr);
		int _year = _t -> tm_year;
		string _rt = to_string(_year + 1900);
		return _rt.c_str();
	}
	const char* ls_time_localtime_wday()
	{
		
		time_t _t_ptr;
		struct tm *_t ;
		time(&_t_ptr);
		_t = localtime(&_t_ptr);
		int _wday = _t -> tm_wday;
		string _rt = to_string(_wday);
		return _rt.c_str();
	}
	const char* ls_time_localtime_yday()
	{
		
		time_t _t_ptr;
		struct tm *_t ;
		time(&_t_ptr);
		_t = localtime(&_t_ptr);
		int _yday = _t -> tm_yday;
		string _rt = to_string(_yday);
		return _rt.c_str();
	}
	const char* ls_time_localtime_isdst()
	{
		
		time_t _t_ptr;
		struct tm *_t ;
		time(&_t_ptr);
		_t = localtime(&_t_ptr);
		int _isdst = _t -> tm_isdst;
		string _rt = to_string(_isdst);
		return _rt.c_str();
	}
	const char* ls_time_ctime()
	{
		string _day_[8] = {"0","周一","周二","周三","周四","周五","周六","周日"};
		int _pos = atoi(ls_time_localtime_wday());
		string _rt;
		string _rt_year = ls_time_localtime_year();
		string _rt_mon = ls_time_localtime_mon();
		string _rt_mdays = ls_time_localtime_mdays();
		string _rt_hour = ls_time_localtime_hour();
		string _rt_min = ls_time_localtime_min();
		string _rt_sec = ls_time_localtime_sec();
		_rt = _day_[_pos];
		_rt = _rt + "  "  + _rt_year + "年" + _rt_mon + "月" + _rt_mdays +  "日  " + _rt_hour + "时" + _rt_min + "分" + _rt_sec + "秒"; 
		return _rt.c_str();
	}
} 
