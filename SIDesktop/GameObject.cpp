#include "GameObject.h"
#include "TextureManager.h"

SI::GameObject::GameObject()
{
}

SI::GameObject::GameObject(const char* texturePath, SDL_Renderer* rend)
{
	destRect = { 0,0,0,0 };

	renderer = rend;
	objTexture = SI::TextureManager::LoadTextureBMP(texturePath, renderer);
}

SI::GameObject::~GameObject()
{
}

void SI::GameObject::Update()
{
	
}

void SI::GameObject::Render()
{
	SDL_RenderCopy(renderer, objTexture, NULL, &destRect);
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

void SI::GameObject::SetTexture(const char* texturePath, SDL_Renderer* rend)
{
	renderer = rend;
	objTexture = SI::TextureManager::LoadTextureBMP(texturePath, rend);
}

SDL_Rect SI::GameObject::GetDestinationRect()
{
	return destRect;
}
