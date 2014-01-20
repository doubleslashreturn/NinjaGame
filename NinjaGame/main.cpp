//INCLUDE
#include "game.h"

//USING
using ftw::Game;

//MAIN METHOD (ENTRY POINT)
int main(int argc, char * args[])
{
	//create, run, destory game
	Game * game = new Game();
	int result = game->Run();
	delete game;

	//return result
	return result;
}