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
	//const struct powerup ajux = get_powerup();
	//struct field field;
	BOOL teste = TRUE;
	//field.config = load_default_config();
	//field.config.base_lifes = 13;
	//save_config_file(field.config, (char *)"teste");

	//struct configuration aux = load_config_file("teste");
	_tprintf(TEXT("power up: %d\n"), teste);

	//_tprintf(TEXT("power up: %hs\n"), powerup_type_string[ajux.type]);

	//_tprintf(TEXT("Configuração:\n%ls"), config_to_string(aux));

	system("Pause");

	return 0;
}
