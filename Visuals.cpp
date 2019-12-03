#include "Visuals.h"
#include "TextureManager.h"


//statics
SDL_Window* Visuals::MAINwindow = nullptr; 
SDL_Renderer* Visuals::MAINrenderer = nullptr;

SDL_Rect Visuals::viewRect = { 0,0,0,0 };
SDL_Point Visuals::screenDims = { 512,512 };

void Visuals::setup() {

	//=======<SETUP THE VISUALS>==========
	SDL_Init(SDL_INIT_EVERYTHING);
	atexit(SDL_Quit);
	

	MAINwindow = SDL_CreateWindow("Perfect_Untitled",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, //SDL_WINDOWPOS_UNDEFINED
		screenDims.x, screenDims.y,
		//SDL_WINDOW_FULLSCREEN_DESKTOP
		SDL_WINDOW_RESIZABLE
	);
	SDL_Renderer* MAINrenderer = SDL_CreateRenderer(MAINwindow, -1, 0);
	//SDL_ShowCursor(SDL_DISABLE);
	SDL_SetRenderDrawColor(MAINrenderer, 100, 100, 100, 255);
	SDL_RenderClear(MAINrenderer);
	SDL_RenderPresent(MAINrenderer);
	//======<\SETUP THE VISUALS>==========

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


void Visuals::recheckScreenDims() {
	int w, h;
	SDL_GetWindowSize(MAINwindow, &w, &h);
	screenDims = { w,h };
}
void Visuals::setFullScreen(bool fs) {
	if (fs) {
		SDL_SetWindowFullscreen(MAINwindow, SDL_WINDOW_FULLSCREEN_DESKTOP);
	} else {
		SDL_SetWindowFullscreen(MAINwindow, 0);
	}
}


SDL_Rect* Visuals::getViewRect() {
	return &viewRect;
}
SDL_Point Visuals::getViewCenter() {
	return { viewRect.x + (viewRect.w / 2) ,
			 viewRect.y + (viewRect.h / 2) };
}
void Visuals::setViewCenter(SDL_Point pt) {
	viewRect.x = pt.x - (viewRect.w / 2);
	viewRect.y = pt.x - (viewRect.h / 2);
}







SDL_Rect Visuals::convertRect(SDL_Rect rect) {
	//complicated stuff here

}
SDL_Point Visuals::convertPoint(SDL_Point pt) {
	//similar here

}