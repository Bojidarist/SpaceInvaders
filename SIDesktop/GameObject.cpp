#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"

SI::GameObject::GameObject()
{
	SI::GameObject::destRect = { 0,0,0,0 };
	SI::GameObject::objTexture = nullptr;
}

SI::GameObject::GameObject(const char* texturePath)
{
	destRect = { 0,0,0,0 };

	objTexture = SI::TextureManager::LoadTextureBMP(texturePath);
}

SI::GameObject::~GameObject()
{
}

void SI::GameObject::Update()
{
	
}

void SI::GameObject::Render()
{
	SDL_RenderCopy(SI::Game::Renderer, objTexture, NULL, &destRect);
}


void SI::GameObject::SetPos(int x, int y)
{
	destRect.x = x;
	destRect.y = y;
}

void SI::GameObject::SetSize(int w, int h)
{
	destRect.w = w;
	destRect.h = h;
}

void SI::GameObject::SetTexture(const char* texturePath)
{
	objTexture = SI::TextureManager::LoadTextureBMP(texturePath);
}

SDL_Rect SI::GameObject::GetDestinationRect()
{
	return destRect;
}
