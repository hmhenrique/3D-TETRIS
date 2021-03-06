#include "libs.h"

Menu::Menu(){}


void Menu::printName()
{
    t.printTxt(4.7f, 3.5f, player.getName(), t.color_red, t.font4);
}

void Menu::printInstructions()
{
    t.printTxt(4.0f, 4.0f, "Enter the player name", t.color_white, t.font4);
    t.printTxt(4.0f, 0.5f, "Press [ENTER] to play.", t.color_gray, t.font3);
    t.printTxt(3.5f, 3.5f, "Player : ", t.color_white, t.font4);
}

void Menu::printMenu()
{
    printName();
    printInstructions();
}

void Menu::activeMenu()
{
    menu = true;
}

void Menu::inactiveMenu()
{
    menu = false;
}

bool Menu::statusMenu()
{
    return menu;
}
