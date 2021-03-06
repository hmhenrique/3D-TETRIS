#include "libs.h"

void Text::printTxt(float x, float y, std::string text, GLfloat color_text[3], void* font)
{
    char* c;

    char* test = new char[text.size() + 1];
    std::copy(text.begin(), text.end(), test);
    test[text.size()] = '\0';

    glPushMatrix();
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);

    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 10, 0, 10);

    glColor3f(color_text[0], color_text[1], color_text[2]);
    glRasterPos2f(x, y);
    glDisable(GL_LIGHTING);

    for (c = test; *c != '\0'; c++)
        glutBitmapCharacter(font, *c);

    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}


void Text::showPoints(int points)
{
    printTxt(6.5f, 6.5f, "Points :", color_white, font4);
    printTxt(6.5f, 6.0f, std::to_string(points), color_red, font3);
}

void Text::showLevel(int level) {
    printTxt(6.5f, 7.5f, "Level :", color_white, font4);
    printTxt(6.5f, 7.0f, std::to_string(level), color_red, font3);
}
void Text::showName(std::string name) {
    printTxt(6.5f, 8.5f, "Player :", color_white, font4);
    printTxt(6.5f, 8.0f, name, color_red, font3);
}

void Text::showCommands() {
    printTxt(7.0f, 1.5f, "[ W A S D ] to move", color_gray, font3);
    printTxt(7.0f, 1.25f, "[ Z X C ] to rotate", color_gray, font3);
    printTxt(7.0f, 1.0f, "[ Q ] to rotate GRID", color_gray, font3);
    printTxt(7.0f, 0.75f, "[ E ] to fall", color_gray, font3);
    printTxt(7.0f, 0.5f, "[ ESC ] to quit", color_gray, font3);
}

void Text::showEndGame() {
    printTxt(5.0f, 1.5f, "Press [ ENTER ] to restart", color_gray, font3);
    printTxt(5.0f, 1.0f, "Press [ SPACE ] to return to MENU", color_gray, font3);
    printTxt(5.0f, 0.5f, "Press [ ESC ] to quit", color_gray, font3);
    printTxt(6.0f, 4.0f, "G A M E  O V E R", color_red, font);
}
