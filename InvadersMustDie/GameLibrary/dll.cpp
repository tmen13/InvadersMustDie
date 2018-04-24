/*  USAR DESTA MANEIRA
 
 // Inclusion guard
 #ifndef _DLLTUT_DLL_H_
 #define _DLLTUT_DLL_H_

 // Make our life easier, if DLL_EXPORT is defined in a file then DECLDIR will do an export
 // If it is not defined DECLDIR will do an import
 #if defined DLL_EXPORT
 #define DECLDIR __declspec(dllexport)
 #else
 #define DECLDIR __declspec(dllimport)
 #endif

 #ifdef __cplusplus
 extern "C" {
 #endif

 DECLDIR int Add(int a, int b);

 #ifdef __cplusplus
 }

 #endif
 #endif


 */


#include "dll.h"
#include "Constants.h"
//#include <cstdlib>
//#include <ctime>

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

struct configuration LoadDefaultConfig(int nPlayers, int powerUpRate, int itemSpeed, int startUpLevel, int life) //this loads the values defined in constants.h as default values
{
	struct configuration aux{};

	aux.nPlayers = nPlayers;
	aux.powerUpRate = powerUpRate; // %
	aux.currentLevel = startUpLevel;

	
	return aux;
}

//struct powerup setPowerup() todo: make into a function
//{
//	struct powerup aux;
//
//	srand(time(NULL));
//	int r = (rand() % 100) + 1; // random number between 1 and 100
//
//	if (r <= 60) //common
//		aux.occurrence = 1;
//	else if (r > 60 && r < 90) //rare
//		aux.occurrence = 2;
//	else if (r >= 90) //very rare
//		aux.occurrence = 3;
//
//	if (aux.occurrence == 1) //common
//	{
//		int r = (rand() % 3) + 1;
//
//		if (r == 1)
//		{
//			aux.name = "Escudo";
//			defender.shield = true;
//		}
//		else if (r == 2)
//		{
//			aux.name = "Mais";
//			invader.cooldown -= 1000; //-1 second
//		}
//		else if (r == 3) // extra
//		{
//			aux.name = "Redux";
//			defender.size /= 2;
//		}
//		aux.duration = 1; // temporary
//	}
//	else if (aux.occurrence == 2) //rare
//	{
//		int r = (rand() % 3) + 1;
//
//		if (r == 1)
//		{
//			aux.name = "Gelo";
//			invader.froze = true;
//		}
//		else if (r == 2) //all defenders
//		{
//			aux.name = "Bateria";
//			defender.shots += 1;
//		}
//		else if (r == 3)
//		{
//			aux.name = "Alcool";
//			defender.inverted = true;
//		}
//
//		aux.duration = 1;
//	}
//}