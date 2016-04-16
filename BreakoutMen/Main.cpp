#include <iostream>
#include <SDL.h>

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		std::cerr << "Failed to initialize SDL, details:" << SDL_GetError() << std::endl;

		return EXIT_FAILURE;
	}

	window = SDL_CreateWindow(
		"An awesome SDL window",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		550,
		400,
		SDL_WINDOW_SHOWN
		); // her lagar vi vinduet skj�nner?

	if (window == NULL)
	{
		std::cerr << "Failed to open SDL window, details:" << SDL_GetError() << std::endl;
		SDL_Quit();
		return EXIT_FAILURE;
	} // her sj�kk vi om vinduet gikk feil�t, skj�nner?

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	//lag en renderer, skj�nner?

	if (renderer == NULL)
	{
		std::cerr << "Failed to create renderer, details:" << SDL_GetError() << std::endl;
		SDL_Quit();
		SDL_DestroyWindow(window);
		return EXIT_FAILURE;
	} // gikk det en feil skj�nner?

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // gj�r rendern svart skj�nner?
	SDL_RenderClear(renderer); //her klarerer man renderern skj�nner?

	SDL_Surface* image = SDL_LoadBMP("sdl2.bmp"); //her s�tt man et bilde i ramman

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
	} // funka teksturen skj�ner???

	SDL_Rect bounding_box;
	bounding_box.h = 10;
	bounding_box.w = 90;
	bounding_box.x = 250;
	bounding_box.y = 360;

	SDL_FreeSurface(image);

	// ---------------------------------------
	// Game loop would normally run from here.

	// TODO: 1) Get input.

	// TODO: 2) Do business (domain) logic.

	// 3) Render output:
	SDL_RenderCopy(renderer, texture, NULL, &bounding_box);
	SDL_RenderPresent(renderer);

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