#pragma once
class Brick
{
public:
	Brick(int x, int y, int r, int g, int b);

	Brick();

	int x;
	int y;
	int r;
	int g;
	int b;
	// Brick dimensions
	static const int WIDTH;
	static const int HEIGHT;
	bool dead;

	int get_x() const;
	int get_y() const;
	int get_r() const;
	int get_g() const;
	int get_b() const;
};