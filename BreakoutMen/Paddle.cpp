#include "Paddle.h"
#include "Ball.h"
#include "Game.h"

const int Paddle::HEIGHT = 10;
const int Paddle::WIDTH = 60;

Paddle::Paddle(int new_x, int new_y) {
	x = new_x;
	y = new_y;
}

int Paddle::get_x() const {
	return x;
}

int Paddle::get_y() const {
	return y;
}

void Paddle::set_y(int new_y) {
	y = new_y;

	// Paddle shouldn't be allowed to go above or below the screen.
	if (y < 0)
		y = 0;
	else if (y + HEIGHT > Game::SCREEN_HEIGHT)
		y = Game::SCREEN_HEIGHT - HEIGHT;
}

void Paddle::add_to_y(int new_y) {
	y += new_y;

	// Paddle shouldn't be allowed to go above or below the screen.
	if (y < 0)
		y = 0;
	else if (y + HEIGHT > Game::SCREEN_HEIGHT)
		y = Game::SCREEN_HEIGHT - HEIGHT;
}