#pragma once

class Brick;
class Paddle;

class Ball
{
  public:
	Ball(Paddle* paddle);
	~Ball();

	int status;
	
	static const int WIDTH;
	static const int HEIGHT;

	int x;
	int y;

	int dx;
	int dy;

	bool bounce;

	int speed;
	float angle;

	void launch_ball(Paddle *paddle);
	bool roof_collision();
	bool wall_collision();
	bool collides_with(Paddle *paddle);
	bool collides_with_brick(Brick *brick);
	void bounces_off(Paddle *paddle);
	void reset(Paddle *paddle);
};