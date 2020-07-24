#pragma once
#include "GameObject.h"

namespace SI
{
	class Player : public GameObject
	{
		public:
			Player(const char* texturePath, int x = 0, int y = 0, int w = 100, int h = 100);
			~Player();

			void Update() override;

		private:
			int width = 0;
			int height = 0;
			GameObject* fireObj;
	};
}