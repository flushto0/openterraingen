#include <SDL.h>
#include <gl/glew.h>
#include "imgui/imgui.h"

void shutdown(SDL_Window*);

int main(int argc, char *argv[])
{
	SDL_Window *window;
	SDL_Event currentEvent;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
	{
		SDL_Log("SDL was unable to initialize. %s", SDL_GetError());
		return 1;
	}
	window = SDL_CreateWindow("OpenTerrain", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_OPENGL);
	if (window == nullptr) SDL_Log("The SDL window could not be created. %s", SDL_GetError());

	while (true)
	{
		SDL_PollEvent(&currentEvent);
		if (currentEvent.type == SDL_WINDOWEVENT)
		{
			switch (currentEvent.window.event)
			{
				case SDL_WINDOWEVENT_CLOSE:
					shutdown(window);
					break;
			}
		}
	}

	shutdown(window);
	return 0;
}

void shutdown(SDL_Window *window)
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}