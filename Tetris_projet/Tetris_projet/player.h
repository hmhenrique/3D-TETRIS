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
	* v�rifier le nombre de points du joueur et retourner le niveau
	* @return le niveau du joueur
	*/
	int returnLevel();

	/*
	* Variable: c -> un character 
	* ajoutera le charact�re c au nom du joueur
	*/
	void addChar(char c);

	/*
	* d�pouiller le dernier caract�re du nom du joueur
	*/
	void popChar();

	/*
	* Variable: num_lignes -> nombre de lignes qu'ont �t� d�let�
	* ajouter un nombre de points en fonction du nombre de lignes d�truites
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


