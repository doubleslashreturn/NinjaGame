//INCLUDE HEADER
#include "ninjaGame.h"

//NAMESPACE
namespace wtf
{
	//CONSTRUCTOR
	NinjaGame::NinjaGame()
		: Game(GAME_NAME, RES_W, RES_H) { }

	//DECONSTRUCTOR
	NinjaGame::~NinjaGame() { }

	//INITIALIZE
	bool NinjaGame::Init() { return true; }

	//LOAD
	bool NinjaGame::Load() { return true; }

	//UPDATE
	void NinjaGame::Update() { Game::Update(); }

	//RENDER
	void NinjaGame::Render() { Game::Render(); }

	//UNLOAD
	bool NinjaGame::Unload() { return true; }
}