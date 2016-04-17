#pragma once
class Ball
{
public:
	Ball();
	~Ball();
	void Move(int time);
	void render();
	static const int width = 32;
	static const int height = 32;
	int x, y;
	int xVelocity, yVelocity;
};

