#pragma once
class Menu
{

private:

	Text t;

	bool menu = true;

public:

	Player player;

	/*
	* Le constructeur.
	*/
	Menu();

	/*
	* faire l'afichage du nom du joueur dans la fen�tre
	* appelle la fonction printTxt() de Text et la fonction getName() de Player
	*/
	void printName();

	/*
	* faire l'afichage des commandes dans la fen�tre
	* appelle la fonction printTxt() de Text
	*/
	void printInstructions();

	/*
	* faire l'afichage du Menu dans la fen�tre
	* appelle les fonctions printName() et printInstructions() de Menu
	*/
	void printMenu();

	/*
	* set menu �gale � true
	*/
	void activeMenu();

	/*
	* set menu �gale � false
	*/
	void inactiveMenu();

	/*
	* @return la variable menu (peut �tre true ou false)
	*/
	bool statusMenu();

};

