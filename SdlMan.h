#pragma once

#define _CRTDBG_MAP_ALLOC
#include <SDL.h>
#include <stdio.h>
#include <vector>
#include <memory>
#include <stdlib.h>
#include <crtdbg.h>


// for screen sizing
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

// for windows position
#define DEFAULT_POS 1
#define CUSTOM_POS 2


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
	std::vector<SDL_Surface*> surfaces;
public:
	SDL_Window* GetWindow();
	static void InitMedia();
	// static Method to create a SDL window without an instance of sdlman
	static SDL_Window* CreateWindow(winpos_t *winpos);
	SdlMan(SDL_Window* win, std::vector<SDL_Surface*> surfaces) {
		this->main_window = win;
		this->surfaces = surfaces;
	}
} ;

class SdlmanAllocator
{
private:
	SdlMan* ptr;
public:
	explicit SdlmanAllocator(SdlMan* p) { ptr = p; }

	~SdlmanAllocator() {
		SDL_DestroyWindow(this->ptr->GetWindow());
		SDL_Quit();
	}
	SdlMan& unwrap() { return *ptr; }
};


winpos_t* CreateWindowPos(int type);