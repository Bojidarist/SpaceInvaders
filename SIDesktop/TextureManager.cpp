#include "TextureManager.h"
#include "Logger.h"
#include "Game.h"

SDL_Texture* SI::TextureManager::LoadTextureBMP(const char* fileName)
{
	SDL_Surface* surface = SDL_LoadBMP(fileName);
	if (!surface)
	{
		SI::LogError(fileName, false);
		SI::LogError(" did not load correctly", true);

		return nullptr;
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(SI::Game::Renderer, surface);
	SDL_FreeSurface(surface);

	return texture;
}