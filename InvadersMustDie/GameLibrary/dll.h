#pragma once
#include "../Server/Enums.h"
#include "Constants.h"

//Este .h deve ser incluído no projeto que o vai usar (modo implícito)

#define TAM 256

#ifdef GAMELIBRARY_EXPORTS
#define DLL_IMP_API __declspec(dllexport)
#else
#define DLL_IMP_API __declspec(dllimport)
#endif

struct field
{
	char field_size[MAX_SIZE_LARGE][MAX_SIZE_LARGE];
	int nInvaders; //number of invaders left
};

struct invader
{
	invasor_type type;
	int lp;
	movement_type movement; //1 => linear; 2 => random
	int pace; //number of steps that the monster can have after the cooldown time been 
	int cooldown; //time, in miliseconds, that the monsters freezes after each movement
	int fireRate; //shots for each N movement
	int x; //x cord
	int y; //y cord of the left corner
	int width;
	int length;
};

struct powerup
{
	powerup_type type;
	powerup_duration_type duration_type;
	int duration; //0 => permanent
	occurrence_type occurrence;
	int x; //x cord
	int y; //y cord of the left corner
	int width; //pode definir-se uma constante para o tamanho e definir logo aqui para o length tambem
	int length;
	int speed; //pode definir-se uma constante para o tamanho e definir logo aqui 
};

struct defender
{
	int life;
	int points;
	int damage;
	int x; //x cord
	int y; //y cord of the left corner
	int width;
	int length;
	int speed;
	int fireRate; //speed of the shots
	//bool hasShield; // true if defender got "Escudo" powerup
	//bool isInverted; // true if defender got "Álcool" powerup
	//bool hasNoclip; // true if defender got "NoClip" powerup
};

struct configuration
{
	int nPlayers; //1 => singleplayer, 2 => co-op ... 3, 4 ... n players
	int powerUpRate;
	int currentLevel;
};

struct bombs
{
	int x; //x cord
	int y; //y cord of the left corner
	int width;
	int length;
	int speed;
	int damage;
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