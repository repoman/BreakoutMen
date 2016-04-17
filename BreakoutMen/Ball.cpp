#include "Ball.h"

#include <cmath>
#include <random>
#include <SDL_stdinc.h>

#include "Paddle.h"
#include "Brick.h"
#include "Game.h"

namespace {
	std::random_device rd;
	std::mt19937 gen(rd());
}

const int Ball::WIDTH = 16;
const int Ball::HEIGHT = 16;

Ball::Ball(Paddle* paddle)
{
	status = 0;

	x = paddle->get_x();
	y = paddle->get_y() - this->HEIGHT;

	dx = 0;
	dy = 0;

	bounce = false;
	speed = 8;
	angle = 0.0f;
}

Ball::~Ball()
{}

void Ball::launch_ball(Paddle *paddle) {
	std::uniform_int_distribution<int> dir(0, 1);
	int direction = 1 + (-2)*(dir(gen) % 2);  // Either 1 or -1.

	std::uniform_int_distribution<int> ang(-60, 60);
	angle = ang(gen);  // Between -60 and 60.

	dx = speed/2;
	dy = -speed/2;

	status = 2;

	x = paddle->get_x();
	y = paddle->get_y()-this->HEIGHT;
}

void Ball::bounces_off(Paddle *paddle) {
	int hitSpot = ((x+(WIDTH/2)) - (paddle->get_x() + paddle->WIDTH) / 2);

	
	/*
	int sign = (paddle->get_x() < Game::SCREEN_WIDTH / 2) ? 1 : -1;

	int relative_y = (y - paddle->get_y() + WIDTH);

	angle = (2.14f * relative_y - 75.0f);

	// Convert angle to radian, find its cos() and multiply by the speed.
	dx = sign*speed*std::cos(angle*M_PI / 180.0f);

	// Convert angle to radina, find its sin() and multiply by the speed.
	dy = speed*std::sin(angle*M_PI / 180.0f);
	*/
}


bool Ball::roof_collision() {
	return y + dy < 0;
}

bool Ball::wall_collision()
{
	return (x + dx <= 0) || (x + dx + WIDTH >= Game::SCREEN_WIDTH);
}

bool Ball::collides_with(Paddle *paddle) {
	// Sjekk om ballen kolliderer med paddle i neste frame
	if (x > paddle->get_x() + Paddle::WIDTH ||
		x < paddle->get_x() ||
		!(y + WIDTH > paddle->get_y() &&
			y <= paddle->get_y() + Paddle::HEIGHT))
		return false;
	else
		return true;
}

bool Ball::collides_with_brick(Brick *brick)
{
	// Check if collision with left paddle occurs in next frame
	if ((x > brick->get_x() &&
	x < brick->get_x() + brick->WIDTH) && (y > brick->get_y() &&
		y < brick->get_y() + brick->HEIGHT))
	{
		return true;
	} else {
	return false;
	}
}


// Reset ball to initial state.
void Ball::reset(Paddle *paddle) {
	x = paddle->get_x();
	y = paddle->get_y() - this->HEIGHT / 2;

	// Ball is fixed.
	dx = 0;
	dy = 0;
	status = 0;

	// Speed and hit counter are reset to their initial positions.
	speed = 8;
}