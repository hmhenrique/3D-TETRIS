#pragma once
class Cube
{
	
private:

	GLfloat color_cube[3];

	float x = 0, y = 0, z = 0;

public:

	/*
	* Le constructeur.
	* Variables: Position x, y et z et la coleur
	*/
	Cube(float x_, float y_, float z_, GLfloat color[3]);
	Cube() {};
	virtual ~Cube(){}

	/*
	* Définit la position de l'objet cube
	*/
	void setpos(float x_, float y_, float z_);

	/*
	* Fait tomber le cube (par rapport à l'axe y)
	*/
	void fall();

	/*
	* Vérifie si la position x, y, z passée est la position x, y, z du cube ou non
	* @return true si est la position et false se non
	*/
	bool CheckPosition(float x_, float y_, float z_);

	/*
	* Vérifie si la position y passée est la position y du cube ou non
	* @return true si est la position et false se non
	*/
	bool CheckLevel(float _y);

	/*
	* @return la position y du cube
	*/
	float GetLevel();

	/*
	* @return les positions du cube sous la forme d'un vecteur
	*/
	std::vector<float> GetPosition();

	/*
	* variable: true si est une cube de la 'grid' ou le 'ghost' et false se non
	* dessine le cube dans les positions et couleurs respectives
	* si g est false, est une cube 'solid', sinon, est une cube 'wired'
	*/
	void DrawCube(bool g);
};

