#pragma once
class Text
{
public:
	/*
	* Le constructeur.
	*/
	Text() {};


	GLfloat color_white[3] = { 255.0f, 255.0f , 255.0f };
	GLfloat color_red[3] = { 255.0f, 0.0f , 0.0f };
	GLfloat color_gray[3] = { 79.0f, 79.0f , 79.0f };

	void* font = GLUT_BITMAP_TIMES_ROMAN_24;
	//void* font2 = GLUT_STROKE_ROMAN;
	void* font3 = GLUT_BITMAP_8_BY_13;
	void* font4 = GLUT_BITMAP_9_BY_15;
	//void* font5 = GLUT_BITMAP_TIMES_ROMAN_10;
	//void* font6 = GLUT_BITMAP_HELVETICA_10;
	//void* font7 = GLUT_BITMAP_HELVETICA_12;
	//void* font8 = GLUT_BITMAP_HELVETICA_18;

	/*
	* variables: x -> position dans l'axis X; y -> position dans l'axis Y dans la fenêtre, text -> le texte qui sera afficher dans la 
	*		fenêtre; color_text -> la couleur de le texte, font -> la font de la letre 
	* Afficher un text dans la fenêtre
	*/
	void printTxt(float x, float y, std::string text, GLfloat color_text[3], void* font);


	/*
	* variables: points -> les points du joueur
	* Afficher les points du joueur dans la fenêtre
	* appelle la fonction printTxt() de Text
	*/
	void showPoints(int points);

	/*
	* variables: level -> le level du joueur
	* Afficher le level du joueur dans la fenêtre
	* appelle la fonction printTxt() de Text
	*/
	void showLevel(int level);

	/*
	* variables: name -> les points du joueur
	* Afficher le nom du joueur dans la fenêtre
	* appelle la fonction printTxt() de Text
	*/
	void showName(std::string name);

	/*
	* Afficher les commandes dans la fenêtre
	* appelle la fonction printTxt() de Text
	*/
	void showCommands();

	/*
	* Afficher le fin de jeu dans la fenêtre
	* appelle la fonction printTxt() de Text
	*/
	void showEndGame();
};

