#include "dll.h"
#include "Constants.h"

//Para verificar ao carregar a dll que a aplicação irá ocupar mais memória
char ponteiro[40960];

int nDLL = 1234;

struct invader setInvader(const invasor_type type)
{
	struct invader aux {};

	switch (type)
	{
	case basic:
		aux.cooldown = 2500; //the invader must wait 3 seconds before it can make another move
		aux.fireRate = 3; // for each 3 moviments, the invader shoots
		aux.lp = 1;
		aux.type = type;
		aux.pace = 1; //moves 1 field for each 3 seconds passed
		aux.movement = linear; //moves linearly (right or left)
		break;
	case dodger:
		aux.cooldown = 1000; // 1 second
		aux.fireRate = 3; // for each 3 moviments, the invader shoots
		aux.lp = 1;
		aux.type = type;
		aux.pace = 2;
		aux.movement = random;
		break;
	case boss:
		aux.cooldown = 4000;
		aux.fireRate = 1; // for each moviment, the invader shoots
		aux.lp = 5;
		aux.type = type;
		aux.pace = 1;
		aux.movement = linear;
		break;
	}

	return aux;
}

struct powerup setPowerup(const powerup_type type)
{
	struct powerup aux {};

	switch (type)
	{
	case shield:
		aux.type = type;
		aux.duration_type = temporary;
		aux.occurrence = common;
		aux.duration = POWERUP_DEFAULT_TIME; //10s by default, config will set this value
		break;
	case ice:
		aux.type = type;
		aux.duration_type = temporary;
		aux.occurrence = uncommon;
		aux.duration = POWERUP_DEFAULT_TIME; 
		break;
	case battery:
		aux.type = type;
		aux.duration_type = temporary;
		aux.occurrence = uncommon;
		aux.duration = POWERUP_DEFAULT_TIME; 
		break;
	case enemy_boost:
		aux.type = type;
		aux.duration_type = temporary;
		aux.occurrence = common;
		aux.duration = POWERUP_DEFAULT_TIME; 
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
		aux.duration = POWERUP_DEFAULT_TIME; 
		break;
	case noclip:
		aux.type = type;
		aux.duration_type = temporary;
		aux.occurrence = rare;
		aux.duration = POWERUP_DEFAULT_TIME; 
		break;
	default:;
	}

	return aux;
}