
#include "dll.h"

//Para verificar ao carregar a dll que a aplicação irá ocupar mais memória
char ponteiro[40960];

typedef enum { temporary = 1, permanent } powerup_durarion;

int nDLL = 1234;

struct invader setInvader(std::string name)
{
	struct invader aux;

	if (name == "basic")
	{
		aux.cooldown = 2500; //the invader must wait 3 seconds before it can make another move
		aux.fireRate = 3; // for each 3 moviments, the invader shoots
		aux.lp = 1;
		aux.name = name;
		aux.pace = 1; //moves 1 field for each 3 seconds passed
		aux.movement = 1; //moves linearly (right or left)
	}
	else if (name == "dodger")
	{
		aux.cooldown = 1000; // 1 second
		aux.fireRate = 3; // for each 3 moviments, the invader shoots
		aux.lp = 1;
		aux.name = name;
		aux.pace = 2;
		aux.movement = 1;
	}
	else if (name == "tank")
	{
		aux.cooldown = 4000;
		aux.fireRate = 1; // for each moviment, the invader shoots
		aux.lp = 5;
		aux.name = name;
		aux.pace = 1;
		aux.movement = 1; 
	}
	 
	/*
	others
	*/ 

	return aux;
}

struct powerup setPowerup(std::string name)
{
	struct powerup aux;

	if (name == "Escudo")
	{
		aux.duration = 1; // temporary
		aux.occurrence = 1; //common
		aux.name = name;
	}
	else if (name == "Gelo")
	{
		aux.duration = 1; // temporary
		aux.occurrence = 2; //uncommon
		aux.name = name;
	}
	else if (name == "Bateria")
	{
		aux.duration = 1; // temporary
		aux.occurrence = 1;
		aux.name = name;
	}

	/*
	etc //não sei se os efeitos dos powerups vão ser feitos aqui ou no servidor (bem como o random que os
	         atribui)
	*/

	return aux;
}