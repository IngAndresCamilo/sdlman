#include "SdlMan.h"



int main(int argc, char* args[]) {
	
	// starting SDL media
	SdlMan::InitMedia();

	
	// generating a window with default position
	auto *win = new SdlMan(SdlMan::CreateWindow(CreateWindowPos(DEFAULT_POS)));
	win->PaintMainSurface(win->AccessColors()->GetColor("RED"));
	win->Refresh();
	win->AccessSurfaces()->Add(STR("sprite1"), SDL_LoadBMP("sprites/bitmaps/zirox1.bmp"));
	win->AccessSurfaces()->Add(STR("sprite2"), SDL_LoadBMP("sprites/bitmaps/zirox2.bmp"));
	win->AccessSurfaces()->Add(STR("sprite3"), SDL_LoadBMP("sprites/bitmaps/zirox3.bmp"));
	win->AccessSurfaces()->Add(STR("sprite4"), SDL_LoadBMP("sprites/bitmaps/zirox4.bmp"));
	win->WaitFive();

	delete win;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();
	return 0;
}

