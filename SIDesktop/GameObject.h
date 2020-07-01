#pragma once
#include <SDL.h>

namespace SI
{
	class GameObject
	{
		public:
			GameObject();
			GameObject(const char* texturePath, SDL_Renderer* rend);
			~GameObject();

			virtual void Update();
			virtual void Render();
			void SetPos(int x, int y);
			void SetSize(int w, int h);
			void SetTexture(const char* texturePath, SDL_Renderer* rend);
			SDL_Rect GetDestinationRect();

		private:
			SDL_Texture* objTexture;
			SDL_Rect destRect;
			SDL_Renderer* renderer;
	};
}
