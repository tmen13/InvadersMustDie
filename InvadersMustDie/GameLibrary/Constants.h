#pragma once

//Config constants
#define MAX_PLAYERS_ALLOWED 4
#define MIN_PLAYERS_TO_PLAY 1
#define MAP_SIZE_MEDIUM 500
#define MAX_SIZE_LARGE 700
#define POWER_UP_DEFAULT_TIME 10000 // power up lasts 10s
#define POWER_UP_TRIGGER_RATE 3 // when 3 enemies are killed, theres a trigger to check if a power up will drop
#define POWER_UP_DROP_RATE 50 // 50% of droping a power up if 3 enemies are killed
#define BASE_LIFES 3 // the player starts with 3 lifes
#define NUM_LEVELS_BEFORE_BOSS 5
#define MAX_NUM_INVADERS 50
#define MIN_NUM_INVADERS 10

//Warnings constants
#define CONFIG_SAVE_SUCCESS 0
#define CONFIG_SAVE_ALREADY_EXISTS 1