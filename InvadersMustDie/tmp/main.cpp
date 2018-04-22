#include <Windows.h>
#include <tchar.h>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>

#include "..\..\..\repos\InvadersMustDie\GameLibrary\dll.h"

int _tmain(int argc, TCHAR *argv[])
{
#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stderr), _O_WTEXT);
#endif


	_tprintf(TEXT("Valor da variável da DLL: %d\n"), nDLL); //exports

	return 0;
}