#pragma once

class Ball;

class Paddle
{
private:
	int x;
	int y;

public:
	Paddle(int x, int y);

	// Paddle dimensions
	static const int WIDTH;
	static const int HEIGHT;

	int get_x() const;
	int get_y() const;
	void set_y(int new_y);
	void add_to_y(int new_y);
	//int predict(Ball *ball); void AI(Ball *ball);
};