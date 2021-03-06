#pragma once

class Player
{
private:

	std::string name = "";
	int points = 0;
	int level = 1;

public:
	/*
	* Le constructeur.
	*/
	Player();

	/*
	* vérifier le nombre de points du joueur et retourner le niveau
	* @return le niveau du joueur
	*/
	int returnLevel();

	/*
	* Variable: c -> un character 
	* ajoutera le charactére c au nom du joueur
	*/
	void addChar(char c);

	/*
	* dépouiller le dernier caractère du nom du joueur
	*/
	void popChar();

	/*
	* Variable: num_lignes -> nombre de lignes qu'ont été déleté
	* ajouter un nombre de points en fonction du nombre de lignes détruites
	*/
	void addPoints(int num_lines);

	/*
	* reset la pontuation a zero
	*/
	void resetPoints();

	/*
	* @return level
	*/
	int getLevel();

	/*
	* @return points
	*/
	int getPoints();

	/*
	* @return nom
	*/
	std::string getName();
};


