#include "Player.h"
#include "TextureManager.h"
#include "SIMath.h"
#include "Game.h"

SI::Player::Player(const char* texturePath, int x, int y, int w, int h)
{
	fireObj = new GameObject("resources/sprites/sprite_03.bmp");
	fireObj->SetSize(15, 15);

	width = w;
	height = h;

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
					dest.x = SI::SIMath::Clamp(dest.x - 5, 0, 800);
					break;
				case SDLK_RIGHT:
					dest.x = SI::SIMath::Clamp(dest.x + 5, 0, 800 - width);
					break;
				case SDLK_SPACE:
					if (fireObj->GetDestinationRect().y < 0)
					{
						fireObj->SetPos(dest.x + (width / 4), dest.y);
					}
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}

	if (fireObj->GetDestinationRect().y >= -15)
	{
		fireObj->GetDestinationRect().y -= 3;
		auto enemies = SI::Game::Wave->GetEnemies();
		for (size_t i = 0; i < enemies.size(); i++)
		{
			for (size_t j = 0; j < enemies[i].size(); j++)
			{
				if (SDL_HasIntersection(&fireObj->GetDestinationRect(), &enemies[i][j]->GetDestinationRect()))
				{
					SI::Game::Wave->RemoveEnemyAt(i, j);
					fireObj->SetPos(0, -15);
				}
			}
		}
	}
}

void SI::Player::Render()
{
	SI::GameObject::Render();

	fireObj->Render();
}