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
	* Crée la 'grid' (CubeWallEnabled[12][21][12]) et donne la valeu 1 pour les cubes qui sont dans les "murs" ou "wall"
	* appelle les fonctions createCubesWall() et newBlockToMove()
	*/
	Grid();
	virtual ~Grid();

	/*
	* parcourir la matrice de la 'grid' (CubeWallEnabled[12][21][12]) et créer un vecteur de cubes (cube_wall) 
	* avec des cubes lorsque la valeur de position est 1
	*/
	void createCubesWall();

	/*
	* Créé une piéce (block) avec le constructeur de Blocks() avec les positions initiales (xinit, yinit, zinit)
	*/
	void newBlockToMove();

	/*
	* faire la movimentation du block qui tombe à une position en bas. Cas ce n'est pas possible, la pièce s'arrete et une nouvelle pièce doit être
	* en haut du tableu
	* appelle la fonction setPosition() de Block et appelle la fonction moveToStop()
	*/
	void fallBlock();

	/*
	* ajoute le block_moving derniere position dans le vecteur blocks_stop e crée une nouvelle block_moving dans la position initiale
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
	* faire la projection de l'endroit où tombera la píèce
	* appelle la fonction setPos() de Blocks
	*/
	void setghost();

	/*
	* verifier si un plan a été complété et si oui, le détruire 
	* appelle les fonctions checkLevel() et destroyLevel() de Blocks
	* @return le nombre de plans détruits
	*/
	int deleteLine();
	/*
	* verifier si le jeu est fini
	* appelle la fonction getmax() de Blocks
	* @return True si le jeu est fini , false sinon
	*/
	bool gameoverCheck();


	/*
	* variables: width -> largeur d'un carré de la grille; height -> hauteur d'un carré de la grille; 
	*			dir -> determiner dans quel plan la grille sera dessinée (xy, xz, yz)
	* cet grid s'appelle Fake, parce que elle est seulement une representation pour l'user avoir une idée des limites du tableau, mais
	* en fait elle n'est pas responsable de limiter le tableau. et cet fonction va seulement dessinée un carré dans la fake grid avec orientation  
	* pour le plan xy, xz ou yz
	*/
	void drawFakeGrid(float width, float height, int dir);

	/*
	* variables: x -> largeur de grille dans l'axis X; y -> hauteur de la grille; z -> largeur de grille dans l'axis Z
	* cet grid s'appelle Fake, parce que elle est seulement une representation pour l'user avoir une idée des limites du tableau, mais
	* en fait elle n'est pas responsable de limiter le tableau. et cet fonction va seulement dessinée la grille qui est dessiné pour l'utilisateur 
	* avoir une notion où sont les limites du tableau
	* appelle la fonction drawFakeGrid() de Grid
	*/
	void drawFullFakeGrid(int x, int y, int z);

	/*
	* dessiné tous les bolcks dans le vecteur blocks_stop
	* appelle la fonction drawBlock() de Blocks
	*/
	void drawBlocksStop();

	/*
	* dessiné le block_moving
	* appelle la fonction drawBlock() de Blocks
	*/
	void drawBlockMoving();

	/*
	* dessiné le gjost
	* appelle la fonction drawBlock() de Blocks
	*/
	void drawGhost();

	/*
	* dessiné tous les composants qui son important pour l'utilisateur voir dans la grid
	* appelle les fonctions drawBlockMoving(), setghost(), drawGhost() et drawBlocksStop() de Grid
	*/
	void drawGrid();

	/*
	* dessiné la grid qui est vraiment utiliser pour limiter le tableau, cet function est seulement utilisé pour verifier si tous ce passe bien
	* appelle la fonction DrawCube() de Cube
	*/
	void drawCubesWall();

	/*
	* dessiné la Logo du jeu 
	* appelle la fonction drawLogo() te createLogo() de Blocks
	*/
	void drawLogo();

	/*
	* clear le vecteur blocks_stop
	*/
	void restart();
};

