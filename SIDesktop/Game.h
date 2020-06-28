#pragma once

#include <SDL.h>
#undef main

namespace SI {

	class Game
	{
		public:
			Game();
			~Game();

			void Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
			
			void HandleEvents();
			void Update();
			void Render();
			void Clean();

			bool Running();

		private:
			bool isRunning;
			SDL_Window* window;
			SDL_Renderer* renderer;

	};
}