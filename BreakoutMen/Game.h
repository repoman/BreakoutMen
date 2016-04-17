#pragma once

#include "SDL.h"

#include <string>

class Ball;
class Paddle;
class Brick;

class Game {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	Ball* ball;
	Paddle* paddle;
	Brick* bricks[32];

	std::string font_name;
	
	SDL_Color font_color;

	SDL_Texture* press_space_to_launch;

	bool exit;

public:
	static const int SCREEN_WIDTH;
	static const int SCREEN_HEIGHT;

	Game(int argc, char *argv[]);
	~Game();
	void execute();
	void input();
	void update();
	void render();
};