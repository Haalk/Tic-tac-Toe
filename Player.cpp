#include "Player.h"
#include "Helper.h"
#include <limits>
Player::Player()
{
}


Player::~Player()
{
}

void Player::player_move(Field *field)
{
	bool check_move = true;
	std::string move_char;
	report_move();
	while (check_move)
	{
		std::cout << "Enter move: ";
		std::cin>>move_char;
		if (move_char[0]>='1'&&move_char[0]<='9' && move_char.length()<2&&field->replace(move_char[0], m_logo))
			check_move = false;
	}
}

std::string Player::player_name()
{
	return m_name;
}

void Player::set_player_name()
{
	std::getline(std::cin, m_name);
}

void Player::set_player_logo()
{
	 std::cin.get(m_logo);
	 while (std::cin.get() != '\n')
		 continue;
}

char Player::get_player_logo()
{
	return m_logo;
}

void Player::report_move()
{
	std::cout << m_name << " your move\n";
}
