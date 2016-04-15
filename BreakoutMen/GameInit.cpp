#include "GameInit.h"
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;



GameInit::GameInit()
{
	window = NULL;
	renderer = NULL;
}


GameInit::~GameInit()
{
}

bool GameInit::Init() {
	window = SDL_CreateWindow("Iben og lasse, ikke frode for han kommer aldri",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN);
	if (window == NULL) {
		SDL_Quit();
		return false;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		SDL_Quit();
		return false;
	}
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_Delay(5000);
	return true;
}