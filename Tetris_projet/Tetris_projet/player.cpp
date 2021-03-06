#include "libs.h"

Player::Player() {}

int Player::returnLevel()
{
	if (points < 100) {
		level = 1;
	}
	else if (points < 500) {
		level = 2;
	}
	else {
		level = 3;
	}

	return level;
}

void Player::addChar(char c)
{
	name.push_back(c);
}

void Player::popChar()
{
	if(name.size() > 0)
		name.pop_back();
}

void Player::addPoints(int num_lines)
{
	if (num_lines == 1)
		points += 40 * level;

	else if (num_lines == 2)
		points += 100 * level;

	else if (num_lines == 3)
		points += 300 * level;
}

void Player::resetPoints()
{
	points = 0;
}


int Player::getLevel() {
	return level;
}
int Player::getPoints() {
	return points;
}
std::string Player::getName() {
	return name;
}
