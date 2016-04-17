#include "GameManager.h"

GameManager::GameManager(SDL_Renderer* renderer) {
	this->renderer = renderer;

	x = 0;
	y = 0;
	width = 1;
	height = 1;
}

GameManager::~GameManager()
{
}

void GameManager::Update(float delta) {
}

void GameManager::Render(float delta) {
}

bool GameManager::Collides(GameManager* other) {
	if (x + width > other->x && x < other->x + other->width &&
		y + height > other->y && y < other->y + other->height) {
		return true;
	}
	return false;
}
