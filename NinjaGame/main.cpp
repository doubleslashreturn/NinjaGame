//INCLUDE
#include "game.h"
#include "ninjaGame.h"

//USING
using ftw::Game;
using wtf::NinjaGame;

//MAIN METHOD (ENTRY POINT)
int main(int argc, char * args[])
{
	//create, run, destory game
	Game * game = new NinjaGame();
	int result = game->Run();
	delete game;

	//return result
	return result;
}