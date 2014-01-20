//INCLUDE HEADER
#include "game.h"

//NAMESPACE
namespace ftw
{
	//CONSTRUCTOR
	Game::Game() { }

	//DECONSTRUCTOR
	Game::~Game() { }

	//RUN
	int Game::Run()
	{
		//init SDL
		if(!InitSDL()) { return 1; }

		//init game
		if(!Init()) { return 1; }
		if(!Load()) { return 1; }

		while(!gameover)
		{
			Update();
			Render();
		}

		if(!Unload()) { return 1; }

		//quit SDL
		if(!QuitSDL()) { return 1; }

		//return no error
		return 0;
	}

	//INITIALIZE
	bool Game::Init()
	{
		//for testing
		gameover = false;
		kb = new Keyboard();

		return true;
	}

	//LOAD
	bool Game::Load()
	{
		//for testing
		return true;
	}

	//UPDATE
	void Game::Update()
	{
		//for testing
		if(kb->Press(SDL_SCANCODE_ESCAPE))
		{
			gameover = true;
		}
		kb->Update();
	}

	//RENDER
	void Game::Render()
	{
		//for testing
		SDL_SetRenderDrawColor(device, 0, 0, 0, 255);
		SDL_RenderClear(device);
        SDL_RenderPresent(device);
	}

	//UNLOAD
	bool Game::Unload()
	{
		//for testing
		delete kb;

		return true;
	}	

	//INIT SDL
	bool Game::InitSDL()
	{
		//init SDL
		if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			printf("Error: SDL could not initialize something! SDL Error: %s\n", SDL_GetError());
			return false;
		}
		else
		{
			//enable vsync
			if(!SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1"))
			{
				printf("Warning: Vsync not enabled!");
			}

			//todo we might not want the gpu to mess with our pixels
			//this might be turned off in the future
			if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
			{
				printf("Warning: Linear texture filtering not enabled!");
			}

			//create window as a global pointer
			window = SDL_CreateWindow(
                GAME_NAME.c_str(),
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                RES_W, RES_H,
                SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

			//check valid window pointer
			if(window == NULL)
			{
				printf("Error: SDL could not create a window! SDL Error: %s\n", SDL_GetError());
				return false;
			}
			else
			{
				//create render device as a global pointer
				device = SDL_CreateRenderer(window, -1, 0);

				//check valid device pointer
				if(device == NULL)
				{
					printf("Error: SDL could not create a render device! SDL Error: %s\n", SDL_GetError());
					SDL_DestroyWindow(window); window = NULL;
					return false;
				}
				else
				{
					//init SDL default device color
					SDL_SetRenderDrawColor(device, 0xFF, 0xFF, 0xFF, 0xFF);

					//init png format
					if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
					{
						printf("Error: SDL Image could not initalize PNG format! SDL Image Error: %s\n", IMG_GetError());
						SDL_DestroyWindow(window); window = NULL;
						SDL_DestroyRenderer(device); device = NULL;
						return false;
					}
				}
			}
			
		}

		//return no error
		return true;
	}

	//QUIT SDL
	bool Game::QuitSDL()
	{
		//destroy device
		SDL_DestroyRenderer(device);
		device = NULL;

		//destroy window
		SDL_DestroyWindow(window);
		window = NULL;

		//quit SDL subsystems
		IMG_Quit();

		//quit SDL
		SDL_Quit();

		//return no error
		return true;
	}
}