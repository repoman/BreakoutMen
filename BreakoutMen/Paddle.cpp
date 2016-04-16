#include "Paddle.h"
#include "Main.h"
void Paddle::render(){
	SDL_Surface* image = SDL_LoadBMP("sdl2.bmp"); //her sætt man et bilde i ramman

	if (image == NULL)
	{
		std::cerr << "Failed to load image, details:" << SDL_GetError() << std::endl;
		SDL_Quit();
	} //sjekk om at bildet funka???
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);

	if (texture == NULL)
	{
		std::cerr << "Failed to generate texture, details:" << SDL_GetError() << std::endl;
		SDL_Quit();
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_FreeSurface(image);
	} // funka teksturen skjøner???

	SDL_Rect bounding_box;
	bounding_box.h = 10;
	bounding_box.w = 90;
	bounding_box.x = 250;
	bounding_box.y = 360;

	SDL_FreeSurface(image);
}