#include "GameController.h"
#include <string>
#include <conio.h>

GameController::GameController()
{
	field = new Field;
	for (int i = 0; i < amount_players; ++i)
		player = new Player[amount_players];

}

void GameController::Game()
{
	using std::cout;
	using std::cin;
	using std::endl;
	cout << "\n\n\t\t\t Hello!!!\n";
	bool Game = true;
	while (Game)
	{
		for (int i = 0; i < amount_players; ++i)
		{
			cout << "Enter your name player " << i + 1 << ": ";
			player[i].set_player_name();
			cout << "Enter your logo " << player[i].player_name() << ": ";
			player[i].set_player_logo();
		}
		bool current_game = true;
		field->loadField();
		int counter_player = -1;
		field->drawField();
		while (current_game)
		{
			if (++counter_player == amount_players)
				counter_player = 0;
			player[counter_player].player_move(field);
			field->drawField();
			if (field->field_win(player[counter_player].get_player_logo()))
				current_game = false;
		}
		cout << "\n\n\t CONGRATULATIONS!!! " << player[counter_player].player_name() <<" WIN!\n\n";
		_getch();
		cout << "\t Play again? ( y/n ): ";
		char ch;
		cin >> ch;
		while (std::cin.get() != '\n')
			continue;
		if (ch == 'n' || ch == 'N')
			Game = false;
		else
		{
			system("cls");
			field->loadField();
			field->drawField();
		}
	}
}


GameController::~GameController()
{
	delete field;
	delete[] player;
}
