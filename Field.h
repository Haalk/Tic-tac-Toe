#pragma once
#include <vector>

class Field
{
public:
	Field();
	void loadField();
	void drawField();
	bool replace(char, char);
	bool field_win(char);
	~Field();
private:
	std::vector < std::vector<char>> m_field;

};

