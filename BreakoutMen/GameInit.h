#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <cstdio>
#include <stdio.h>

#include "Ball.h"

class GameInit
{
public:
	const static int SCREEN_WIDTH = 640;
	const static int SCREEN_HEIGHT = 480;

	GameInit();
	~GameInit();
	
	bool Init();
	void Run();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;

	Paddle* paddle;

	/*void Clean();
	void Update(float delta);
	void Render(float delta);

	void NewGame();*/


};

