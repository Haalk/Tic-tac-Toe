#pragma once
#include "Field.h"
#include <string>
class Player
{
public:
	Player();
	~Player();
	void player_move(Field *);
	std::string player_name();
	void set_player_name();
	void set_player_logo();
	char get_player_logo();
	void report_move();
private:
	char m_logo;
	std::string m_name;

};

