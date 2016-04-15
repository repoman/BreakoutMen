#include "SDL.h"
#include "GameManager.h"

class Paddle: public GameManager
{
public:
	Paddle(SDL_Renderer* renderer);
	~Paddle();

	void Update(float delta);
	void Render(float delta);

private:
	SDL_Texture* texture;
};