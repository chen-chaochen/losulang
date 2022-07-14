typedef   signed char       int8;
typedef unsigned char      uint8;
typedef   signed short      int16;
typedef unsigned short     uint16;
typedef   signed int        int32;
typedef unsigned int       uint32;
typedef   signed long long  int64;
typedef unsigned long long uint64;
typedef struct { char *data; int64 len; int64 size; } lsSTRING;
typedef int8 boolean;
#define ls_D2I( value ) ((int32)__builtin_nearbyint( value ))
#define ls_D2L( value ) ((int64)__builtin_nearbyint( value ))
int32 ls_ConsoleView( int32, int32 );
int32 ls_Locate( int32, int32, int32, int32, int32 );
void ls_Cls( int32 );
int32 ls_Color( int32, int32, int32 );
int32 rename( uint8*, uint8* );
int32 ls_FileKill( lsSTRING* );
lsSTRING* ls_StrInit( void*, int64, void*, int64, int32 );
lsSTRING* ls_StrAssign( void*, int64, void*, int64, int32 );
void ls_StrDelete( lsSTRING* );
lsSTRING* ls_StrConcat( lsSTRING*, void*, int64, void*, int64 );
int32 ls_StrCompare( void*, int64, void*, int64 );
lsSTRING* ls_StrAllocTempResult( lsSTRING* );
lsSTRING* ls_StrAllocTempDescZ( uint8* );
lsSTRING* ls_StrMid( lsSTRING*, int64, int64 );
int64 ls_StrLen( void*, int64 );
double ls_VAL( lsSTRING* );
int64 ls_VALLNG( lsSTRING* );
int32 ls_Shell( lsSTRING* );
void ls_End( int32 );
int32 ls_Exec( lsSTRING*, lsSTRING* );
int32 ls_SleepEx( int32, int32 );
int32 ls_MkDir( lsSTRING* );
int32 ls_RmDir( lsSTRING* );
static void ls_ctor__losuvm( void ) __attribute__(( constructor ));
int32 ls_FileCopy( uint8*, uint8* );

lsSTRING* replace( lsSTRING* a, lsSTRING* B, lsSTRING* c )
{
	lsSTRING ls$result;
	__builtin_memset( &ls$result, 0, 24ll );
	label2:;
	double i;
	__builtin_memset( &i, 0, 8ll );
	lsSTRING rep;
	__builtin_memset( &rep, 0, 24ll );
	i = 0x1.p+0;
	ls_StrAssign( (void*)&rep, -1ll, (void*)"", 1ll, 0 );
	label4:;
	{
		int64 vr$4 = ls_StrLen( (void*)B, -1ll );
		lsSTRING* vr$6 = ls_StrMid( (lsSTRING*)a, ls_D2L( i ), vr$4 );
		int32 vr$7 = ls_StrCompare( (void*)vr$6, -1ll, (void*)B, -1ll );
		if( (int64)vr$7 != 0ll ) goto label8;
		{
			lsSTRING tmp$7;
			int64 vr$9 = ls_StrLen( (void*)B, -1ll );
			i = (i + (double)vr$9) + -0x1.p+0;
			__builtin_memset( &tmp$7, 0, 24ll );
			lsSTRING* vr$16 = ls_StrConcat( &tmp$7, (void*)&rep, -1ll, (void*)c, -1ll );
			ls_StrAssign( (void*)&rep, -1ll, (void*)vr$16, -1ll, 0 );
		}
		goto label7;
		label8:;
		{
			lsSTRING tmp$8;
			lsSTRING* vr$19 = ls_StrMid( (lsSTRING*)a, ls_D2L( i ), 1ll );
			__builtin_memset( &tmp$8, 0, 24ll );
			lsSTRING* vr$23 = ls_StrConcat( &tmp$8, (void*)&rep, -1ll, (void*)vr$19, -1ll );
			ls_StrAssign( (void*)&rep, -1ll, (void*)vr$23, -1ll, 0 );
		}
		label7:;
		i = i + 0x1.p+0;
		int64 vr$26 = ls_StrLen( (void*)a, -1ll );
		if( i <= (double)vr$26 ) goto label10;
		{
			lsSTRING tmp$9;
			lsSTRING* vr$29 = ls_StrMid( (lsSTRING*)a, ls_D2L( i ), 1ll );
			__builtin_memset( &tmp$9, 0, 24ll );
			lsSTRING* vr$33 = ls_StrConcat( &tmp$9, (void*)&rep, -1ll, (void*)vr$29, -1ll );
			ls_StrAssign( (void*)&rep, -1ll, (void*)vr$33, -1ll, 0 );
			goto label5;
		}
		label10:;
		label9:;
	}
	label6:;
	goto label4;
	label5:;
	ls_StrInit( (void*)&ls$result, -1ll, (void*)&rep, -1ll, 0 );
	ls_StrDelete( (lsSTRING*)&rep );
	goto label3;
	ls_StrDelete( (lsSTRING*)&rep );
	label3:;
	lsSTRING* vr$40 = ls_StrAllocTempResult( (lsSTRING*)&ls$result );
	return vr$40;
}

lsSTRING* ls_sys_system( uint8* _num )
{
	lsSTRING ls$result;
	__builtin_memset( &ls$result, 0, 24ll );
	label11:;
	lsSTRING _str_num;
	__builtin_memset( &_str_num, 0, 24ll );
	double vr$3 = ls_VAL( (lsSTRING*)&_str_num );
	ls_End( ls_D2I( vr$3 ) );
	ls_StrInit( (void*)&ls$result, -1ll, (void*)"", 1ll, 0 );
	ls_StrDelete( (lsSTRING*)&_str_num );
	goto label12;
	ls_StrDelete( (lsSTRING*)&_str_num );
	label12:;
	lsSTRING* vr$9 = ls_StrAllocTempResult( (lsSTRING*)&ls$result );
	return vr$9;
}

lsSTRING* ls_sys_shell( uint8* _cmd )
{
	lsSTRING ls$result;
	__builtin_memset( &ls$result, 0, 24ll );
	label13:;
	lsSTRING _str_cmd;
	__builtin_memset( &_str_cmd, 0, 24ll );
	ls_StrAssign( (void*)&_str_cmd, -1ll, (void*)_cmd, 0ll, 0 );
	ls_Shell( (lsSTRING*)&_str_cmd );
	ls_StrInit( (void*)&ls$result, -1ll, (void*)"", 1ll, 0 );
	ls_StrDelete( (lsSTRING*)&_str_cmd );
	goto label14;
	ls_StrDelete( (lsSTRING*)&_str_cmd );
	label14:;
	lsSTRING* vr$8 = ls_StrAllocTempResult( (lsSTRING*)&ls$result );
	return vr$8;
}

lsSTRING* ls_sys_rename( uint8* _sname, uint8* _oname )
{
	lsSTRING ls$result;
	__builtin_memset( &ls$result, 0, 24ll );
	label15:;
	lsSTRING _str_sname;
	__builtin_memset( &_str_sname, 0, 24ll );
	lsSTRING _str_oname;
	__builtin_memset( &_str_oname, 0, 24ll );
	ls_StrAssign( (void*)&_str_sname, -1ll, (void*)_sname, 0ll, 0 );
	ls_StrAssign( (void*)&_str_oname, -1ll, (void*)_oname, 0ll, 0 );
	rename( (uint8*)*(uint8**)&_str_sname, (uint8*)*(uint8**)&_str_oname );
	ls_StrInit( (void*)&ls$result, -1ll, (void*)"", 1ll, 0 );
	ls_StrDelete( (lsSTRING*)&_str_oname );
	ls_StrDelete( (lsSTRING*)&_str_sname );
	goto label16;
	ls_StrDelete( (lsSTRING*)&_str_oname );
	ls_StrDelete( (lsSTRING*)&_str_sname );
	label16:;
	lsSTRING* vr$11 = ls_StrAllocTempResult( (lsSTRING*)&ls$result );
	return vr$11;
}

lsSTRING* ls_sys_rmdir( uint8* _dir )
{
	lsSTRING ls$result;
	__builtin_memset( &ls$result, 0, 24ll );
	label17:;
	lsSTRING _str_dir;
	__builtin_memset( &_str_dir, 0, 24ll );
	ls_StrAssign( (void*)&_str_dir, -1ll, (void*)_dir, 0ll, 0 );
	ls_RmDir( (lsSTRING*)&_str_dir );
	ls_StrInit( (void*)&ls$result, -1ll, (void*)"", 1ll, 0 );
	ls_StrDelete( (lsSTRING*)&_str_dir );
	goto label18;
	ls_StrDelete( (lsSTRING*)&_str_dir );
	label18:;
	lsSTRING* vr$8 = ls_StrAllocTempResult( (lsSTRING*)&ls$result );
	return vr$8;
}

lsSTRING* ls_sys_rmfile( uint8* _file )
{
	lsSTRING ls$result;
	__builtin_memset( &ls$result, 0, 24ll );
	label19:;
	lsSTRING _str_file;
	__builtin_memset( &_str_file, 0, 24ll );
	ls_StrAssign( (void*)&_str_file, -1ll, (void*)_file, 0ll, 0 );
	ls_FileKill( (lsSTRING*)&_str_file );
	ls_StrInit( (void*)&ls$result, -1ll, (void*)"", 1ll, 0 );
	ls_StrDelete( (lsSTRING*)&_str_file );
	goto label20;
	ls_StrDelete( (lsSTRING*)&_str_file );
	label20:;
	lsSTRING* vr$8 = ls_StrAllocTempResult( (lsSTRING*)&ls$result );
	return vr$8;
}

lsSTRING* ls_sys_mkdir( uint8* _dir )
{
	lsSTRING ls$result;
	__builtin_memset( &ls$result, 0, 24ll );
	label21:;
	lsSTRING _str_dir;
	__builtin_memset( &_str_dir, 0, 24ll );
	ls_StrAssign( (void*)&_str_dir, -1ll, (void*)_dir, 0ll, 0 );
	ls_MkDir( (lsSTRING*)&_str_dir );
	ls_StrInit( (void*)&ls$result, -1ll, (void*)"", 1ll, 0 );
	ls_StrDelete( (lsSTRING*)&_str_dir );
	goto label22;
	ls_StrDelete( (lsSTRING*)&_str_dir );
	label22:;
	lsSTRING* vr$8 = ls_StrAllocTempResult( (lsSTRING*)&ls$result );
	return vr$8;
}

lsSTRING* ls_sys_sleep( uint8* _time )
{
	lsSTRING ls$result;
	__builtin_memset( &ls$result, 0, 24ll );
	label23:;
	lsSTRING _str_time;
	__builtin_memset( &_str_time, 0, 24ll );
	ls_StrAssign( (void*)&_str_time, -1ll, (void*)_time, 0ll, 0 );
	double vr$4 = ls_VAL( (lsSTRING*)&_str_time );
	ls_SleepEx( ls_D2I( vr$4 ), 1 );
	ls_StrInit( (void*)&ls$result, -1ll, (void*)"", 1ll, 0 );
	ls_StrDelete( (lsSTRING*)&_str_time );
	goto label24;
	ls_StrDelete( (lsSTRING*)&_str_time );
	label24:;
	lsSTRING* vr$10 = ls_StrAllocTempResult( (lsSTRING*)&ls$result );
	return vr$10;
}

lsSTRING* ls_sys_exec( uint8* _exename, uint8* _cmd )
{
	lsSTRING ls$result;
	__builtin_memset( &ls$result, 0, 24ll );
	label25:;
	lsSTRING _str_exename;
	__builtin_memset( &_str_exename, 0, 24ll );
	lsSTRING _str_cmd;
	__builtin_memset( &_str_cmd, 0, 24ll );
	ls_StrAssign( (void*)&_str_exename, -1ll, (void*)_exename, 0ll, 0 );
	ls_StrAssign( (void*)&_str_cmd, -1ll, (void*)_cmd, 0ll, 0 );
	ls_Exec( (lsSTRING*)&_str_exename, (lsSTRING*)&_str_cmd );
	ls_StrInit( (void*)&ls$result, -1ll, (void*)"", 1ll, 0 );
	ls_StrDelete( (lsSTRING*)&_str_cmd );
	ls_StrDelete( (lsSTRING*)&_str_exename );
	goto label26;
	ls_StrDelete( (lsSTRING*)&_str_cmd );
	ls_StrDelete( (lsSTRING*)&_str_exename );
	label26:;
	lsSTRING* vr$13 = ls_StrAllocTempResult( (lsSTRING*)&ls$result );
	return vr$13;
}

lsSTRING* ls_sys_copyfile( uint8* _sfile, uint8* _efile )
{
	lsSTRING ls$result;
	__builtin_memset( &ls$result, 0, 24ll );
	label27:;
	lsSTRING _str_sfile;
	__builtin_memset( &_str_sfile, 0, 24ll );
	lsSTRING _str_efile;
	__builtin_memset( &_str_efile, 0, 24ll );
	ls_StrAssign( (void*)&_str_efile, -1ll, (void*)_efile, 0ll, 0 );
	ls_StrAssign( (void*)&_str_sfile, -1ll, (void*)_sfile, 0ll, 0 );
	ls_FileCopy( (uint8*)*(uint8**)&_str_sfile, (uint8*)*(uint8**)&_str_efile );
	ls_StrInit( (void*)&ls$result, -1ll, (void*)"", 1ll, 0 );
	ls_StrDelete( (lsSTRING*)&_str_efile );
	ls_StrDelete( (lsSTRING*)&_str_sfile );
	goto label28;
	ls_StrDelete( (lsSTRING*)&_str_efile );
	ls_StrDelete( (lsSTRING*)&_str_sfile );
	label28:;
	lsSTRING* vr$11 = ls_StrAllocTempResult( (lsSTRING*)&ls$result );
	return vr$11;
}

lsSTRING* ls_cli_pause( void )
{
	lsSTRING ls$result;
	__builtin_memset( &ls$result, 0, 24ll );
	label29:;
	ls_SleepEx( -1, 0 );
	ls_StrInit( (void*)&ls$result, -1ll, (void*)"", 1ll, 0 );
	goto label30;
	label30:;
	lsSTRING* vr$3 = ls_StrAllocTempResult( (lsSTRING*)&ls$result );
	return vr$3;
}

lsSTRING* ls_cli_cls( void )
{
	lsSTRING ls$result;
	__builtin_memset( &ls$result, 0, 24ll );
	label31:;
	ls_Cls( -65536 );
	ls_StrInit( (void*)&ls$result, -1ll, (void*)"", 1ll, 0 );
	goto label32;
	label32:;
	lsSTRING* vr$3 = ls_StrAllocTempResult( (lsSTRING*)&ls$result );
	return vr$3;
}

lsSTRING* ls_cli_setview( uint8* _line, uint8* _row )
{
	lsSTRING ls$result;
	__builtin_memset( &ls$result, 0, 24ll );
	label33:;
	lsSTRING _str_line;
	__builtin_memset( &_str_line, 0, 24ll );
	lsSTRING _str_row;
	__builtin_memset( &_str_row, 0, 24ll );
	int64 vr$4 = ls_VALLNG( (lsSTRING*)&_str_row );
	int64 vr$7 = ls_VALLNG( (lsSTRING*)&_str_line );
	ls_ConsoleView( (int32)vr$7, (int32)vr$4 );
	ls_StrInit( (void*)&ls$result, -1ll, (void*)"", 1ll, 0 );
	ls_StrDelete( (lsSTRING*)&_str_row );
	ls_StrDelete( (lsSTRING*)&_str_line );
	goto label34;
	ls_StrDelete( (lsSTRING*)&_str_row );
	ls_StrDelete( (lsSTRING*)&_str_line );
	label34:;
	lsSTRING* vr$15 = ls_StrAllocTempResult( (lsSTRING*)&ls$result );
	return vr$15;
}

lsSTRING* ls_cli_color( uint8* _forecolor, uint8* _backcolor )
{
	lsSTRING ls$result;
	__builtin_memset( &ls$result, 0, 24ll );
	label35:;
	lsSTRING* vr$1 = ls_StrAllocTempDescZ( (uint8*)_backcolor );
	double vr$2 = ls_VAL( (lsSTRING*)vr$1 );
	lsSTRING* vr$4 = ls_StrAllocTempDescZ( (uint8*)_forecolor );
	double vr$5 = ls_VAL( (lsSTRING*)vr$4 );
	ls_Color( ls_D2I( vr$5 ), ls_D2I( vr$2 ), 0 );
	ls_StrInit( (void*)&ls$result, -1ll, (void*)"", 1ll, 0 );
	goto label36;
	label36:;
	lsSTRING* vr$9 = ls_StrAllocTempResult( (lsSTRING*)&ls$result );
	return vr$9;
}

lsSTRING* ls_cli_locate( uint8* _line, uint8* _row )
{
	lsSTRING ls$result;
	__builtin_memset( &ls$result, 0, 24ll );
	label37:;
	lsSTRING* vr$1 = ls_StrAllocTempDescZ( (uint8*)_row );
	double vr$2 = ls_VAL( (lsSTRING*)vr$1 );
	lsSTRING* vr$4 = ls_StrAllocTempDescZ( (uint8*)_line );
	double vr$5 = ls_VAL( (lsSTRING*)vr$4 );
	ls_Locate( ls_D2I( vr$5 ), ls_D2I( vr$2 ), -1, 0, 0 );
	ls_StrInit( (void*)&ls$result, -1ll, (void*)"", 1ll, 0 );
	goto label38;
	label38:;
	lsSTRING* vr$9 = ls_StrAllocTempResult( (lsSTRING*)&ls$result );
	return vr$9;
}

static const char __attribute__((used, section(".lsctinf"))) __lsctinf[] = "-l\0msvcrt";

__asm__( 
	".section .drectve\n"
	"\t.ascii \" -export:\\\"ls_sys_system\\\"\"\n"
	"\t.ascii \" -export:\\\"ls_sys_shell\\\"\"\n"
	"\t.ascii \" -export:\\\"ls_sys_rename\\\"\"\n"
	"\t.ascii \" -export:\\\"ls_sys_rmdir\\\"\"\n"
	"\t.ascii \" -export:\\\"ls_sys_rmfile\\\"\"\n"
	"\t.ascii \" -export:\\\"ls_sys_mkdir\\\"\"\n"
	"\t.ascii \" -export:\\\"ls_sys_sleep\\\"\"\n"
	"\t.ascii \" -export:\\\"ls_sys_exec\\\"\"\n"
	"\t.ascii \" -export:\\\"ls_sys_copyfile\\\"\"\n"
	"\t.ascii \" -export:\\\"ls_cli_pause\\\"\"\n"
	"\t.ascii \" -export:\\\"ls_cli_cls\\\"\"\n"
	"\t.ascii \" -export:\\\"ls_cli_color\\\"\"\n"
	"\t.ascii \" -export:\\\"ls_cli_locate\\\"\"\n"
);
__asm__( ".text" );
