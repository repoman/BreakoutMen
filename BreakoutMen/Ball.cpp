#include "Ball.h"

Ball::Ball()
{
	x = 0;
	y = 0;
	xVelocity = 0;
	yVelocity = -1;
}


Ball::~Ball()
{}

void Ball::Move(int time)
{
	x += xVelocity * time;
	y += yVelocity * time;
}

void Ball::render()
{
	SDL_rect
}