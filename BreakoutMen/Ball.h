#pragma once

class Brick;
class Paddle;

class Ball
{
  public:
	Ball(Paddle* paddle);
	~Ball();

	//ball status
	int status;
	
	//Ball dimensions
	static const int WIDTH;
	static const int HEIGHT;

	//ball position
	int x;
	int y;

	// ball movements
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