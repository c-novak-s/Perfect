#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "Move.h"

#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

class Game {
public:
	static void setup(SDL_Renderer* rn, signed char c, bool t, SOCKET* ths);
	static void run();
	static void cleanup();
private:
	static void handleClick();
	static void sendMove(Move m);
	static void receiveMove();

	static SOCKET* toHostSocket;

	static SDL_Renderer* r;
	static bool done;
	static SDL_Point mouseLocation;
	

	static signed char color;
	static bool myTurn;
	static signed char grid[7][6]; // -1 blue, 0 none, 1 red
};