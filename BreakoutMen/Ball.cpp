#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"
#include "Game.h"

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
	dx = speed/2;
	dy = -speed/2;

	status = 2;

	x = paddle->get_x();
	y = paddle->get_y()-this->HEIGHT;
}

void Ball::bounces_off(Paddle *paddle) {
	int hitSpot = ((x+(WIDTH/2)) - (paddle->get_x() + (paddle->WIDTH / 2)));

	dx = hitSpot/5;
	dy *= -1;
}


bool Ball::roof_collision() {
	return y + dy < 0;
}

bool Ball::wall_collision()
{
	return (x + dx <= 0) || (x + dx + WIDTH >= Game::SCREEN_WIDTH);
}

bool Ball::collides_with(Paddle *paddle) {
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
	if ((x > brick->get_x() &&
	x < brick->get_x() + brick->WIDTH) && (y > brick->get_y() &&
		y < brick->get_y() + brick->HEIGHT))
	{
		return true;
	} else {
	return false;
	}
}

void Ball::reset(Paddle *paddle) {
	x = paddle->get_x();
	y = paddle->get_y() - this->HEIGHT / 2;

	dx = 0;
	dy = 0;
	status = 0;

	speed = 8;
}