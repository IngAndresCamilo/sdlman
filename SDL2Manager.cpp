#include "SdlMan.h"


int main(int argc, char* args[]) {
	
	// starting SDL media
	SdlMan::InitMedia();
	// generating a window with default position
	// calling the sdlm-allocator smart pointer
	auto win = SdlmanAllocator(new SdlMan(SdlMan::CreateWindow(CreateWindowPos(DEFAULT_POS))));
	win->PaintMainSurface();
	win->Refresh();
	win->WaitFive();

	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();
	return 0;
}


void foo() {
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
		return;
	}
	window = SDL_CreateWindow(
		"hello_sdl2",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN
	);
	if (window == NULL) {
		fprintf(stderr, "could not create window: %s\n", SDL_GetError());
		return;
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
}