#include "Game.h"

SI::Game* game = nullptr;

int main()
{
	game = new SI::Game();
	
	game->Init("Space Invaders", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (game->Running())
	{
		game->HandleEvents();
		game->Update();
		game->Render();
	}

	game->Clean();

	return 0;
}