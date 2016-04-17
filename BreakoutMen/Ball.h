#pragma once

class Paddle;

class Ball
{
  public:
	Ball(int x, int y);
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
	bool wall_collision();
	bool collides_with(Paddle *paddle);
	void bounces_off(Paddle *paddle);
	void reset();
};