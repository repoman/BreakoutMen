#include "SDL.h"
#include "math.h"
#include "time.h"
#include "Defines.h"
#include "Enums.h"
#include <stack>

class Main
{
public:
	Entity paddle;
	Entity ball;
	int game_score;

	void Menu();
	void Game();
	void Exit();
	void GameWon();
	void GameLost();

	void ClearScreen();
	void HandleMenuInput();
	void HandleGameInput();
	void HandleExitInput();
	void HandleWinLoseInput();
	bool CheckWallCollisions(Entity& entity, Direction dir);
	bool CheckBallCollisions(Entity& paddle);
	void HandleBall();
	void MoveBall();
	void HandlePlayerScore();

	void Init();
	void Shutdown();
};

