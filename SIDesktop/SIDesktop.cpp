#include <iostream>
#include <SDL.h>
#undef main

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	
	SDL_Window* window = SDL_CreateWindow("Space Invaders", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 25, 25, 25, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	SDL_Delay(5000);

	return 0;
}