#pragma once

#include <SDL.h>
#include <string>

void renderTexture(
	SDL_Texture *texture,
	SDL_Renderer *renderer,
	SDL_Rect dst, 
	SDL_Rect *rect = nullptr);

void renderTexture(
	SDL_Texture *texture,
	SDL_Renderer *renderer, 
	int x, 
	int y, 
	SDL_Rect *rect = nullptr);

SDL_Texture* renderText(
	const std::string &message,
	const std::string &fontFile, 
	SDL_Color colour,
	int fontSize, 
	SDL_Renderer *renderer);