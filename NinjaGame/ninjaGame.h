//INCLUDE GUARDS
#pragma once
#ifndef WTF_NINJA_GAME_H
#define WTF_NINJA_GAME_H

//INLCUDE
#include "global.h"
#include "game.h"

//USING
using ftw::Game;

//NAMESPACE
namespace wtf
{
	//NINJA GAME HEADER
	class NinjaGame : public Game
	{
	private:

		//FIELDS

	protected:

		//INITIALIZE
		virtual bool Init() override;

		//LOAD
		virtual bool Load() override;

		//UPDATE
		virtual void Update() override;

		//RENDER
		virtual void Render() override;

		//UNLOAD
		virtual bool Unload() override;

	public:

		//CONSTRUCTOR
		NinjaGame();

		//DECONSTRUCTOR
		~NinjaGame();
	};
}

//END GUARDS
#endif