#include "crt.bi"
extern "C"
dim shared size as long
dim shared now_size as long
dim shared _lin as long
dim shared _pos as long

declare function ls_bar_close() as string 

function ls_bar_next() as string export
	dim i as long
	now_size = now_size + 1
	if now_size > size then 
		ls_bar_close()
	end if
	_lin = csrlin
	if _lin = 1 then
		_lin = _lin + 1
	end if
	_pos = pos
	locate 1,1
	printf("[")
	for i = 0 to now_size
		printf("#")
	next 
	printf(space(size - now_size)&"] "&str(now_size)&"/"&str(size))
	locate _lin,_pos
	return ""
end function
function ls_bar_start(num as zstring) as string export
	size = val(num)
	now_size = 0
	_lin = csrlin
	if _lin = 1 then
		_lin = _lin + 1
	end if
	_pos = pos
	locate 1,1
	printf("["&space(size)&"] "&str(now_size)&"/"&str(size))
	locate _lin,_pos
	return ""
end function

function ls_bar_close() as string export
	_lin = 0
	_pos = 0
	size = 0
	now_size = 0
	return ""
end function

end extern
