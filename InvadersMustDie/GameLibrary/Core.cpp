#define DLL_EXPORT

#include "Core.h"
#include "Constants.h"
#include <cstdlib>

#include "fstream"
#include <sys/stat.h>
#include <atlstr.h>
#include <string> 
#include <sstream> 

using namespace std;
//Para verificar ao carregar a dll que a aplicação irá ocupar mais memória
char ponteiro[40960];

inline bool file_exists(const std::string& name) {
	struct stat buffer;
	return stat(name.c_str(), &buffer) == 0;
}

struct invader set_invader(const invader_type type)
{
	struct invader aux {};

	switch (type)
	{
	case basic:
		aux.cooldown = 3000; //the invader must wait 3 seconds before it can make another move
		aux.fire_rate = 3; // for each 3 moviments, the invader shoots
		aux.lp = 1;
		aux.type = type;
		aux.pace = 1; //moves 1 field for each 3 seconds passed
		aux.movement = linear; //moves linearly (right or left)
		break;
	case dodger:
		aux.cooldown = 1000; // 1 second
		aux.fire_rate = 3; // for each 3 moviments, the invader shoots
		aux.lp = 1;
		aux.type = type;
		aux.pace = 2;
		aux.movement = random;
		break;
	case boss:
		aux.cooldown = 4000;
		aux.fire_rate = 1; // for each moviment, the invader shoots
		aux.lp = 5;
		aux.type = type;
		aux.pace = 1;
		aux.movement = linear;
		break;
	}

	return aux;
}

struct powerup set_powerup(const powerup_type type)
{
	struct powerup aux {};

	switch (type)
	{
	case shield:
		aux.type = type;
		aux.duration_type = temporary;
		aux.occurrence = common;
		aux.duration = POWER_UP_DEFAULT_TIME; //10s by default, config will set this value
		break;
	case ice:
		aux.type = type;
		aux.duration_type = temporary;
		aux.occurrence = uncommon;
		aux.duration = POWER_UP_DEFAULT_TIME;
		break;
	case battery:
		aux.type = type;
		aux.duration_type = temporary;
		aux.occurrence = uncommon;
		aux.duration = POWER_UP_DEFAULT_TIME;
		break;
	case enemy_boost:
		aux.type = type;
		aux.duration_type = temporary;
		aux.occurrence = common;
		aux.duration = POWER_UP_DEFAULT_TIME;
		break;
	case life:
		aux.type = type;
		aux.duration_type = permanent;
		aux.occurrence = rare;
		aux.duration = 0; //permanent
		break;
	case alchool:
		aux.type = type;
		aux.duration_type = temporary;
		aux.occurrence = uncommon;
		aux.duration = POWER_UP_DEFAULT_TIME;
		break;
	case noclip:
		aux.type = type;
		aux.duration_type = temporary;
		aux.occurrence = rare;
		aux.duration = POWER_UP_DEFAULT_TIME;
		break;
	}

	return aux;
}

config load_default_config() //this loads the values defined in constants.h as default values
{
	configuration aux{};

	aux.n_players = MIN_PLAYERS_TO_PLAY;
	aux.power_up_trigger_rate = POWER_UP_TRIGGER_RATE; // %
	aux.power_up_drop_rate = POWER_UP_DROP_RATE;
	aux.map_size = MAP_SIZE_MEDIUM;
	aux.num_levels_before_boss = NUM_LEVELS_BEFORE_BOSS;
	aux.base_lifes = BASE_LIFES;
	aux.invaders_start_num = MIN_NUM_INVADERS;
	return aux;
}

config load_config_file(const char *config_name)
{
	configuration aux{};
	string file_name = "configs\\";
	file_name += config_name;
	file_name += ".dat";

	if (!file_exists(file_name))
		return load_default_config(); // se o ficheiro de config nao existir, carrega a config por defeito

	const auto file_name_c = file_name.c_str();
	ifstream input_file(file_name_c, std::ios::binary);
	input_file.read((char*)&aux, sizeof(aux));

	return aux;
}

int save_config_file(config config, char *config_name)
{
	std::string file_name = "configs\\";
	file_name += config_name;
	file_name += ".dat";

	if (CreateDirectory(L"configs", nullptr) || ERROR_ALREADY_EXISTS == GetLastError()) // se a pasta nao existir, cria
	{
		if (file_exists(file_name))
			return CONFIG_SAVE_ALREADY_EXISTS;

		ofstream output_file(file_name, std::ios::binary);
		output_file.write((char*)&config, sizeof(config));
		output_file.close();

		return CONFIG_SAVE_SUCCESS;
	}

	return CONFIG_SAVE_ERROR_SAVING;
}

TCHAR* config_to_string(config config)
{
	wostringstream oss;
	oss << TEXT("Nº de jogadores: ") << config.n_players << endl
		<< TEXT("Power Up trigger rate: ") << config.power_up_trigger_rate << TEXT(" inimigo(s) morto(s)") << endl
		<< TEXT("Power up drop rate: ") << config.power_up_drop_rate << TEXT("%") << endl
		<< TEXT("Tamanho do mapa: ") << config.map_size << "x" << config.map_size << endl
		<< TEXT("Nº de níveis por boss: ") << config.num_levels_before_boss << endl
		<< TEXT("Vida inicial: ") << config.base_lifes << endl
		<< TEXT("Nº base de inimigos: ") << config.n_players << endl;

	auto oss_to_str = oss.str();
	const auto size = oss_to_str.length();

	auto tchar_aux = new TCHAR[size + 1];
	tchar_aux[size] = 0;
	wcscpy_s(tchar_aux, size + 1, static_cast<const wchar_t*>(oss_to_str.c_str()));

	return tchar_aux;
}

struct powerup get_powerup()
{
	struct powerup aux {};

	int r = rand() % 100 + 1; // random number between 1 and 100

	if (r <= 60) //common
		aux.occurrence = common;
	else if (r > 60 && r < 90) //rare
		aux.occurrence = uncommon;
	else if (r >= 90) //very rare
		aux.occurrence = rare;

	switch (aux.occurrence)
	{
	case common:
		r = rand() % 2 + 1;

		if (r == 1)
			aux = set_powerup(shield);
		if (r == 2)
			aux = set_powerup(enemy_boost);
		break;
	case uncommon:
		r = rand() % 3 + 1;

		if (r == 1)
			aux = set_powerup(ice);
		if (r == 2)
			aux = set_powerup(battery);
		else if (r == 3)
			aux = set_powerup(alchool);
		break;
	case rare:
		r = rand() % 2 + 1;

		if (r == 1)
			aux = set_powerup(life);
		if (r == 2)
			aux = set_powerup(noclip);
		break;
	}

	return aux;
}
