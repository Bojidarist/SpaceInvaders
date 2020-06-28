#include "Game.h"
#include "Logger.h"

void SI::Game::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) 
{
	int flags = 0;
	if (fullscreen) 
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) 
	{
		SI::LogMessage("SDL Initialized");
		
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			SI::LogMessage("Window created");
		}
		else
		{
			isRunning = false;
			SI::LogError("Window NOT created");
		}
		
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 25, 25, 25, 255);
			SI::LogMessage("Renderer created");
		}
		else
		{
			isRunning = false;
			SI::LogError("Renderer NOT created");
		}

		isRunning = true;
	}
	else
	{
		isRunning = false;
		SI::LogError("SDL was not able to initialize");
	}
}

void SI::Game::HandleEvents() 
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}

void SI::Game::Update() 
{

}

void SI::Game::Render() 
{
	SDL_RenderClear(renderer);

	// Render stuff

	SDL_RenderPresent(renderer);
}

void SI::Game::Clean() 
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	SI::LogMessage("Game cleaned");
}

bool SI::Game::Running() 
{
	return isRunning;
}

// Constructor
SI::Game::Game()
{
	isRunning = false;
	window = nullptr;
	renderer = nullptr;
}

// Destructor
SI::Game::~Game()
{

}