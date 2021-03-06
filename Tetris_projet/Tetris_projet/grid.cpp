#include "libs.h"

Grid::Grid() {
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			for (int k = 0; k < 12; k++)
			{
				if (i == 0 || i == 11 || k == 0 || k == 11 || j == 0) {
					CubeWallEnabled[i][j][k] = 1;
				}

				else CubeWallEnabled[i][j][k] = 0;
			}
		}
	}
	
	createCubesWall();
	newBlockToMove();

}
Grid::~Grid() {}

void Grid::createCubesWall()
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            for (int k = 0; k < 12; k++)
            {
                if (CubeWallEnabled[i][j][k] == 1) {
                    cube_wall.push_back(Cube(i, j, k, colorDefault));
                }
            }
        }
    }
}

void Grid::newBlockToMove()
{
    block_moving = Blocks(xinit, yinit, zinit);
}

void Grid::fallBlock()
{
    bool status;
    status = block_moving.setPosition(0, -1, 0, blocks_stop, cube_wall);
    if (!status) {
        moveToStop();
    }
}

void Grid::moveToStop()
{
    blocks_stop.push_back(block_moving);
    newBlockToMove();
}

void Grid::moveXn()
{
    block_moving.setPosition(-1, 0, 0, blocks_stop, cube_wall);
}

void Grid::moveXp()
{
    block_moving.setPosition(1, 0, 0, blocks_stop, cube_wall);
}

void Grid::moveZn()
{
    block_moving.setPosition(0, 0, -1, blocks_stop, cube_wall);
}

void Grid::moveZp()
{
    block_moving.setPosition(0, 0, 1, blocks_stop, cube_wall);
}

void Grid::rotateBlock_x()
{
    std::vector<Cube> aux_c;
    float x_min, x_max, y_min, y_max, z_min, z_max, desc_y, desc_z, px, py, pz, aux_x, aux_z;

    y_min = block_moving.getmin(block_moving.cube_block)[1];
    y_max = block_moving.getmax(block_moving.cube_block)[1];

    x_min = block_moving.getmin(block_moving.cube_block)[0];
    x_max = block_moving.getmax(block_moving.cube_block)[0];

    z_min = block_moving.getmin(block_moving.cube_block)[2];
    z_max = block_moving.getmax(block_moving.cube_block)[2];

    block_temp = block_moving;

    for (auto& ele : block_temp.cube_block) {
        px = ele.GetPosition()[0];
        py = ele.GetPosition()[1];
        pz = ele.GetPosition()[2];

        desc_y = py - y_min;
        desc_z = pz - z_min;

        ele.setpos(px, py - desc_z - desc_y, pz - desc_z + desc_y);
        //ele.y = ele.y - desc_z;
        //ele.z = ele.z - desc_z;

        //ele.y = ele.y - desc_y;
        //ele.z = ele.z + desc_y;

        aux_c.push_back(ele);
    }

    block_temp.cube_block.clear();
    block_temp.cube_block = aux_c;

    if (block_temp.setPosition(0, 0, 0, blocks_stop, cube_wall))
        block_moving = block_temp;
}

void Grid::rotateBlock_y() {

    std::vector<Cube> aux_c;
    float x_min, x_max, y_min, y_max, z_min, z_max, desc_x, desc_z, px, py, pz, aux_x, aux_z;

    y_min = block_moving.getmin(block_moving.cube_block)[1];
    y_max = block_moving.getmax(block_moving.cube_block)[1];

    x_min = block_moving.getmin(block_moving.cube_block)[0];
    x_max = block_moving.getmax(block_moving.cube_block)[0];

    z_min = block_moving.getmin(block_moving.cube_block)[2];
    z_max = block_moving.getmax(block_moving.cube_block)[2];

    block_temp = block_moving;

    for (auto& ele : block_temp.cube_block) {
        px = ele.GetPosition()[0];
        py = ele.GetPosition()[1];
        pz = ele.GetPosition()[2];

        desc_x = px - x_min;
        desc_z = pz - z_min;

        ele.setpos(px - desc_x + desc_z, py, pz - desc_x - desc_z);

        //ele.x = ele.x - desc_x;
        //ele.z = ele.z - desc_x;

        //ele.x = ele.x + desc_z;
        //ele.z = ele.z - desc_z;

        aux_c.push_back(ele);
    }

    block_temp.cube_block.clear();
    block_temp.cube_block = aux_c;

    if (block_temp.setPosition(0, 0, 0, blocks_stop, cube_wall))
        block_moving = block_temp;
}

void Grid::rotateBlock_z() {

    std::vector<Cube> aux_c;
    float x_min, x_max, y_min, y_max, z_min, z_max, desc_x, desc_y, px, py, pz, aux_x, aux_z;

    y_min = block_moving.getmin(block_moving.cube_block)[1];
    y_max = block_moving.getmax(block_moving.cube_block)[1];

    x_min = block_moving.getmin(block_moving.cube_block)[0];
    x_max = block_moving.getmax(block_moving.cube_block)[0];

    z_min = block_moving.getmin(block_moving.cube_block)[2];
    z_max = block_moving.getmax(block_moving.cube_block)[2];

    block_temp = block_moving;

    for (auto& ele : block_temp.cube_block) {
        px = ele.GetPosition()[0];
        py = ele.GetPosition()[1];
        pz = ele.GetPosition()[2];

        desc_x = px - x_min;
        desc_y = py - y_min;

        ele.setpos(px - desc_y - desc_x, py - desc_y + desc_x, pz);

        //ele.y = ele.y - desc_y;
        //ele.x = ele.x - desc_y;

        //ele.y = ele.y + desc_x;
        //ele.x = ele.x - desc_x;

        aux_c.push_back(ele);
    }

    block_temp.cube_block.clear();
    block_temp.cube_block = aux_c;

    if (block_temp.setPosition(0, 0, 0, blocks_stop, cube_wall))
        block_moving = block_temp;
}

void Grid::setghost()
{
    ghost = block_moving;
    while (ghost.setPosition(0, -1, 0, blocks_stop, cube_wall)) {

    }
}

int Grid::deleteLine()
{
    int count = 0, linesdeleted = 0;
    for (int i = 20; i > 0; i--) {
        for (auto& ele : blocks_stop) {
            count = count + ele.checkLevel(i);
        }
        if (count == 100) {
            for (auto& ele : blocks_stop) {
                ele.destroyLevel(i);
            }
            linesdeleted += 1;
        }
        count = 0;
    }
    return linesdeleted;
}

bool Grid::gameoverCheck() {
    for (auto& ele : blocks_stop) {
        if (ele.getmax(ele.cube_block)[1] > 19) {
            //std::cout << "GAME OVER" << std::endl;
            return true;
        }
    }
    return false;
}

void Grid::drawFakeGrid(float width, float height, int dir)
{
    const float w = width / 2.0f;
    const float h = height / 2.0f;

    // plano xy
    if (dir == 0)
    {
        glBegin(GL_LINES);
        glVertex3f(-w, h, 0);   //TOP
        glVertex3f(w, h, 0);

        glVertex3f(w, h, 0);   //Right
        glVertex3f(w, -h, 0);

        glVertex3f(w, -h, 0);  //bottom
        glVertex3f(-w, -h, 0);

        glVertex3f(-w, -h, 0);   //left
        glVertex3f(-w, h, 0);
        glEnd();
    }

    //plano xz
    if (dir == 1)
    {
        glBegin(GL_LINES);
        glVertex3f(-w, 0, h);   //TOP
        glVertex3f(w, 0, h);

        glVertex3f(w, 0, h);   //Right
        glVertex3f(w, 0, -h);

        glVertex3f(w, 0, -h);  //bottom
        glVertex3f(-w, 0, -h);

        glVertex3f(-w, 0, -h);   //left
        glVertex3f(-w, 0, h);
        glEnd();
    }

    //plano yz
    if (dir == 2)
    {
        glBegin(GL_LINES);
        glVertex3f(0, -w, h);   //TOP
        glVertex3f(0, w, h);

        glVertex3f(0, w, h);   //Right
        glVertex3f(0, w, -h);

        glVertex3f(0, w, -h);  //bottom
        glVertex3f(0, -w, -h);

        glVertex3f(0, -w, -h);   //left
        glVertex3f(0, -w, h);
        glEnd();
    }
}

void Grid::drawFullFakeGrid(int x, int y, int z)
{

    glTranslatef(0.5f, 1.0f, 0.5f);
    glTranslatef(0.f, 0.5f, 0.5f);
    for (int i = 0; i < x; i++)
    {
        glTranslatef(i, 0.f, 0.f);
        for (int j = 0; j < y; j++)
        {
            glTranslatef(0.f, j, 0.f);
            for (int k = 0; k < z; k++)
            {
                glTranslatef(0.f, 0.f, k);
                if (i == 0)
                {
                    glRotatef(0, 0, 1, 0);
                    glRotatef(0, 1, 0, 0);
                    glRotatef(0, 0, 0, 1);
                    drawFakeGrid(1.0f, 1.0f, 2);
                }

                glTranslatef(0.f, 0.f, -k);
            }
            glTranslatef(0.f, -j, 0.f);
        }
        glTranslatef(-i, 0.f, 0.f);
    }
    glTranslatef(0.f, -0.5f, -0.5f);

    glTranslatef(0.5f, 0.f, 0.5f);
    for (int i = 0; i < x; i++)
    {
        glTranslatef(i, 0.f, 0.f);
        for (int j = 0; j < y; j++)
        {
            glTranslatef(0.f, j, 0.f);
            for (int k = 0; k < z; k++)
            {
                glTranslatef(0.f, 0.f, k);
                if (j == 0)
                {
                    glRotatef(0, 0, 1, 0);
                    glRotatef(0, 1, 0, 0);
                    glRotatef(0, 0, 0, 1);
                    drawFakeGrid(1.0f, 1.0f, 1);
                }
                glTranslatef(0.f, 0.f, -k);
            }
            glTranslatef(0.f, -j, 0.f);
        }
        glTranslatef(-i, 0.f, 0.f);
    }
    glTranslatef(-0.5f, 0.f, -0.5f);

    glTranslatef(0.5f, 0.5f, 0.f);
    for (int i = 0; i < x; i++)
    {
        glTranslatef(i, 0.f, 0.f);
        for (int j = 0; j < y; j++)
        {
            glTranslatef(0.f, j, 0.f);
            for (int k = 0; k < z; k++)
            {
                glTranslatef(0.f, 0.f, k);
                if (k == 0)
                {
                    glRotatef(0, 0, 1, 0);
                    glRotatef(0, 1, 0, 0);
                    glRotatef(0, 0, 0, 1);
                    drawFakeGrid(1.0f, 1.0f, 0);
                }

                glTranslatef(0.f, 0.f, -k);
            }
            glTranslatef(0.f, -j, 0.f);
        }
        glTranslatef(-i, 0.f, 0.f);
    }
    glTranslatef(-0.5f, -0.5f, 0.f);
    glTranslatef(-0.5f, -0.5f, -0.5f);
}

void Grid::drawBlocksStop()
{
    for (auto& element : blocks_stop)
        element.drawBlock(false);
}

void Grid::drawBlockMoving()
{
    block_moving.drawBlock(false);
}

void Grid::drawGhost() 
{
    ghost.drawBlock(true);
}

void Grid::drawGrid()
{
    drawBlockMoving();
    setghost();
    drawGhost();
    drawBlocksStop();
}

//test
void Grid::drawCubesWall()
{
    for (auto& element : cube_wall)
        element.DrawCube(true);
}

void Grid::drawLogo() {

    glTranslatef(15.0f, 15.0f, 15.0f);                                     // Translate back and to the left
    glRotatef(-90.f, 1.0f, 0.0f, 0.0f);
    glRotatef(90.f, 0.0f, 1.0f, 0.0f);


    logo.createLogo();
    logo.drawLogo();

    glTranslatef(-7.0f, 15.0f, 1.0f);
    glRotatef(45.f, 1.0f, 0.0f, 0.0f);
    logo.draw3d();
}

void Grid::restart() {
    blocks_stop.clear();
}
