#pragma once

#include <windows.h>
#include <tchar.h>
#include <string>

//Este .h deve ser incluído no projeto que o vai usar (modo implícito)

#define TAM 256

#ifdef GAMELIBRARY_EXPORTS
#define DLL_IMP_API __declspec(dllexport)
#else
#define DLL_IMP_API __declspec(dllimport)
#endif

struct invader
{
	std::string name;
	int lp;
	int movement; //1 => linear; 2 => random
	int pace; //number of steps that the monster can have after the cooldown time been 
	int cooldown; //time, in miliseconds, that the monsters freezes after each movement
	int fireRate; //shots for each N movement
};

struct powerup
{
	std::string name;
	int duration; //1 => temporary
	int occurrence; //1 => commun, 2 => rare, 3 => very rare
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