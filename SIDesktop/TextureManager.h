#pragma once

#include "SDL.h"

namespace SI
{
	class TextureManager
	{
		public:
			static SDL_Texture* LoadTextureBMP(const char* fileName);
	};
}