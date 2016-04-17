#include "Game.h"
#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"
#include "Utilities.h"

#include <iostream>
#include <SDL_ttf.h>

const int Game::SCREEN_WIDTH = 640;
const int Game::SCREEN_HEIGHT = 480;

Game::Game(int argc, char *argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("Breakout Men",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
		SDL_RENDERER_PRESENTVSYNC);

	paddle = new Paddle(SCREEN_WIDTH/2, SCREEN_HEIGHT - 20);
	ball = new Ball(paddle);

	for (int i = 0;i < 32;i++)
	{
		int x = i * (SCREEN_WIDTH / 8) + 3;
		int y = 0;
		int r = 255;
		int g = 0;
		int b = 0;
		if (i > 7 && i < 16)
		{
			x = x - SCREEN_WIDTH;
			y = 20;
			r = 0;
			g = 255;
			b = 0;
		}
		if (i > 15 && i < 24)
		{
			x = x - (SCREEN_WIDTH * 2);
			y = 20 * 2;
			r = 0;
			g = 0;
			b = 255;
		}
		if (i > 23 && i < 33)
		{
			x = x - (SCREEN_WIDTH * 3);
			y = 20 * 3;
			r = 255;
			g = 255;
			b = 0;
		}
		y = y + 3;
		bricks[i] = new Brick(x, y, r, g, b);
	}
	
	TTF_Init();
	font_color = { 255, 255, 255, 255 };
	font_name = "Lato-Regular.ttf";
	press_space_to_launch = renderText("Press SPACE to start",
		font_name, font_color, 18, renderer);

	exit = false;
}

Game::~Game() {
	SDL_DestroyTexture(press_space_to_launch);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::execute() {
	while (!exit) {
		input();
		update();
		render();
		SDL_Delay(10);
	}
}

void Game::input() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {

		if (event.type == SDL_QUIT) {
			exit = true;
		}

		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
			case SDLK_ESCAPE:
				exit = true;
				break;

			case SDLK_SPACE:
				if (ball->status == 0) {
					ball->status = 1;
				}
				break;

			case SDLK_LEFT:
				paddle->leftKeyDown = true;
				break;

			case SDLK_RIGHT:
				paddle->rightKeyDown = true;
				break;
			}
		}

		if (event.type == SDL_KEYUP)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_LEFT:
				paddle->leftKeyDown = false;
				break;

			case SDLK_RIGHT:
				paddle->rightKeyDown = false;
				break;
			}
		}
	}
}

void Game::update() {

	//Kontroller
	if (paddle->leftKeyDown)
	{
		paddle->add_to_x(-10);
	}
	if (paddle->rightKeyDown)
	{
		paddle->add_to_x(10);
	}

	//Skyt ballen
	if (ball->status == 0) {
		return;
	}

	else if (ball->status == 1) {
		ball->launch_ball(paddle);
	}

	if (ball->collides_with(paddle)) {
		ball->bounces_off(paddle);
	}

	if (ball->roof_collision()) {
		ball->dy *= -1;
	}

	if (ball->wall_collision())
	{
		ball->dx *= -1;
	}

	for (int i = 0;i < 32;i++)
	{
		if (!bricks[i]->dead && ball->collides_with_brick(bricks[i]))
		{
			bricks[i]->dead = true;
			ball->dy *= -1;
		}
	}

	ball->x += ball->dx;
	ball->y += ball->dy;

	if (ball->y > SCREEN_HEIGHT) {
		ball->reset(paddle);
	}
}

void Game::render() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	//Rendre brikkan
	for (int i = 0;i < 32;i++)
	{
		if (!bricks[i]->dead)
		{
			SDL_Rect brick = { bricks[i]->x, bricks[i]->y, bricks[i]->WIDTH, bricks[i]->HEIGHT };
			SDL_SetRenderDrawColor(renderer, bricks[i]->get_r(), bricks[i]->get_g(), bricks[i]->get_b(), 255);
			SDL_RenderFillRect(renderer, &brick);
		}
	}

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	//Rendre ballen
	SDL_Rect paddleRect = { paddle->get_x(),
		paddle->get_y(),
		Paddle::WIDTH, Paddle::HEIGHT };
	SDL_RenderFillRect(renderer, &paddleRect);

	//Rendre ballen
	SDL_Rect pong_ball = { ball->x, ball->y, ball->WIDTH, ball->WIDTH };
	SDL_RenderFillRect(renderer, &pong_ball);

	

	if (ball->status == 0) {
		renderTexture(press_space_to_launch,
			renderer, SCREEN_WIDTH / 2 - 120, SCREEN_HEIGHT / 2);
	}

	SDL_RenderPresent(renderer);
}