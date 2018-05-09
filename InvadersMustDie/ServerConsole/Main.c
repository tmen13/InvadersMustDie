#include <Windows.h>
#include <tchar.h>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>

#include "../GameLibrary/Core.h"
#include <time.h>

int _tmain(int argc, TCHAR *argv[])
{
	srand(time(NULL));

#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stderr), _O_WTEXT);
#endif
	for (int i = 0; i < 10; i++)
	{
		const struct powerup ajux = get_powerup();

		_tprintf(TEXT("power up: %hs\n"), powerup_type_string[ajux.type]);
	}

	system("Pause");

	return 0;
}
