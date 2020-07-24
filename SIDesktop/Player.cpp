#include "Player.h"
#include "TextureManager.h"
#include "SIMath.h"
#include "Game.h"

SI::Player::Player(const char* texturePath, int x, int y, int w, int h)
{
	this->SetTexture(texturePath);
	this->SetPos(x, y);
	this->SetSize(w, h);
}

SI::Player::~Player()
{
}

void SI::Player::Update()
{
	SDL_Rect& dest = this->GetDestinationRect();

	switch (SI::Game::Event.type)
	{
		case SDL_KEYDOWN:
			switch (SI::Game::Event.key.keysym.sym)
			{
				case SDLK_LEFT:
					dest.x -= 5;
					break;
				case SDLK_RIGHT:
					dest.x += 5;
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
}