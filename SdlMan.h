#pragma once
#include "includes.h"

// for screen sizing
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

// for windows position
#define DEFAULT_POS 1
#define CUSTOM_POS 2

// used as argument to instanciate a new SDL window
typedef struct WindowsPos {
	const char *title;
	int x;
	int y;
	int width;
	int height;
	Uint32 flag;
}winpos_t;

class SdlMan
{
private:
	SDL_Window* main_window;
	SDL_Surface* screen_surface;
	ColorsList* colors;
	Surfaces* external_surfaces;
public:
	SDL_Window* GetWindow();
	static void InitMedia();
	// static Method to create a SDL window without an instance of sdlman
	static SDL_Window* CreateWindow(winpos_t *winpos);

	// method that affects the surface of the main window
	void PaintMainSurface(ColorsNode *color);
	void Refresh();
	void WaitFive();
	void WaitSecond();
	static void Clean();
	void MergeWSurface(char *surface_name);

	// methods for colorlist
	ColorsList* AccessColors();

	// methods for surfaces
	Surfaces* AccessSurfaces();


	// contructor
	SdlMan(SDL_Window* win) {
		this->main_window = win;
		this->screen_surface = SDL_GetWindowSurface(this->main_window);
		this->colors = new ColorsList();
		this->colors->GetDefautColors();
		this->external_surfaces = new Surfaces();
	}

	~SdlMan() {
		SDL_DestroyWindow(this->GetWindow());
		SDL_Quit();
		delete this->external_surfaces;
		delete this->colors;
		std::cout << "The main window has been destroyed succesfully" << std::endl;
	}
} ;



winpos_t* CreateWindowPos(int type);
