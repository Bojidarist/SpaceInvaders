#pragma once

#include <SDL.h>
#include "EnemyWave.h"
#undef main

namespace SI {

	class Game
	{
		public:
			Game();
			~Game();

			void Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
			
			void StartOfFrame();
			void HandleEvents();
			void Update();
			void LateUpdate();
			void Render();
			void EndOfFrame();
			void Clean();
			void SetFPS(int fps);
			bool Running();

			static bool IsPaused;
			static SDL_Event Event;
			static SDL_Renderer* Renderer;
			static EnemyWave* Wave;

		private:
			bool isRunning;
			int fps;
			Uint32 frameStart;
			int frameTime;
			int frameDelay;
			SDL_Window* window;
	};
}