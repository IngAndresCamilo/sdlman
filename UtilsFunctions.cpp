#include "SdlMan.h"


winpos_t *CreateWindowPos(int type) {
	winpos_t *winpos = nullptr;
	switch (type)
	{
	case 1:
		winpos = new winpos_t{
			"Default",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN
		};
		break;
	default:
		break;
	}
	return winpos;
}