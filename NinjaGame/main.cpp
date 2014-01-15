//INCLUDES
#include <iostream>
#include <SDL.h>

//MAIN METHOD
int main(int argc, char * args[])
{
	//INIT SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	//WINDOW HANDLE
	SDL_Window * window = SDL_CreateWindow(
		"Test Game Window",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1280, 720,
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

	//RENDER DEVICE
	SDL_Renderer * device = SDL_CreateRenderer(window, -1, 0);

	//CLEAR SCREEN
	SDL_SetRenderDrawColor(device, 0, 255, 0, 255);
	SDL_RenderClear(device);
	SDL_RenderPresent(device);

	//DELAY SDL
	SDL_Delay(2000);

	//QUIT SDL
	SDL_Quit();

	//RETURN NO ERROR
	return 0;
}