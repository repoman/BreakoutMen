#include "Paddle.h"


Paddle::Paddle() {
	mPosX = 0;
	mPosY = 0;

	mVelX = 0;


}

void Paddle::handleEvent(SDL_Event& e) {
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT: mVelX -= PADDLE_SPEED; break;
		case SDLK_RIGHT: mVelX += PADDLE_SPEED; break;
		}
	}

	else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT: mVelX += PADDLE_SPEED; break;
		case SDLK_RIGHT: mVelX -= PADDLE_SPEED; break;
		}
	}
}

void Paddle::move() {
	mPosX += mVelX;

	if ((mPosX < 0) || (mPosX + PADDLE_WIDTH > GameInit::SCREEN_WIDTH)) {
		mPosX -= mVelX;
	}
}

void Paddle::render() {
	gtexture.render(mPosX, mPosY);
}