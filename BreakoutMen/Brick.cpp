#include "Brick.h"

const int Brick::HEIGHT = 13;
const int Brick::WIDTH = 74;

Brick::Brick(int x, int y)
{
	this->x = x;
	this->y = y;
	dead = false;
}

Brick::Brick()
{
	
}

int Brick::get_x() const {
	return x;
}

int Brick::get_y() const {
	return y;
}