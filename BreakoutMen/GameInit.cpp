#include "GameInit.h"
#include <iostream>
#include "Paddle.h"

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

	SDL_Surface* image = SDL_LoadBMP("sdl2.bmp");

	if (image == NULL)
	{
		std::cerr << "Failed to load image, details:" << SDL_GetError() << std::endl;
		SDL_Quit();
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		return EXIT_FAILURE;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);

	if (texture == NULL)
	{
		std::cerr << "Failed to generate texture, details:" << SDL_GetError() << std::endl;
		SDL_Quit();
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_FreeSurface(image);
		return EXIT_FAILURE;
	}

	SDL_Rect bounding_box;
	bounding_box.h = image->h;
	bounding_box.w = image->w;
	bounding_box.x = 0;
	bounding_box.y = 0;

	SDL_FreeSurface(image);

	SDL_RenderCopy(renderer, texture, NULL, &bounding_box);
	SDL_RenderPresent(renderer);


	system("pause");

	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}

void GameInit::Run() {
	paddle = new Paddle(renderer);

	//NewGame();
	//Clean();

	SDL_Quit();
}