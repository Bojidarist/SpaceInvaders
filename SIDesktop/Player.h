#pragma once
#include "GameObject.h"

namespace SI
{
	class Player : public GameObject
	{
		public:
			Player(const char* texturePath, SDL_Renderer* rend);
			~Player();

			void Update() override;
	};
}