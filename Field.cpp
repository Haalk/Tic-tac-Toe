#include "Field.h"
#include "Helper.h"
#include <conio.h>
Field::Field()
{
	m_field.resize(Field_size_height);
	for (int i = 0; i < Field_size_height; ++i)
		m_field[i].resize(Field_size_width);
}

void Field::loadField()
{
	char number = '1';
	for (int i = 0; i < Field_size_height; ++i)
	{
		for (int j = 0; j < Field_size_width; ++j)
		{
		 if(i%2==0)
			 m_field[i][j] = '-';
		 else if(j%2==0)
			 m_field[i][j] = '|';
		 else if (j % 2 == 1 && j!=Field_size_width)
				m_field[i][j] = number++;

		}
	}
}

void Field::drawField()
{
	system("cls");
	for (int i = 0; i < Field_size_height; ++i)
	{
		for (int j = 0; j < Field_size_width; ++j)
		{
			std::cout << m_field[i][j];
		}
		std::cout << std::endl;
	}
}

bool Field::replace(char move_char, char player_logo)
{
	for (int i = 0; i < Field_size_height; ++i)
	{
		for (int j = 0; j < Field_size_width; ++j)
		{
			if (m_field[i][j]==move_char)
			{
				m_field[i][j] = player_logo;
				return true;
			}
		}
	}
	return false;
}

bool Field::field_win(char player_logo)
{
	int counter_width = 0;
	int counter_height = 0;
	if (m_field[3][3] == player_logo)
		if (m_field[1][1] == player_logo && m_field[5][5] == player_logo
			|| m_field[1][5] == player_logo && m_field[5][1] == player_logo)
			return true;
	for (int i = 1; i < Field_size_height; i+=2)
	{
		for (int j = 1; j < Field_size_width; j+=2)
		{
			if (i % 2)
			{
					if (m_field[i][j] == player_logo)
						counter_width++;
			}
			if (j % 2)
				if (m_field[j][i] == player_logo)
					counter_height++;
			
		}
		if (counter_width == 3 || counter_height==3)
			return true; 
		else
		{
			counter_width = 0;
			counter_height = 0;
		}
	}
	return false;
}


Field::~Field()
{
}
