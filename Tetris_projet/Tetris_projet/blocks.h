#pragma once
class Blocks {

public:

	/*
	* Le constructeur.
	* Variables: Position x, y et z.
	* appelle les fonctions createBlock() createCubes();
	*/
	Blocks(float x_, float y_, float z_);
	Blocks();
	virtual ~Blocks();

	/*
	* Cr�e une pi�ce ou block (tetromio), en fonction des variables al�atoires random1 et random2
	* en utilisant une matrice 3x3x3 pour faciliter le positionnement.
	* @return true si une pi�ce a �t� cr��
	*/
	bool createBlock();

	/*
	* Cr�e une vecteur de cubes pour la pi�ce cr��.
	* Des cubes sont stock�s dans le vecteur cube_block
	*/
	void createCubes();

	/*
	* variable: g -> true si est une cube de la 'grid' ou le 'ghost' et false se non
	* Dessine la pi�ce, en utilisant la fonction drawCube() (class Cube) sur chaque cube du vecteur de cubes
	*/
	void drawBlock(bool g);

	/*
	* V�rifie si la position x, y, z pass�e est la position x, y, z de chaque cube du vecter qui r�present la pi�ce
	* en utilisant la fonction CheckPosition() (class Cube) sur chaque cube du vecteur de cubes
	* @return true si est la position et false se non
	*/
	bool checkPosition(float x, float y, float z);

	/*
	* variables: combien changer dans chaque direction x, y et z, le vecteur de Blocks debout sur la 'grid et le vecteur de cubes du "murs" de la grid
	* V�rifie si la position x, y, z pass�e est la position x, y, z de chaque cube
	* du vecteur de blocks (qui contient des cubes) qui repr�sent des autres pi�ces dans la 'grid' et 
	* du vecteur de cubes qui repr�sent la 'grid'
	* et donc si c'est possible, modifie des positions de chaque cube et donc de la pi�ce.
	* en utilisant la fonction CheckPosition() GetPosition() et setpos() (class Cube) sur chaque cube
	* @return true si la position de chaque cube ont �t� modifi� et false si non
	*/
	bool setPosition(float x, float y, float z, std::vector<Blocks> blocks, std::vector<Cube> wall_cube);

	/*
	* variable: la valeur d'une hauteur (niveau) y de la 'grid'
	* v�rifier combien de cubes sont au niveau indiqu�
	* @return le nombre de cubes au niveau indiqu�
	*/
	int checkLevel(float _y);

	/*
	* variable: la valeur d'une hauteur (niveau) y de la 'grid'
	* supprimer tous les cubes au niveau y indiqu�, 
	* en conservant les m�mes positions que ceux en dessous de ce niveau et en descendant (en diminuant la position y) de ceux au-dessus
	* en utilisant la fonction GetLevel() et fall() (class Cube) sur chaque cube
	*/
	void destroyLevel(float _y);


	/*
	* recherche la plus petite position de chaque axe (x, y, z) occup� par les cubes d'une pi�ce
	* @return positions dans un vecteur de taille 3, �tant [0] -> x, [1] -> y et [2] -> z
	*/
	std::vector<float> getmin(std::vector<Cube> vec);

	/*
	* recherche la plus grand position de chaque axe (x, y, z) occup� par les cubes d'une pi�ce
	* @return positions dans un vecteur de taille 3, �tant [0] -> x, [1] -> y et [2] -> z
	*/
	std::vector<float> getmax(std::vector<Cube> vec);

	/*
	* Cr�e les cubes que repr�sent le logo "TETRIS" et "3D" dans le menu
	*/
	void createLogo();

	/*
	* Dessine les cubes que repr�sent le logo "TETRIS" dans le menu
	* en utilisant la fonction DrawCube(false) dans chaque cube.
	*/
	void drawLogo();

	/*
	* Cr�e du cubes que repr�sent le logo "3D" dans le menu
	* en utilisant la fonction DrawCube(false) dans chaque cube.
	*/
	void draw3d();

	/*
	* variables qui doivent �tre publiques pour le bon fonctionnement de la rotation en 'grid'
	*/
	std::vector<Cube> cube_block;
	std::vector<Cube> cube_block_temp, cube_block_temp2;
	

private:

	int CubeEnabled[3][3][3];
	int aux[3][3][3];

	float posx, posy, posz;

	bool rot_x = true;

	std::vector<Cube> tetris_logo;
	std::vector<Cube> tetris_logo_3d;

	int random1, random2;

	GLfloat color[3];

	// block_I[3][3][3];
	int block_I_0[3][3] = { 1, 1, 1,
							0, 0, 0,
							0, 0, 0 };

	GLfloat color_block_I[3] = { 255 , 255, 0 };


	//block_L[3][3][3];

	int block_L_0[3][3] = { 1, 1, 1,
							0, 0, 1,
							0, 0, 0 };

	GLfloat color_block_L[3] = { 0 , 153, 0 };

	//block_L2[3][3][3];

	int block_L2_0[3][3] = { 0, 0, 1,
							1, 1, 1,
							0, 0, 0 };

	GLfloat color_block_L2[3] = { 153 , 51, 153 };

	//block_T[3][3][3];

	int block_T_0[3][3] = { 1, 1, 1,
							0, 1, 0,
							0, 0, 0 };

	GLfloat color_block_T[3] = { 255 , 0, 0 };

	//block_O[3][3][3];

	int block_O_0[3][3] = { 1, 1, 0,
							1, 1, 0,
							0, 0, 0 };
	int block_O_1[3][3] = { 1, 1, 0,
							1, 1, 0,
							0, 0, 0 };

	GLfloat color_block_O[3] = { 0 , 0, 255 };

	//block_S[3][3][3];

	int block_S_0[3][3] = { 1, 1, 0,
							0, 1, 1,
							0, 0, 0 };

	GLfloat color_block_S[3] = { 255 , 128, 0 };


	//block_S2[3][3][3];

	int block_S2_0[3][3] = { 0, 1, 1,
							1, 1, 0,
							0, 0, 0 };

	GLfloat color_block_S2[3] = { 255 , 102, 153 };


	//matrix null
	int block_NULL[3][3] = { 0, 0, 0,
							0, 0, 0,
							0, 0, 0 };

	//tetris
	int tetris[5][26] = { 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1,
						  0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0,
						  0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1,
						  0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
						  0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1 };

	GLfloat color_tetris[3] = { 255 , 255, 0 };

	//3D
	int trois_d[5][8] = { 1, 1, 1, 0, 1, 1, 1, 0, 
					      0, 0, 1, 0, 1, 0, 0, 1,
					      0, 1, 1, 0, 1, 0, 0, 1,
				          0, 0, 1, 0, 1, 0, 0, 1, 
					      1, 1, 1, 0, 1, 1, 1, 0};

	GLfloat color_3d[3] = { 255 , 0, 0 };
};

