#include "Utilities.h"
#include <SDL.h>
#include <SDL_ttf.h>

void renderTexture(
	SDL_Texture* texture,
	SDL_Renderer* renderer, 
	SDL_Rect dst, 
	SDL_Rect* rect) {
		SDL_RenderCopy(renderer, texture, rect, &dst);
}

void renderTexture(
	SDL_Texture* texture,
	SDL_Renderer* renderer, 
	int x, 
	int y, 
	SDL_Rect* rect) {
		SDL_Rect dst;
		dst.x = x;
		dst.y = y;
		if (rect != nullptr) {
			dst.w = rect->w;
			dst.h = rect->h;
		} else {
			SDL_QueryTexture(texture, nullptr, nullptr, &dst.w, &dst.h);
	}

	renderTexture(texture, renderer, dst, rect);
}

SDL_Texture* renderText(
	const std::string &message,
	const std::string &fontFile, 
	SDL_Color colour,
	int fontSize, 
	SDL_Renderer* renderer) {

		TTF_Font* font = TTF_OpenFont(fontFile.c_str(), fontSize);

		SDL_Surface* surface = TTF_RenderText_Blended(font, message.c_str(), colour);

		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

		SDL_FreeSurface(surface);
		TTF_CloseFont(font);
		return texture;
}
