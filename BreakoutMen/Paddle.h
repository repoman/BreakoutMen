#include "SDL.h"
#include "Main.cpp"
#include "GameInit.h
#include <iostream>
#include <SDL.h>

class Paddle
{
public:
	static const int PADDLE_WIDTH = 40;
	static const int PADDLE_HEIGHT = 10;

	static const int PADDLE_SPEED = 10;

	Paddle(SDL_Renderer* renderer);

	void handleEvent(SDL_Event& e);

	void move();

	void render();

private:
	int mPosX, mPosY;
	int mVelX;

	SDL_Texture* texture;
};