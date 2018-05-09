#define DLL_EXPORT

#include "Core.h"
#include "Constants.h"
#include <cstdlib>

//Para verificar ao carregar a dll que a aplicação irá ocupar mais memória
char ponteiro[40960];

struct invader set_invader(const invader_type type)
{
	struct invader aux {};

	switch (type)
	{
	case basic:
		aux.cooldown = 2500; //the invader must wait 3 seconds before it can make another move
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

struct configuration load_default_config() //this loads the values defined in constants.h as default values
{
	configuration aux{};

	aux.n_players = MIN_PLAYERS_TO_PLAY;
	aux.power_up_trigger_rate = POWER_UP_TRIGGER_RATE; // %
	aux.power_up_drop_rate = POWER_UP_DROP_RATE; 
	aux.map_size = MAP_SIZE_MEDIUM;
	aux.num_levels_before_boss = NUM_LEVELS_BEFORE_BOSS;
	aux.base_lifes = BASE_LIFES;
	aux.current_level = 1; //on init, this will be the start level
	aux.invaders_start_num = MIN_NUM_INVADERS;
	return aux;
}

struct configuration load_config_file(char *file_path)
{
	configuration aux{};

	aux.n_players = MIN_PLAYERS_TO_PLAY;
	aux.power_up_trigger_rate = POWER_UP_TRIGGER_RATE; // %
	aux.power_up_drop_rate = POWER_UP_DROP_RATE;
	aux.map_size = MAP_SIZE_MEDIUM;
	aux.num_levels_before_boss = NUM_LEVELS_BEFORE_BOSS;
	aux.base_lifes = BASE_LIFES;
	aux.current_level = 1; //on init, this will be the start level
	return aux;

}

void save_config_file(configuration *config)
{
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
