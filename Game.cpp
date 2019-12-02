#include "Game.h"
#include "TextureManager.h"
#include <time.h>


//statics
SDL_Renderer* Game::r = nullptr;
bool Game::done = false;
bool Game::myTurn = false;
SDL_Point Game::mouseLocation = { 0,0 };
signed char Game::color = 0;
signed char Game::grid[7][6] = { { 0,0,0,0,0,0 },
								 { 0,0,0,0,0,0 },
								 { 0,0,0,0,0,0 },
								 { 0,0,0,0,0,0 },
								 { 0,0,0,0,0,0 },
								 { 0,0,0,0,0,0 },
								 { 0,0,0,0,0,0 } };
SOCKET* Game::toHostSocket = nullptr;
								 

void Game::setup(SDL_Renderer* rn, signed char c, bool t, SOCKET* ths) {
	srand(time(NULL));

	r = rn;
	color = c;
	myTurn = t;
	toHostSocket = ths;

}
void Game::run() {

	SDL_Texture* board = TextureManager::myTextureGet("Board.png");
	SDL_Texture* blueDisc = TextureManager::myTextureGet("BlueDisc.png");
	SDL_Texture* redDisc = TextureManager::myTextureGet("RedDisc.png");
	SDL_Texture* arrows = TextureManager::myTextureGet("Arrows.png");
	
	SDL_Rect arrowsRect = {32,32,448,64};
	SDL_Rect DiscStamp = {0,0,64,64};




	SDL_Event event;
	//begin game loop
	while (!done) {
		//begin event handling
		if (!myTurn) {
			receiveMove();
		}

		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT: done = true; break;
			case SDL_KEYDOWN:
				if (event.key.repeat == 0) {
					switch (event.key.keysym.sym) {
					case SDLK_ESCAPE: done = true; break;
					}
				}; break;
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT) { // left click
					handleClick();
				} else if (event.button.button == SDL_BUTTON_RIGHT) { // right click

				}; break;
			case SDL_MOUSEMOTION:
				mouseLocation = { event.motion.x, event.motion.y };
				break;
			}

		}//end event handling


		SDL_RenderCopy(r,board,NULL,NULL);
		for (int x = 0; x < 7; x++) {
			for (int y = 0; y < 6; y++) {
				DiscStamp.x = 32 + (x*64);
				DiscStamp.y = 96 + (y*64);

				if (grid[x][y] == 1) {
					SDL_RenderCopy(r,redDisc,NULL, &DiscStamp);
				} else if (grid[x][y] == -1) {
					SDL_RenderCopy(r,blueDisc,NULL, &DiscStamp);
				}
			}
		}
		if (myTurn) {
			SDL_RenderCopy(r,arrows,NULL,&arrowsRect);
		}

		SDL_RenderPresent(r);
		
	}
	//end game loop (done == false)
}
void Game::cleanup() {

}








void Game::handleClick() {
	if (myTurn && mouseLocation.x >= 32 && mouseLocation.x < 480) {
		int col = (mouseLocation.x - 32) / 64;
		for (int row = 5; row >= 0; row--) {
			if (grid[col][row] == 0) {
				grid[col][row] = color;
				sendMove({(signed char)col,(signed char)row,color});
				myTurn = false; //comment out for testing
				return;
			}
		}
	}
}
void Game::sendMove(Move m) {
	int i = send(*toHostSocket, (char*)&m, sizeof(m), 0);
}
void Game::receiveMove() {
	Move m;
	int i = recv(*toHostSocket, (char*)&m, sizeof(m), 0);
	grid[m.x][m.y] = m.color;
	myTurn = true;
}