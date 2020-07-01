#include "Game.h"
#include "Logger.h"
#include "GameObject.h"
#include "Player.h"

SI::Player* player;

SDL_Event SI::Game::Event;

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

	player = new Player("test.bmp", renderer);
}

void SI::Game::SetFPS(int fps)
{
	this->fps = fps;
}

void SI::Game::StartOfFrame()
{
	frameStart = SDL_GetTicks();
	frameDelay = 1000 / fps;
}

void SI::Game::HandleEvents() 
{
	SDL_PollEvent(&Event);

	switch (Event.type)
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
	player->Update();
}

void SI::Game::LateUpdate()
{
	
}

void SI::Game::Render() 
{
	SDL_RenderClear(renderer);

	// Render stuff
	player->Render();

	SDL_RenderPresent(renderer);
}

void SI::Game::EndOfFrame()
{
	frameTime = SDL_GetTicks() - frameStart;
	if (frameDelay > frameTime)
	{
		SDL_Delay(frameDelay - frameTime);
	}
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
	frameStart = 0;
	frameTime = 0;
	fps = 30;
	frameDelay = 1000 / fps;
}

// Destructor
SI::Game::~Game()
{

}