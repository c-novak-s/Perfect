

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <utility>   //do i need this???, yes
#include <time.h>
#include <unordered_map> //do i need this?
#include <string>
#include <vector>


#include "Visuals.h"
#include "Game.h"



int main(int argc, char ** argv){

	//setups
	Visuals::setup();
	Game::setup();

	


	//========= RUN THE GAME==============
	Game::run();
	//====================================



	//cleanups
	Game::cleanup();
	Visuals::cleanup();



	//close
	printf("Everything went swimmingly.");
	return 0;
}