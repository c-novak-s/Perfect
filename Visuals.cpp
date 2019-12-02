#include "Visuals.h"
#include "TextureManager.h"


//statics
SDL_Window* Visuals::MAINwindow = nullptr; 
SDL_Renderer* Visuals::MAINrenderer = nullptr;




void Visuals::setup() {

	//====== SETUP THE VISUALS==========
	SDL_Init(SDL_INIT_VIDEO);//??
	SDL_Init(SDL_INIT_EVERYTHING);
	atexit(SDL_Quit);
	

	MAINwindow = SDL_CreateWindow("Perfect_Untitled",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, //SDL_WINDOWPOS_UNDEFINED
		512, 512,
		//SDL_WINDOW_FULLSCREEN_DESKTOP
		NULL
	);
	SDL_Renderer* MAINrenderer = SDL_CreateRenderer(MAINwindow, -1, 0);
	//SDL_ShowCursor(SDL_DISABLE);
	SDL_SetRenderDrawColor(MAINrenderer, 100, 100, 100, 255);
	SDL_RenderClear(MAINrenderer);
	SDL_RenderPresent(MAINrenderer);
	//====== SETUP THE VISUALS==========

	TextureManager::setup(MAINrenderer);

}
void Visuals::cleanup() {
	TextureManager::cleanup();

	SDL_DestroyRenderer(MAINrenderer);
	SDL_DestroyWindow(MAINwindow);
	
	SDL_Quit();
}
SDL_Window* Visuals::getWindow() {
	return MAINwindow;
}
SDL_Renderer* Visuals::getRenderer() {
	return MAINrenderer;
}





