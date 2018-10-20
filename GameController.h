#pragma once
#include "Field.h"
#include "Player.h"
#include "Helper.h"
class GameController
{
public:
	GameController();
	void Game();
	~GameController();
private:
	Field * field;
	Player * player;
};

