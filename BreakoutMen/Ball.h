#pragma once
class Ball
{
public:
	Ball();
	~Ball();
	void Move(float tick);
	void render();
	static const int width = 10;
	static const int height = 10;

private:
	float xpos, ypos, xvel, yvel;
	
};

