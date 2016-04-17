#include <iostream>
#include "Main.h"

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		std::cerr << "Failed to initialize SDL, details:" << SDL_GetError() << std::endl;

		return EXIT_FAILURE;
	}

	SDL_Window* window = SDL_CreateWindow(
		"An awesome SDL window",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		SDL_WINDOW_SHOWN
		); // her lagar vi vinduet skjønner?

	if (window == NULL)
	{
		std::cerr << "Failed to open SDL window, details:" << SDL_GetError() << std::endl;
		SDL_Quit();
		return EXIT_FAILURE;
	} // her sjækk vi om vinduet gikk feilåt, skjønner?

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	//lag en renderer, skjønner?

	if (renderer == NULL)
	{
		std::cerr << "Failed to create renderer, details:" << SDL_GetError() << std::endl;
		SDL_Quit();
		SDL_DestroyWindow(window);
		return EXIT_FAILURE;
	} // gikk det en feil skjønner?

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // gjør rendern svart skjønner?
	SDL_RenderClear(renderer); //her klarerer man renderern skjønner?

	SDL_Surface* image = SDL_LoadBMP("sdl2.bmp"); //her sætt man et bilde i ramman

	if (image == NULL)
	{
		std::cerr << "Failed to load image, details:" << SDL_GetError() << std::endl;
		SDL_Quit();
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		return EXIT_FAILURE;
	} //sjekk om at bildet funka???

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);

	if (texture == NULL)
	{
		std::cerr << "Failed to generate texture, details:" << SDL_GetError() << std::endl;
		SDL_Quit();
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_FreeSurface(image);
		return EXIT_FAILURE;
	} // funka teksturen skjøner???

	SDL_Rect paddle;
	paddle.h = 10;
	paddle.w = 90;
	paddle.x = 250;
	paddle.y = 360;

	SDL_Rect ball;
	ball.h = 32;
	ball.w = 32;
	ball.x = 304;
	ball.y = 448;

	SDL_FreeSurface(image);

	// ---------------------------------------
	// Game loop would normally run from here.

	// TODO: 1) Get input.

	// TODO: 2) Do business (domain) logic.

	while (true)
	{
		// 3) Render output:
		SDL_RenderClear(renderer); //her klarerer man renderern skjønner?
		SDL_RenderCopy(renderer, texture, NULL, &paddle);
		SDL_RenderCopy(renderer, texture, NULL, &ball);
		SDL_RenderPresent(renderer);

		paddle.x += 1;
	}

	// Game loop would normally end here.
	// ---------------------------------------

	std::cout << "Everything went better than expected!" << std::endl;

	system("pause");

	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}