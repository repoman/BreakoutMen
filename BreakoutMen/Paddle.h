#pragma once

class Ball;

class Paddle
{
private:
	int x;
	int y;

public:
	Paddle(int x, int y);

	bool leftKeyDown;
	bool rightKeyDown;

	static const int WIDTH;
	static const int HEIGHT;

	int get_x() const;
	int get_y() const;
	void set_x(int new_x);
	void add_to_x(int new_x);
};