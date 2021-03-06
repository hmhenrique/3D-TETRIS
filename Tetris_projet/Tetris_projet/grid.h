#pragma once

class Grid
{
private:


	int CubeWallEnabled[12][21][12];
	std::vector<Blocks> blocks_stop;
	Blocks block_moving;
	Blocks ghost;
	Blocks block_temp;
	Blocks logo;
	std::vector<Cube> cube_wall;
	GLfloat colorDefault[3] = {0, 0, 0};
	float xinit = 5, yinit = 20, zinit = 5;
	
public:

	/*
	* Le constructeur.
	* Cr�e la 'grid' (CubeWallEnabled[12][21][12]) et donne la valeu 1 pour les cubes qui sont dans les "murs" ou "wall"
	* appelle les fonctions createCubesWall() et newBlockToMove()
	*/
	Grid();
	virtual ~Grid();

	/*
	* parcourir la matrice de la 'grid' (CubeWallEnabled[12][21][12]) et cr�er un vecteur de cubes (cube_wall) 
	* avec des cubes lorsque la valeur de position est 1
	*/
	void createCubesWall();

	/*
	* Cr�� une pi�ce (block) avec le constructeur de Blocks() avec les positions initiales (xinit, yinit, zinit)
	*/
	void newBlockToMove();

	/*
	* faire la movimentation du block qui tombe � une position en bas. Cas ce n'est pas possible, la pi�ce s'arrete et une nouvelle pi�ce doit �tre
	* en haut du tableu
	* appelle la fonction setPosition() de Block et appelle la fonction moveToStop()
	*/
	void fallBlock();

	/*
	* ajoute le block_moving derniere position dans le vecteur blocks_stop e cr�e une nouvelle block_moving dans la position initiale
	* appelle la fonction newBlockToMove()
	*/
	void moveToStop();


	/*
	* si possible, change la position du block en moins un dans l'axis X
	* appelle la fonction setPostion() de Blocks
	*/
	void moveXn();
	/*
	* si possible, change la position du block en plus un dans l'axis X
	* appelle la fonction setPostion() de Blocks
	*/
	void moveXp();
	/*
	* si possible, change la position du block en moins un dans l'axis Z
	* appelle la fonction setPostion() de Blocks
	*/
	void moveZn();
	/*
	* si possible, change la position du block en plus un dans l'axis Z
	* appelle la fonction setPostion() de Blocks
	*/
	void moveZp();

	/*
	* faire la rotation du block au tour de l'axis X
	* appelle les fonction getmin(), getmax() de Blocks et les fonctions GetPosition() et setpos() de Cube
	*/
	void rotateBlock_x();
	/*
	* faire la rotation du block au tour de l'axis Y
	* appelle les fonction getmin(), getmax() de bBocks et les fonctions GetPosition() et setpos() de Cube
	*/
	void rotateBlock_y();
	/*
	* faire la rotation du block au tour de l'axis Z
	* appelle les fonction getmin(), getmax() de Blocks et les fonctions GetPosition() et setpos() de Cube
	*/
	void rotateBlock_z();


	/*
	* faire la projection de l'endroit o� tombera la p��ce
	* appelle la fonction setPos() de Blocks
	*/
	void setghost();

	/*
	* verifier si un plan a �t� compl�t� et si oui, le d�truire 
	* appelle les fonctions checkLevel() et destroyLevel() de Blocks
	* @return le nombre de plans d�truits
	*/
	int deleteLine();
	/*
	* verifier si le jeu est fini
	* appelle la fonction getmax() de Blocks
	* @return True si le jeu est fini , false sinon
	*/
	bool gameoverCheck();


	/*
	* variables: width -> largeur d'un carr� de la grille; height -> hauteur d'un carr� de la grille; 
	*			dir -> determiner dans quel plan la grille sera dessin�e (xy, xz, yz)
	* cet grid s'appelle Fake, parce que elle est seulement une representation pour l'user avoir une id�e des limites du tableau, mais
	* en fait elle n'est pas responsable de limiter le tableau. et cet fonction va seulement dessin�e un carr� dans la fake grid avec orientation  
	* pour le plan xy, xz ou yz
	*/
	void drawFakeGrid(float width, float height, int dir);

	/*
	* variables: x -> largeur de grille dans l'axis X; y -> hauteur de la grille; z -> largeur de grille dans l'axis Z
	* cet grid s'appelle Fake, parce que elle est seulement une representation pour l'user avoir une id�e des limites du tableau, mais
	* en fait elle n'est pas responsable de limiter le tableau. et cet fonction va seulement dessin�e la grille qui est dessin� pour l'utilisateur 
	* avoir une notion o� sont les limites du tableau
	* appelle la fonction drawFakeGrid() de Grid
	*/
	void drawFullFakeGrid(int x, int y, int z);

	/*
	* dessin� tous les bolcks dans le vecteur blocks_stop
	* appelle la fonction drawBlock() de Blocks
	*/
	void drawBlocksStop();

	/*
	* dessin� le block_moving
	* appelle la fonction drawBlock() de Blocks
	*/
	void drawBlockMoving();

	/*
	* dessin� le gjost
	* appelle la fonction drawBlock() de Blocks
	*/
	void drawGhost();

	/*
	* dessin� tous les composants qui son important pour l'utilisateur voir dans la grid
	* appelle les fonctions drawBlockMoving(), setghost(), drawGhost() et drawBlocksStop() de Grid
	*/
	void drawGrid();

	/*
	* dessin� la grid qui est vraiment utiliser pour limiter le tableau, cet function est seulement utilis� pour verifier si tous ce passe bien
	* appelle la fonction DrawCube() de Cube
	*/
	void drawCubesWall();

	/*
	* dessin� la Logo du jeu 
	* appelle la fonction drawLogo() te createLogo() de Blocks
	*/
	void drawLogo();

	/*
	* clear le vecteur blocks_stop
	*/
	void restart();
};

