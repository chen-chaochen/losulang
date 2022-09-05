//Include StdC++ Head File
#include<iostream>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<graphics.h>
using namespace std;

//define

typedef string ls_io;
typedef const char* ls_post;
double ls_pi = 3.14159265358979323846;
//Delclare The Var
extern "C"
{
    int _ls_logo_x;
    int _ls_logo_nx;
    int _ls_logo_y;
    int _ls_logo_ny;
    int _ls_logo_arr;
    bool _ls_line;
    int _ls_logo_color[16] = \
    {\
        0,\
        0xAA0000,\
        0x00AA00,\
        0xAAAA00,\
        0x0000AA,\
        0xAA00AA,\
        0x0055AA,\
        0xAAAAAA,\
        0x555555,\
        0xFF5555,\
        0x55FF55,\
        0xFFFF55,\
        0x5555FF,\
        0xFF55FF,\
        0x55FFFF,\
        0xFFFFFF,\
    };
    vector<ls_io> _ls_logo_colorname = \
    {\
        "ºÚ",\
        "À¶",\
        "ÂÌ",\
        "Çà",\
        "ºì",\
        "×Ï",\
        "×Ø",\
        "Ç³»Ò",\
        "Éî»Ò",\
        "ÁÁÀ¶",\
        "ÁÁÂÌ",\
        "ÁÁÇà",\
        "ÁÁºì",\
        "ÁÁ×Ï",\
        "»Æ",\
        "°×"\
    };
    IMAGE _img_tmp;
    
}

//Function Export
extern "C"
{
    ls_io ls_logo_init(ls_post wid,ls_post hei);
    ls_io ls_logo_sbc(ls_post colorname);
    ls_io ls_logo_sbc_rgb(ls_post RGB);
    ls_io ls_logo_slc(ls_post colorname);
    ls_io ls_logo_slc_rgb(ls_post RGB);
    ls_io ls_logo_fd(ls_post step);    
    ls_io ls_logo_bd(ls_post step);
    ls_io ls_logo_home();
    ls_io ls_logo_tr(ls_post arr);
    ls_io ls_logo_tl(ls_post arr);
    ls_io ls_logo_cls();
    ls_io ls_logo_to();
    ls_io ls_logo_td();
    ls_io ls_logo_fill(ls_post colorname);
    ls_io ls_logo_fill_rgb(ls_post RGB);
    ls_io ls_logo_circle(ls_post r);
    ls_io ls_logo_ellipse(ls_post a,ls_post b);
    ls_io ls_logo_rect(ls_post wid,ls_post hei);
    ls_io ls_logo_dot();
    ls_io ls_logo_goto(ls_post x,ls_post y);
    ls_io ls_logo_saveimg(ls_post save_file);
    ls_io ls_logo_loadimg(ls_post load_file);
    ls_io ls_logo_resize(ls_post wid,ls_post hei);
    ls_io ls_logo_close();


}

//Included Function
extern "C"
{
    int _in_ls_rgb(ls_post RGB);
    int _in_ls_logo_color(ls_post colorname);
    double _in_ls_logo_sin(int arr);
    double _in_ls_logo_cos(int arr);
    void _in_ls_logo_line(int x1,int y1,int x2, int y2);
    ls_io _in_ls_mid(ls_io str,long start_pos,long len_pos);
}

//#include "losuvm_logo.hxx"
extern "C"
{
    ls_io ls_logo_init(ls_post wid,ls_post hei)
    {
        initgraph(atoi(wid),atoi(hei),3);
        ls_logo_sbc("°×");
        ls_logo_slc("ºÚ");
        cleardevice();
        _ls_logo_arr = 0;
        _ls_logo_x = atoi(wid) / 2;
        _ls_logo_y = atoi(hei) / 2;
        _ls_logo_nx = _ls_logo_x;
        _ls_logo_ny = _ls_logo_y;
        _ls_line = 1;
        return "1";
    }
    ls_io ls_logo_cls()
    {
        cleardevice();
        return "1";
    }
    ls_io ls_logo_sbc(ls_post colorname)
    {
        setbkcolor(_in_ls_logo_color(colorname));
        return "1";
    }
    ls_io ls_logo_sbc_rgb(ls_post RGB)
    {
        setbkcolor(_in_ls_rgb(RGB));
        return "1";
    }
    ls_io ls_logo_slc(ls_post colorname)
    {
        setlinecolor(_in_ls_logo_color(colorname));
        return "1";
    }
    ls_io ls_logo_slc_rgb(ls_post RGB)
    {
        setlinecolor(_in_ls_rgb(RGB));
        return "1";
    }
    ls_io ls_logo_fd(ls_post step)
    {
        double _step = atoi(step);
        //_ls_logo_nx_tmp = _ls_logo_nx + (_step * (_in_ls_logo_sin(_ls_logo_arr)));
        //_ls_logo_ny_tmp = _ls_logo_ny - (_step * (_in_ls_logo_cos(_ls_logo_arr)));
        int _ls_logo_nx_tmp,_ls_logo_ny_tmp;
        if (_ls_logo_arr>=0 && _ls_logo_arr <= 90)
        {
            _ls_logo_nx_tmp = _ls_logo_nx + (_step * (_in_ls_logo_sin(_ls_logo_arr)));
            _ls_logo_ny_tmp = _ls_logo_ny - (_step * (_in_ls_logo_cos(_ls_logo_arr)));
        }
        else if (_ls_logo_arr > 90 && _ls_logo_arr <= 180)
        {
            _ls_logo_nx_tmp = _ls_logo_nx + (_step * (_in_ls_logo_cos(_ls_logo_arr-90)));
            _ls_logo_ny_tmp = _ls_logo_ny + (_step * (_in_ls_logo_sin(_ls_logo_arr-90)));
        }
        else if (_ls_logo_arr>180 && _ls_logo_arr <= 270)
        {
            _ls_logo_nx_tmp = _ls_logo_nx - (_step * (_in_ls_logo_sin((_ls_logo_arr-180))));
            _ls_logo_ny_tmp = _ls_logo_ny + (_step * (_in_ls_logo_cos(_ls_logo_arr-180)));
        }
        else if (_ls_logo_arr > 270 && _ls_logo_arr <= 360)
        {
            _ls_logo_nx_tmp = _ls_logo_nx - (_step * (_in_ls_logo_cos(_ls_logo_arr-270)));
            _ls_logo_ny_tmp = _ls_logo_ny - (_step * (_in_ls_logo_sin(_ls_logo_arr-270)));
        }
        
        _in_ls_logo_line(_ls_logo_nx,_ls_logo_ny,_ls_logo_nx_tmp,_ls_logo_ny_tmp);
        _ls_logo_nx = _ls_logo_nx_tmp;
        _ls_logo_ny = _ls_logo_ny_tmp;
        return "1";
    }
    ls_io ls_logo_bd(ls_post step)
    {
        double _step = -atoi(step);
        //_ls_logo_nx_tmp = _ls_logo_nx + (_step * (_in_ls_logo_sin(_ls_logo_arr)));
        //_ls_logo_ny_tmp = _ls_logo_ny - (_step * (_in_ls_logo_cos(_ls_logo_arr)));
        int _ls_logo_nx_tmp,_ls_logo_ny_tmp;
        if (_ls_logo_arr>=0&&_ls_logo_arr<=90)
        {
            _ls_logo_nx_tmp = _ls_logo_nx + (_step * (_in_ls_logo_sin(_ls_logo_arr)));
            _ls_logo_ny_tmp = _ls_logo_ny - (_step * (_in_ls_logo_cos(_ls_logo_arr)));
        }
        else if (_ls_logo_arr>90&&_ls_logo_arr<=180)
        {
            _ls_logo_nx_tmp = _ls_logo_nx + (_step * (_in_ls_logo_cos(_ls_logo_arr-90)));
            _ls_logo_ny_tmp = _ls_logo_ny + (_step * (_in_ls_logo_sin(_ls_logo_arr-90)));
        }
        else if (_ls_logo_arr>180&&_ls_logo_arr<=270)
        {
            _ls_logo_nx_tmp = _ls_logo_nx - (_step * (_in_ls_logo_sin((_ls_logo_arr-180))));
            _ls_logo_ny_tmp = _ls_logo_ny + (_step * (_in_ls_logo_cos(_ls_logo_arr-180)));
        }
        else if (_ls_logo_arr>270&&_ls_logo_arr<=360)
        {
            _ls_logo_nx_tmp = _ls_logo_nx - (_step * (_in_ls_logo_sin(_ls_logo_arr-270)));
            _ls_logo_ny_tmp = _ls_logo_ny - (_step * (_in_ls_logo_cos(_ls_logo_arr-270)));
        }
        
        _in_ls_logo_line(_ls_logo_nx,_ls_logo_ny,_ls_logo_nx_tmp,_ls_logo_ny_tmp);
        _ls_logo_nx = _ls_logo_nx_tmp;
        _ls_logo_ny = _ls_logo_ny_tmp;
        return "1";
    }
    ls_io ls_logo_tr(ls_post arr)
    {
        _ls_logo_arr = _ls_logo_arr + atoi(arr);
        do
        {
            if (_ls_logo_arr < 360)
            {
                break;
            }
            _ls_logo_arr = _ls_logo_arr - 360;
        } while(1);
        return "1";
    }
    ls_io ls_logo_tl(ls_post arr)
    {
        _ls_logo_arr = _ls_logo_arr - atoi(arr);
        do
        {
            if (_ls_logo_arr > 0)
            {
                break;   
            }
            _ls_logo_arr = _ls_logo_arr + 360;
        } while (1);
        return "1";
    }
    ls_io ls_logo_to()
    {
        _ls_line = 0;
        return "1";
    }
    ls_io ls_logo_td()
    {
        _ls_line = 1;
        return "1";
    }
    ls_io ls_logo_home()
    {
        _ls_logo_nx = _ls_logo_x;
        _ls_logo_ny = _ls_logo_y;
        _ls_logo_arr = 0;
        _ls_line = 1;
        return "1";
    }
    ls_io ls_logo_fill(ls_post colorname)
    {
        setfillcolor(_in_ls_logo_color(colorname));
        floodfill(_ls_logo_nx,_ls_logo_ny,getlinecolor());
        return "1";
    }
    ls_io ls_logo_fill_rgb(ls_post RGB)
    {
        setfillcolor(_in_ls_rgb(RGB));
        floodfill(_ls_logo_nx,_ls_logo_ny,getlinecolor());
        return "1";
    }
    ls_io ls_logo_dot()
    {
        putpixel(_ls_logo_nx,_ls_logo_ny,getlinecolor());
        return "1";
    }
    ls_io ls_logo_ellipse(ls_post a,ls_post b)
    {
        ellipse(_ls_logo_nx-atoi(a),_ls_logo_ny-atoi(b),_ls_logo_nx+atoi(a),_ls_logo_ny+atoi(b));
        return "1";
    }
    ls_io ls_logo_circle(ls_post r)
    {
        circle(_ls_logo_nx,_ls_logo_ny,atoi(r));
        return "1";
    }
    ls_io ls_logo_goto(ls_post x,ls_post y)
    {
        _ls_logo_nx = atoi(x) + _ls_logo_x;
        _ls_logo_ny =  _ls_logo_y - atoi(y);
        return "1";
    }
    ls_io ls_logo_saveimg(ls_post save_file)
    {
        saveimage(save_file);
        return "1";
    }
    ls_io ls_logo_loadimg(ls_post load_file)
    {
        loadimage(&_img_tmp,load_file);
        putimage(0,0,&_img_tmp);
        return "1";
    }
    ls_io ls_logo_resize(ls_post wid,ls_post hei)
    {
        Resize(NULL,atoi(wid),atoi(hei));
        return "1";
    }
    ls_io ls_logo_close()
    {
        closegraph();
        return "1";
    }
    ls_io ls_logo_rect(ls_post wid,ls_post hei)
    {
        rectangle(_ls_logo_nx-(atoi(wid)/2),_ls_logo_ny-(atoi(hei)/2),_ls_logo_nx+(atoi(wid)/2),_ls_logo_ny+(atoi(hei)/2));
        return "1";
    }

}


extern "C"
{
    int _in_ls_rgb(ls_post tmp)
    {
        ls_io RGB = tmp;
        int R = atoi(_in_ls_mid(RGB,1,3).c_str());
        int G = atoi(_in_ls_mid(RGB,4,3).c_str());
        int B = atoi(_in_ls_mid(RGB,7,3).c_str());
        return RGB(R,G,B);
    }
    int _in_ls_logo_color(ls_post colorname)
    {
    	string _colorname = colorname;
        for (int i = 0; i < 16; i++)
        {
            if (_ls_logo_colorname[i]==_colorname)
            {
                return _ls_logo_color[i];
            }   
        }
        return 0;
    }
    double _in_ls_logo_sin(int arr)
    {
        return sin(arr * ls_pi / 180);
    }
    double _in_ls_logo_cos(int arr)
    {
        return cos(arr * ls_pi / 180);
    }
    void _in_ls_logo_line(int x1,int y1,int x2,int y2)
    {
        if (_ls_line == 1)
        {
            line(x1,y1,x2,y2);
        }
    }
    ls_io _in_ls_mid(ls_io a,long start_pos,long len_pos)
    {
        if (start_pos > a.length())
        {
            return "";
        }
	    return a.substr(start_pos - 1,len_pos);
    }

}

