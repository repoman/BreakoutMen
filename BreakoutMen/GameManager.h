#include "SDL.h"
#include "SDL_image.h"

class GameManager
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
};