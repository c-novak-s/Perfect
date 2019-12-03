#pragma once

#include <windows.h>
#include "SDL.h"
#include "SDL_image.h"
#include <vector>

class Visuals {
	public:
		static void setup();
		static void cleanup();
		
		static SDL_Window* getWindow();
		static SDL_Renderer* getRenderer();

		static void recheckScreenDims();
		static void setFullScreen(bool fs);

		static SDL_Rect* getViewRect();
		static SDL_Point getViewCenter();
		static void setViewCenter(SDL_Point pt);
		



		static SDL_Rect convertRect(SDL_Rect rect);
		static SDL_Point convertPoint(SDL_Point pt);

	private:
		static SDL_Window* MAINwindow;
		static SDL_Renderer* MAINrenderer;

		static SDL_Rect viewRect;
		static SDL_Point screenDims;
};




