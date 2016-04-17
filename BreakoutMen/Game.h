#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

/*class GameManager
{
	public:
		GameManager(SDL_Renderer* renderer);
		virtual ~GameManager();

		float x, y, width, height;

		virtual void Update(float delta);
		virtual void Render(float delta);

		bool Collides(GameManager* other);
	protected:
		SDL_Renderer* renderer;
};*/

//#include <SDL2/SDL.h>                       // SDL library.
//#include <SDL_ttf.h>                   // SDL font library.
//#include <SDL2/SDL_mixer.h>                 // SDL sound library.

#include <string>

class Ball;
class Paddle;

class Game {
private:
	// Window and renderer.
	SDL_Window* window;  // Holds window properties.
	SDL_Renderer* renderer;  // Holds rendering surface properties.

							 // Game objects.
	Ball* ball;
	Paddle* left_paddle;
	Paddle* right_paddle;

	// Sounds.
	// Holds sound produced after ball collides with paddle.
	/*Mix_Chunk* paddle_sound;

	// Holds sound produced after ball collides with wall.
	Mix_Chunk* wall_sound;

	// Holds sound produced when updating score.
	Mix_Chunk* score_sound;*/

	// Controllers.
	enum Controllers { mouse, keyboard, joystick };
	Controllers controller;
	//SDL_Joystick *gamepad;  // Holds joystick information.
	//int gamepad_direction;  // gamepad direction.
	//int mouse_x, mouse_y;  // Mouse coordinates.

						   // Fonts.

						   // Font name.
	std::string font_name;

	// Font color.
	SDL_Color font_color;

	// Holds text indicating player 1 score (left).
	SDL_Texture* font_image_left_score;

	// Holds text indicating palyer 2 score (right).
	SDL_Texture* font_image_right_score;

	// Holds text indicating winner.
	SDL_Texture* font_image_winner;

	// Holds text suggesting to restart the game.
	SDL_Texture* font_image_restart;

	// Holds first part of text suggesting to launch the ball.
	SDL_Texture* font_image_launch;

	// Scores.
	int left_score;

	// Indicates when rendering new score is necessary.
	bool left_score_changed;

	// Game status.
	bool exit;  // True when player wants to exit game.

public:
	// Screen resolution.
	static const int SCREEN_WIDTH;
	static const int SCREEN_HEIGHT;

	Game(int argc, char *argv[]);
	~Game();
	void execute();
	void input();
	void update();
	void render();
};