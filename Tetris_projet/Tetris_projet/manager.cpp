#include "libs.h"

Manager::Manager() {};

void Manager::playGame()
{
    switch (indice)
    {
    case 1:
    {
        Scene_Game_menu();
    }
    break;
    case 2:
    {
        Scene_Game_play();
    }
    break;
    case 3:
    {
        Scene_Game_over();
    }
    break;
    }
}

void Manager::KeyboardGL(unsigned char c, int x, int y)
{

    switch (indice)
    {
    case 1: {
        switch (c)
        {
        case 13: // represents [ENTER]
        {
            m.inactiveMenu();
        }
        break;
        case 8: // represents [BACKSPACE]
        {
            m.player.popChar();
        }
        break;
        default:
        {
            m.player.addChar(c);
        }
        break;
        }
    }
          break;

    case 2: {
        switch (c)
        {
        case 'D':
        case 'd':
        {
            g.moveXp();
        }
        break;
        case 'a':
        case 'A':
        {
            g.moveXn();
        }
        break;
        case 'w':
        case 'W':
        {
            g.moveZn();
        }
        break;
        case 's':
        case 'S':
        {
            g.moveZp();
        }
        break;
        case 'z':
        case 'Z':
        {
            g.rotateBlock_x();
        }
        break;
        case 'x':
        case 'X':
        {
            g.rotateBlock_y();
        }
        break;
        case 'c':
        case 'C':
        {
            g.rotateBlock_z();
        }
        break;
        case 'e':
        case 'E':
        {
            g.fallBlock();
        }
        break;
        case 'q':
        case 'Q':
        {
            rotateGrid();
        }
        break;
        }
    }
    break;

    case 3: {
        switch (c)
        {
        case 13: // represents [ENTER]
        {
            restart();
        }
        break;
        case 32: // represents [SPACE]
        {
            m.activeMenu();
            restart();
        }
        break;
        }
    }
          break;

    }
}

void Manager::restart()
{
    g.restart();
    m.player.resetPoints();
    restart_ = true;
}

void Manager::rotateGrid()
{
    rotategrid++;
    if (rotategrid == 4)
        rotategrid = 0;
}

void Manager::Scene_Game_play() {

    //std::cout << "Playing" << std::endl;

    indice = 2;

    restart_ = false;

    if (clock() - tInicio > 1000 / (2 * m.player.returnLevel()))
    {
        g.fallBlock();
        tInicio = clock();
    }

    g.drawFullFakeGrid(10, 20, 10);
    //g.drawCubesWall();


    for(int k = 0; k <= rotategrid; k ++){
        glRotatef(90.f, 0.0f, -1.f, 0.0f); //rotate le scenario le nombre rotategrid de fois
        glTranslatef(0.0f, 0.0f, -11.0f);
    }
    g.drawGrid();

    m.player.addPoints(g.deleteLine());

    if (g.gameoverCheck())
        indice = 3;

    t.showName(m.player.getName());
    t.showLevel(m.player.getLevel());
    t.showPoints(m.player.getPoints());
    t.showCommands();
}


void Manager::Scene_Game_over() {

    //std::cout << "GAME OVER" << std::endl;

    g.drawFullFakeGrid(10, 20, 10);
    // g.drawCubesWall();


    for (int k = 0; k <= rotategrid; k++) {
        glRotatef(90.f, 0.0f, -1.f, 0.0f);
        glTranslatef(0.0f, 0.0f, -11.0f);
    }
    g.drawGrid();

    
    indice = 3;


    t.showName(m.player.getName());
    t.showLevel(m.player.getLevel());
    t.showPoints(m.player.getPoints());
    t.showEndGame();

    if (restart_)
        if(m.statusMenu())
            indice = 1;
        else
            indice = 2;

}


void Manager::Scene_Game_menu() {


    //std::cout << "MENU" << std::endl;

    g.drawLogo();
    m.printMenu();
    indice = 1;

    if (!m.statusMenu())
        indice = 2;

}