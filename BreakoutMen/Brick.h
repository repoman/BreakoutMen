#pragma once
class Brick
{
public:
	Brick(int x, int y);

	Brick();

	int x;
	int y;
	
	// Brick dimensions
	static const int WIDTH;
	static const int HEIGHT;
	bool dead;
};