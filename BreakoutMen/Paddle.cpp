#include "Paddle.h"
#include "Ball.h"
#include "Game.h"

const int Paddle::HEIGHT = 10;
const int Paddle::WIDTH = 100;

Paddle::Paddle(int new_x, int new_y) {
	x = new_x;
	y = new_y;
	leftKeyDown = false;
	rightKeyDown = false;
}

int Paddle::get_x() const {
	return x;
}

int Paddle::get_y() const {
	return y;
}

void Paddle::set_x(int new_x) {
	x = new_x;

	if (x < 0)
		x = 0;
	else if (x + WIDTH > Game::SCREEN_WIDTH)
		x = Game::SCREEN_WIDTH - WIDTH;
}

void Paddle::add_to_x(int new_x) {
	x += new_x;

	if (x < 0)
		x = 0;
	else if (x + WIDTH > Game::SCREEN_WIDTH)
		x = Game::SCREEN_WIDTH - WIDTH;
}