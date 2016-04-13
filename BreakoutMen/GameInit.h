#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <cstdio>
#include <stdio.h>

class GameInit
{
public:
	GameInit();
	~GameInit();
	
	bool Init();
	void Run();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;


};

