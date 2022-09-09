#include "SdlMan.h"

SDL_Window* SdlMan::GetWindow() {
	return this->main_window;
}

void SdlMan::InitMedia() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
		return;
	}
}

SDL_Window* SdlMan::CreateWindow(winpos_t *winpos) {
	SDL_Window *window = SDL_CreateWindow(
		winpos->title,
		winpos->x,
		winpos->y,
		winpos->width,
		winpos->height,
		winpos->flag
	);

	if (!window) {
		fprintf(stderr, "could not create window: %s\n", SDL_GetError());
	}

	// Creating a window consume the pointer of WindowsPosition
	delete winpos;

	return window;
}

void SdlMan::PaintMainSurface(ColorsNode *color) {
	SDL_FillRect(this->screen_surface, NULL, SDL_MapRGB(this->screen_surface->format, color->R, color->G, color->B));
}


void SdlMan::Refresh() {
	SDL_UpdateWindowSurface(this->main_window);
}

void SdlMan::WaitFive() {
	SDL_Delay(5000);
}

void SdlMan::Clean() {

} 

// Methods GETTER for Access to external classes

ColorsList* SdlMan::AccessColors() {
	return this->colors;
}


Surfaces* SdlMan::AccessSurfaces() {
	return this->external_surfaces;
}
