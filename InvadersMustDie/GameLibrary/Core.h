// Inclusion guard
#ifndef CORE_H
#define CORE_H

#pragma once
#include "../Server/Enums.h"
#include "Constants.h"

#define TAM 256

#if defined DLL_EXPORT
#define DECLDIR __declspec(dllexport)
#else
#define DECLDIR __declspec(dllimport)
#endif

struct field
{
	char field_size[MAX_SIZE_LARGE][MAX_SIZE_LARGE];
	int n_invaders; //number of invaders left
};

struct invader
{
	invader_type type;
	int lp;
	movement_type movement; //1 => linear; 2 => random
	int pace; //number of steps that the monster can have after the cooldown time been 
	int cooldown; //time, in miliseconds, that the monsters freezes after each movement
	int fire_rate; //shots for each N movement
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
	int fire_rate; //speed of the shots
				   //bool hasShield; // true if defender got "Escudo" powerup
				   //bool isInverted; // true if defender got "Álcool" powerup
				   //bool hasNoclip; // true if defender got "NoClip" powerup
};

struct configuration
{
	int n_players; //1 => singleplayer, 2 => co-op ... 3, 4 ... n players
	int power_up_rate;
	int current_level;
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

#ifdef __cplusplus
extern "C" {
#endif
	DECLDIR struct powerup get_powerup(void);
#ifdef __cplusplus
}

#endif
#endif