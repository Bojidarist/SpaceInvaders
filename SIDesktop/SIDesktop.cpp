#include "Game.h"

SI::Game* game = nullptr;

int main()
{
	game = new SI::Game();

	game->Init("Space Invaders", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	game->SetFPS(60);

	while (game->Running())
	{
		game->StartOfFrame();
		game->HandleEvents();
		game->Update();
		game->LateUpdate();
		game->Render();
		game->EndOfFrame();
	}

	game->Clean();

	return 0;
}