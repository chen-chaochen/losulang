#include "crt.bi"
#include "file.bi"
extern "C"
Function replace(a As String, B As String, c As String) As String
    Dim i As Double
    Dim rep As String
    i = 1
    rep = ""
    Do
        If Mid(a, i, len(B)) = B Then
            i = i + len(B) - 1
            rep = rep & c
        Else
            rep = rep & Mid(a, i, 1)
        End If
        i = i + 1
        If i > len(a) Then
            rep = rep & Mid(a, i, 1)
            Exit Do
        End If
    Loop
    Return rep
End Function
function ls_sys_system(_num as zstring) as string export
dim _str_num as string
system(val(_str_num))
return ""
end function
function ls_sys_shell(_cmd as zstring) as string export
dim _str_cmd as string
_str_cmd = _cmd
shell(_str_cmd)
return ""
end function 
function ls_sys_rename(_sname as zstring, _oname as zstring) as string export
dim _str_sname as string
dim _str_oname as string
_str_sname = _sname
_str_oname = _oname
name _str_sname,_str_oname
return ""
end function
function ls_sys_rmdir(_dir as zstring) as string export
dim _str_dir as string
_str_dir = _dir
rmdir _str_dir
return ""
end function
function ls_sys_rmfile(_file as zstring) as string export
dim _str_file as string
_str_file = _file
kill _str_file
return ""
end function
function ls_sys_mkdir(_dir as zstring) as string export
dim _str_dir as string
_str_dir = _dir
mkdir _str_dir
return ""
end function
function ls_sys_sleep(_time as zstring) as string export
	dim _str_time as string 
	_str_time = _time
	sleep val(_str_time),1
	return ""
end function
function ls_sys_exec(_exename as zstring,_cmd as zstring ) as string export
dim _str_exename as string
dim _str_cmd as string
_str_exename = _exename
_str_cmd = _cmd
	exec _str_exename,_str_cmd
	return ""
end function
function ls_sys_copyfile(_sfile as zstring ,_efile as zstring) as string export
dim _str_sfile as string
dim _str_efile as string
_str_efile = _efile
_str_sfile = _sfile
	filecopy(_str_sfile,_str_efile)
	return ""
end function
function ls_cli_pause() as string export
	sleep -1,0
	return "" 
end function
function ls_cli_cls() as string export
	cls
	return ""
end function
function ls_cli_setview(_line as zstring,_row as zstring) as string
dim _str_line as string
dim _str_row as string
view print vallng(_str_line) to vallng(_str_row)
return ""
end function
function ls_cli_color(_forecolor as zstring,_backcolor as zstring ) as string export
	color val(_forecolor),val(_backcolor)
	return ""
end function
function ls_cli_printf(_pass as zstring) as string export
dim _str_pass as string
_str_pass = _pass
printf(replace(_str_pass,"\n",chr(10)))
return ""
end function
function ls_cli_locate(_line as zstring,_row as zstring ) as string export
	locate val(_line),val(_row)
	return ""
end function
end extern
