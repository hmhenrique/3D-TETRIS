#pragma once
class Manager
{
public:
	/*
	* Le constructeur.
	*/
	Manager();

	int points, nivel = 1;
	Grid g = Grid();
	bool restart_;
	int rotategrid = 0;

	int indice = 1;

	Menu m;

	Text t;

	clock_t tInicio = clock();


	/*
	* v�rifier l'index et rend la sc�ne appropri�e
	* appelle les fonctions Scene_Game_play(), Scene_Game_menu() ou Scene_Game_over() de Manager
	*/
	void playGame();

	/*
	* v�rifier l'index et activer les fonctions du qui sont appropri�
	* appelle les fonctions inactiveMenu() et activeMenu() de menu, les fonctions popChar() et addChar() de Player,
	* les fonctions moveXp(), moveXn(), moveZp(), moveZn(), rotateBlock_x(), rotateBlock_y(), rotateBlock_z() et fallBlock() de Grid
	* et la fonction restart() de Manager
	*/
	void KeyboardGL(unsigned char c, int x, int y);

	/*
	* reset le jeu pour recomencer.
	* appelle la fonction restart() de Grid et la fonction resetPoints() de Player 
	*/
	void restart();

	/*
	* faites pivoter les positions de r�f�rence pour que la "Grid" soit dessin�e dans une autre position.
	* chaque somme dans 'rotategrid' repr�sente 90 degr�s suppl�mentaires, donc en ajoutant 90 quatre fois, ce serait 360, revenant � 0
	*/
	void rotateGrid();

	/*
	* pr�parer la sc�ne pour jouer
	* appelle les fonctions returnLevel(), addPoints(), getName(), getLevel(), getPoints() de Player,  
	*		les fonctions fallBlock(), drawFullFakeGrid(), drawGrid() et deleteLine() de Grid,
	*		les fonctions showName(), showLevel(), showPoints(), showCommands() de Text
	*/
	void Scene_Game_play();

	/*
	* pr�parer la sc�ne pour le fin de jouer
	* appelle les fonctions drawFullFakeGrid() et drawGrid() de Grid,
	*		les fonctions showName(), showLevel(), showPoints(), showCommands() de Text,
	*		la fonction statusMenu() de Menu
	*/
	void Scene_Game_over();

	/*
	* pr�parer la sc�ne du Menu
	* appelle la fonction drawLogo() de Grid,
	*		les fonctions printMenu() et statusMenu() de Menu
	*/
	void Scene_Game_menu();

};