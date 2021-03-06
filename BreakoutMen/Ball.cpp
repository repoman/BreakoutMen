#include "Ball.h"

#include <cmath>
#include <random>
#include <SDL_stdinc.h>

#include "Paddle.h"
#include "Game.h"

namespace {
	std::random_device rd;
	std::mt19937 gen(rd());
}

const int Ball::WIDTH = 32;
const int Ball::HEIGHT = 32;

Ball::Ball(int x, int y)
{
	status = 1;

	this->x = x;
	this->y = y;

	dx = 0;
	dy = 0;

	bounce = false;
	speed = 8;
	angle = 0.0f;
}

Ball::~Ball()
{}

void Ball::launch_ball(Paddle *ai_paddle) {
	std::uniform_int_distribution<int> dir(0, 1);
	int direction = 1 + (-2)*(dir(gen) % 2);  // Either 1 or -1.

	std::uniform_int_distribution<int> ang(-60, 60);
	angle = ang(gen);  // Between -60 and 60.

	dx = direction*speed*std::cos(angle*M_PI / 180.0f);  // Speed on the x-axis.
	dy = speed*std::sin(angle*M_PI / 180.0f);  // Speed on the y-axis.

	status = 1;
}

void Ball::bounces_off(Paddle *paddle) {
	if (paddle == nullptr)
		return;

	int sign = (paddle->get_x() < Game::SCREEN_WIDTH / 2) ? 1 : -1;

	int relative_y = (y - paddle->get_y() + WIDTH);

	angle = (2.14f * relative_y - 75.0f);

	// Convert angle to radian, find its cos() and multiply by the speed.
	dx = sign*speed*std::cos(angle*M_PI / 180.0f);

	// Convert angle to radina, find its sin() and multiply by the speed.
	dy = speed*std::sin(angle*M_PI / 180.0f);
}


bool Ball::wall_collision() {
	return (y + dy < 0) || (y + WIDTH + dy >= Game::SCREEN_HEIGHT);
}

bool Ball::collides_with(Paddle *paddle) {
	if (paddle->get_x() < Game::SCREEN_WIDTH / 2) {
		// Check if collision with left paddle occurs in next frame
		if (x > paddle->get_x() + Paddle::WIDTH ||
			x < paddle->get_x() ||
			!(y + WIDTH > paddle->get_y() &&
				y <= paddle->get_y() + Paddle::HEIGHT))
			return false;
		else
			return true;
	}
	else {
		// Check if collision with right paddle occurs in next frame.
		if (x + WIDTH < paddle->get_x() ||
			x > paddle->get_x() + Paddle::WIDTH ||
			!(y + WIDTH > paddle->get_y() &&
				y <= paddle->get_y() + Paddle::HEIGHT))
			return false;
		else
			return true;
	}
}

// Reset ball to initial state.
void Ball::reset() {
	x = Game::SCREEN_WIDTH / 2 - WIDTH / 2;
	y = Game::SCREEN_HEIGHT / 2;

	// Ball is fixed.
	dx = 0;
	dy = 0;
	status = 0;

	// Speed and hit counter are reset to their initial positions.
	speed = 8;
}