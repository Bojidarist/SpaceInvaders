#include "Player.h"
#include "TextureManager.h"
#include "SIMath.h"
#include "Game.h"

SI::Player::Player(const char* texturePath, SDL_Renderer* rend)
{
	this->SetTexture(texturePath, rend);
	this->SetSize(150, 150);
}

SI::Player::~Player()
{
}

void SI::Player::Update()
{
	SDL_Rect dest = this->GetDestinationRect();

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
				case SDLK_DOWN:
					dest.y += 5;
					break;
				case SDLK_UP:
					dest.y -= 5;
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}

	dest.x = SIMath::Clamp(dest.x, 0, 800 - dest.w);
	dest.y = SIMath::Clamp(dest.y, 0, 600 - dest.h);
	
	this->SetPos(dest.x, dest.y);
}