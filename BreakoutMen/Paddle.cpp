#include "Paddle.h"



Paddle::Paddle(SDL_Renderer* renderer) : GameManager(renderer) {
	SDL_Surface* surface = IMG_Load("sdl2.bmp");
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	width = 128;
	height = 32;

	y = 0;
	x = 64;
}

Paddle::~Paddle() {
	SDL_DestroyTexture(texture);
}


void Paddle::Update(float delta) {

}

void Paddle::Render(float delta) {
	SDL_Rect rect;
	rect.x = (int)(x + 0.5f);
	rect.y = (int)(y + 0.5f);
	rect.w = width;
	rect.h = height;
	SDL_RenderCopy(renderer, texture, 0, &rect);
}
