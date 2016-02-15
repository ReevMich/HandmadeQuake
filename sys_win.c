#include "winquake.h"
#include "quakedef.h"

//////////////////////////////////////////////////////////////////////////
/*
CALLBACK WinMain() => the entry point to a windows application
*/
//////////////////////////////////////////////////////////////////////////
int32 CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int32 nCmdShow)
{ 
	COM_ParseCommandLine(lpCmdLine);
	// int32 test = COM_CheckParm("-setalpha");
	// int32 value = Q_atoi(com_argv[test+1]);
	return 0;
} 