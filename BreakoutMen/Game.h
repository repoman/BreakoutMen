#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

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

	enum Controllers { mouse, keyboard, joystick };
	Controllers controller;

	std::string font_name;

	SDL_Color font_color;

	SDL_Texture* font_image_left_score;
	SDL_Texture* font_image_right_score;
	SDL_Texture* font_image_winner;
	SDL_Texture* font_image_restart;

	SDL_Texture* font_image_launch;

	int left_score;

	bool left_score_changed;

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