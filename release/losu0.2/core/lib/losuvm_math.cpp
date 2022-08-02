#include<iostream>
#include<string>
#include<math.h>
using namespace std;
extern "C"
{
	const char* ls_math_sin(const char* _num)
	{
		double _d_num = atof(_num);
		string _ret = to_string(sin(_d_num));
		return _ret.c_str();
	}
	const char* ls_math_cos(const char* _num)
	{
		double _d_num = atof(_num);
		string _ret = to_string(cos(_d_num));
		return _ret.c_str();
	}
	const char* ls_math_tan(const char* _num)
	{
		double _d_num = atof(_num);
		string _ret = to_string(tan(_d_num));
		return _ret.c_str();
	}
	const char* ls_math_asin(const char* _num)
	{
		double _d_num = atof(_num);
		string _ret = to_string(asin(_d_num));
		return _ret.c_str();
	}
	const char* ls_math_acos(const char* _num)
	{
		double _d_num = atof(_num);
		string _ret = to_string(acos(_d_num));
		return _ret.c_str();
	}
	const char* ls_math_atan2(const char* _num,const char* _num2)
	{
		double _d_num = atof(_num);
		double _d_num2 = atof(_num2);
		string _ret = to_string(atan2(_d_num,_d_num2));
		return _ret.c_str();
	}
	const char* ls_math_atan(const char* _num)
	{
		double _d_num = atof(_num);
		string _ret = to_string(atan(_d_num));
		return _ret.c_str();
	}
	const char* ls_math_sinh(const char* _num)
	{
		double _d_num = atof(_num);
		string _ret = to_string(sinh(_d_num));
		return _ret.c_str();
	}
	const char* ls_math_cosh(const char* _num)
	{
		double _d_num = atof(_num);
		string _ret = to_string(cosh(_d_num));
		return _ret.c_str();
	}
	const char* ls_math_tanh(const char* _num)
	{
		double _d_num = atof(_num);
		string _ret = to_string(tanh(_d_num));
		return _ret.c_str();
	}
	const char* ls_math_log(const char* _num)
	{
		double _d_num = atof(_num);
		string _ret = to_string(log(_d_num));
		return _ret.c_str();
	}
	const char* ls_math_log10(const char* _num)
	{
		double _d_num = atof(_num);
		string _ret = to_string(log10(_d_num));
		return _ret.c_str();
	}
	const char* ls_math_pow(const char* _num,const char* _num2)
	{
		double _d_num = atof(_num);
		double _d_num2 = atof(_num2);
		string _ret = to_string(pow(_d_num,_d_num2));
		return _ret.c_str();
	}
	const char* ls_math_exp(const char* _num)
	{
		double _d_num = atof(_num);
		string _ret = to_string(exp(_d_num));
		return _ret.c_str();
	}
	const char* ls_math_sqrt(const char* _num)
	{
		double _d_num = atof(_num);
		string _ret = to_string(sqrt(_d_num));
		return _ret.c_str();
	}
	const char* ls_math_ceil(const char* _num)
	{
		double _d_num = atof(_num);
		string _ret = to_string(ceil(_d_num));
		return _ret.c_str();
	}
	const char* ls_math_floor(const char* _num)
	{
		double _d_num = atof(_num);
		string _ret = to_string(floor(_d_num));
		return _ret.c_str();
	}
	const char* ls_math_fabs(const char* _num)
	{
		double _d_num = atof(_num);
		string _ret = to_string(fabs(_d_num));
		return _ret.c_str();
	}
	const char* ls_math_fmod(const char* _num,const char* _num2)
	{
		double _d_num = atof(_num);
		double _d_num2 = atof(_num2);
		string _ret = to_string(fmod(_d_num,_d_num2));
		return _ret.c_str();
	}
	const char* ls_math_hypot(const char* _num,const char* _num2)
	{
		double _d_num = atof(_num);
		double _d_num2 = atof(_num2);
		string _ret = to_string(hypot(_d_num,_d_num2));
		return _ret.c_str();
	}
	const char* ls_math_ldexp(const char* _num,const char* _num2)
	{
		double _d_num = atof(_num);
		long _d_num2 = atoi(_num2);
		string _ret = to_string(ldexp(_d_num,_d_num2));
		return _ret.c_str();
	}
}
