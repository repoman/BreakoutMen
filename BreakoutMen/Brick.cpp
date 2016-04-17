#include "Brick.h"

const int Brick::HEIGHT = 13;
const int Brick::WIDTH = 74;

Brick::Brick(int x, int y, int r, int g, int b)
{
	this->x = x;
	this->y = y;
	this->r = r;
	this->g = g;
	this->b = b;
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

int Brick::get_r() const {
	return r;
}

int Brick::get_g() const {
	return g;
}

int Brick::get_b() const {
	return b;
}