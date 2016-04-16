#include "Ball.h"



Ball::Ball()
{
	xpos = 0;
	ypos = 0;
	xvel = 1;
	yvel = 1;
}


Ball::~Ball()
{}

void Ball::Move(float tick)
{
	xpos += xvel*tick;
	ypos += yvel*tick;
}

void Ball::render()
{
	
}