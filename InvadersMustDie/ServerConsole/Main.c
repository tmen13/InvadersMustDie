#include <Windows.h>
#include <tchar.h>
#include <io.h>
#include <fcntl.h>
#include <process.h>
#include <stdio.h>

#include "../GameLibrary/Core.h"
#include <time.h>

unsigned int __stdcall mythreadA(void* data)
{
	struct configuration aux = load_default_config();
	_tprintf(TEXT("Configuração:\n%ls"), config_to_string(aux));

}

int _tmain(int argc, TCHAR *argv[])
{
	srand(time(NULL));
#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stderr), _O_WTEXT);
#endif

	HANDLE myhandleA = (HANDLE)_beginthreadex(0, 0, &mythreadA, 0, CREATE_SUSPENDED, 0);
	system("Pause");
	ResumeThread(myhandleA);

	system("Pause");
	WaitForSingleObject(myhandleA, INFINITE);

	CloseHandle(myhandleA);

	return 0;
}
