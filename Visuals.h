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

		static void renderObj(Renderable* obj);

	private:
		static SDL_Window* MAINwindow;
		static SDL_Renderer* MAINrenderer;

};


class Renderable {
	public:
		Renderable();

		void setVisible();
		bool getVisible();
		void setShouldRemove();
		bool getShouldRemove();

	private:
		bool visible;
		bool shouldRemove;

};



