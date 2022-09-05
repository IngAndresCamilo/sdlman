#include "SdlMan.h"


int main(int argc, char* args[]) {
	
	// starting SDL media
	SdlMan::InitMedia();

	// starting RGB colors linked list
	ColorsList* colorlist = new ColorsList();
	colorlist->GetDefautColors();
	// getting the default color for paint the main surface
	auto color = colorlist->GetColor("BLACK");
	// generating a window with default position
	// calling the sdlm-allocator smart pointer
	auto win = SdlmanAllocator(new SdlMan(SdlMan::CreateWindow(CreateWindowPos(DEFAULT_POS))));
	win->PaintMainSurface(color);
	win->Refresh();
	win->WaitFive();

	delete colorlist;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();
	return 0;
}
