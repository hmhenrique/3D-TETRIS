#include "libs.h"

Cube::Cube(float x_, float y_, float z_, GLfloat color_cube_[3])
{
    x = x_;
    y = y_;
    z = z_;
    for (int i = 0; i < 3; i++)
        color_cube[i] = color_cube_[i];
}


void Cube::setpos(float x_, float y_, float z_)
{
    this->x = x_;
    this->y = y_;
    this->z = z_;
}

void Cube::fall()
{
    this->y = this->y - 1;
}

bool Cube::CheckPosition(float x_, float y_, float z_) {
    if (this->x == x_ && this->y == y_ && this->z == z_)
        return true;

    return false;
}

bool Cube::CheckLevel(float _y)
{
    if (y == _y)
        return true;
    else return false;
}

float Cube::GetLevel()
{
    return this->y;
}

std::vector<float> Cube::GetPosition()
{
    std::vector<float>pos;
    pos.push_back(x);
    pos.push_back(y);
    pos.push_back(z);
    return pos;
}
    

void Cube::DrawCube(bool g) {  //g -> est la grid ou non
    if (!g) {
        glColor3f(this->color_cube[0], this->color_cube[1], this->color_cube[2]);
        glTranslatef(this->x, this->y, this->z);
        glutSolidCube(0.99);
        glColor3f(0, 0, 0);
        glutWireCube(1);
        glTranslatef(-this->x, -this->y, -this->z);
    }

    else {
        glColor3f(this->color_cube[0], this->color_cube[1], this->color_cube[2]);
        glTranslatef(this->x, this->y, this->z);
        //glutSolidCube(0.99);
        //glColor3f(1, 0, 0);
        glutWireCube(1);
        glTranslatef(-this->x, -this->y, -this->z);
    }
}

