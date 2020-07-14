#pragma once
#include <SDL.h>

namespace SI
{
	class GameObject
	{
		public:
			GameObject();
			GameObject(const char* texturePath);
			~GameObject();

			virtual void Update();
			virtual void Render();
			void SetPos(int x, int y);
			void SetSize(int w, int h);
			void SetTexture(const char* texturePath);
			SDL_Rect& GetDestinationRect();

		private:
			SDL_Texture* objTexture;
			SDL_Rect destRect;
	};
}
