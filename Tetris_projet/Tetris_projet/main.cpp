/*
* Ajouter toutes les header files et librairies
*/
#include "libs.h"

/*
* Parametres pour la fenêtre
*/
int g_iWindowWidth = 800;
int g_iWindowHeight = 560;
int g_iGLUTWindowHandle = 0;
int g_iErrorCode = 0;


/*
* OpenGL Outils
*/
void InitGL(int argc, char* argv[]);
void DisplayGL();
void KeyboardGL(unsigned char c, int x, int y);
void ReshapeGL(int w, int h);
void Cleanup(int exitCode, bool bExit = true);

/*
* Instance de la classe Manager
*/
Manager manager;


/*
* La fonction main() qui appelle les outils OpenGL
*/
int main(int argc, char* argv[])
{
    InitGL(argc, argv);
    glutMainLoop();
    Cleanup(g_iErrorCode);
}

/*
* Fonction openGL principale d'openGL, responsable de la gestion des fenêtres et de l'appel des outils openGL
*/
void InitGL(int argc, char* argv[])
{
    std::cout << "Initialise OpenGL..." << std::endl;

    glutInit(&argc, argv);
    int iScreenWidth = glutGet(GLUT_SCREEN_WIDTH);
    int iScreenHeight = glutGet(GLUT_SCREEN_HEIGHT);

    glutInitDisplayMode(GLUT_RGBA | GLUT_ALPHA | GLUT_DOUBLE | GLUT_DEPTH);

    glutInitWindowPosition((iScreenWidth - g_iWindowWidth) / 2,
        (iScreenHeight - g_iWindowHeight) / 2);
    glutInitWindowSize(g_iWindowWidth, g_iWindowHeight);

    g_iGLUTWindowHandle = glutCreateWindow("TETRIS 3D");

    // Register GLUT callbacks
    glutDisplayFunc(DisplayGL);
    glutKeyboardFunc(KeyboardGL);
    glutReshapeFunc(ReshapeGL);

    // Setup initial GL State
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);

    glShadeModel(GL_SMOOTH);

    std::cout << "Initialise OpenGL: Success!" << std::endl;
}

/*
* Fonction openGL qui configure la vue du jeu et appelle la fonction playGame() de la classe Manager, démarrant ainsi le jeu
*/
void DisplayGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluPerspective(-45.0, 1, 10.0, 100.0);       

    glLoadIdentity();

    glEnable(GL_DEPTH_TEST);

    glTranslatef(-7.0f, -10.0f, -35.0f);       // fonction translate du openGL essentiel pour tout les affichages
    glRotatef(45.f, 0.0f, -1.f, 0.0f);         // fonction rotate du openGL essentiel pour la rotation de la grid
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();                                                      

    manager.playGame();   // init le jeu

    glPopMatrix();
    glFlush();

    glutSwapBuffers();
    glutPostRedisplay();
}


/*
* Fonction openGL qui gerencie le clavier et appelle la fonction KeyboardGL de Manager et 
* ajoute une autre "clé" par défaut pour toutes les scènes
*/
void KeyboardGL(unsigned char c, int x, int y)
{
    
    manager.KeyboardGL(c, x, y);
    glutPostRedisplay();

    switch (c) {
    case 27:  // represents [ESC]
    {
        Cleanup(0);
    }
    break;
    }
    
}


/*
* Fonction openGL qui gerencie de changement du taille de la fenetre
*/
void ReshapeGL(int w, int h)
{
    std::cout << "ReshapGL( " << w << ", " << h << " );" << std::endl;

    if (h == 0)										// Prevent A Divide By Zero error
        h = 1;										// Making Height Equal One

    g_iWindowWidth = w;
    g_iWindowHeight = h;

    glViewport(0, 0, g_iWindowWidth, g_iWindowHeight);

    // Setup the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLdouble)g_iWindowWidth / (GLdouble)g_iWindowHeight, 0.1, 100.0);
    glutPostRedisplay();

    
}

/*
* Fonction openGL responsable pour fermer la fenetre et donc sortir du jeu
*/
void Cleanup(int errorCode, bool bExit)
{
    if (g_iGLUTWindowHandle != 0)
    {
        glutDestroyWindow(g_iGLUTWindowHandle);
        g_iGLUTWindowHandle = 0;
    }

    if (bExit)
    {
        exit(errorCode);
    }
}

