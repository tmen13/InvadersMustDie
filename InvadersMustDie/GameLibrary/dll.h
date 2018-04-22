#pragma once
#include "../Server/Enums.h"

//Este .h deve ser incluído no projeto que o vai usar (modo implícito)

#define TAM 256

#ifdef GAMELIBRARY_EXPORTS
#define DLL_IMP_API __declspec(dllexport)
#else
#define DLL_IMP_API __declspec(dllimport)
#endif

struct invader
{
	invasor_type type;;
	int lp;
	movement_type movement; //1 => linear; 2 => random
	int pace; //number of steps that the monster can have after the cooldown time been 
	int cooldown; //time, in miliseconds, that the monsters freezes after each movement
	int fireRate; //shots for each N movement
};

struct powerup
{
	powerup_type type;
	powerup_duration_type duration_type;
	int duration; //0 => permanent
	occurrence_type occurrence; 
};

extern "C"
{
	//tmp
	extern DLL_IMP_API int nDLL;
	//

	//Funções a serem exportadas/importadas
	//DLL_IMP_API struct invader setInvader(std::string name);
	//DLL_IMP_API struct powerup setPowerup(std::string name);
}