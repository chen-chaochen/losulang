#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
extern "C"
{
    string ls_gpio_export(const char* gpio)
    {
        ofstream _f;
        _f.open("/sys/class/gpio/export",ios::out);
        if(_f.is_open() == 0)
        {
            throw "洛书运行时错误:错误的引脚号\n";
        }
        _f<<gpio;
        _f.close();
        return "1";
    }
    string ls_gpio_unexport(const char* gpio)
    {
        ofstream _f;
        _f.open("/sys/class/gpio/unexport",ios::out);
        if(_f.is_open() == 0)
        {
            throw "洛书运行时错误:错误的引脚号\n";
        }
        _f<<gpio;
        _f.close();
        return "1";
    }
    string ls_gpio_model(const char* gpio,const char* model)
    {
        //model 0 == in ; 1 == out
        ofstream _f;
        string _gpio_file;
        string _gpio = gpio;
        _gpio_file = "/sys/class/gpio/gpio"+ _gpio +"/direction";
        vector<string> dir = {"in","out"};
        _f.open(_gpio_file.c_str(),ios::out);
        if(_f.is_open() == 0)
        {
            throw "洛书运行时错误:错误的端口号\n";
        }
        _f<<dir[atoi(model)];
        _f.close();
        return "1";
    }
    string ls_gpio_value(const char* gpio,const char* model)
    {
        //model 0 == low ; 1 == high
        ofstream _f;
        string _gpio_file;
        string _gpio = gpio;
        _gpio_file = "/sys/class/gpio/gpio"+ _gpio +"/value";
        _f.open(_gpio_file.c_str(),ios::out);
        if(_f.is_open() == 0)
        {
            throw "洛书运行时错误:错误的端口号\n";
        }
        _f<<atoi(model);
        _f.close();
        return "1";
    }
    string ls_gpio_read(const char* gpio)
    {
        int val;
        ifstream _f;
        string _gpio_file;
        string _gpio = gpio;
        _gpio_file = "/sys/class/gpio/gpio"+ _gpio +"/value";
        _f.open(_gpio_file.c_str());
        if(_f.is_open() == 0)
        {
            throw "洛书运行时错误:错误的端口号\n";
        }
        _f>>val;
        _f.close();
        return to_string(val);
    }
}
