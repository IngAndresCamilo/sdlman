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

	return window;
}
