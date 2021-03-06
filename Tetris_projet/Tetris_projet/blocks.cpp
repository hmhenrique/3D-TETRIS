#include "libs.h"

using namespace std;

Blocks::Blocks() {}
Blocks::~Blocks() {}

Blocks::Blocks(float x_, float y_, float z_) {
	posx = x_;
	posy = y_;
	posz = z_;

	createBlock();
	createCubes();
}

bool Blocks::createBlock() {

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				CubeEnabled[i][j][k] = 0;
			}
		}
	}

	srand((unsigned)time(NULL));
	random1 = rand() % 120;
	random2 = random1 / 20;

	switch (random2)
	{
	case 0:
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				CubeEnabled[i][j][0] = block_I_0[i][j];
				CubeEnabled[i][j][1] = block_NULL[i][j];
				CubeEnabled[i][j][2] = block_NULL[i][j];

				color[i] = color_block_I[i];
			}
		}
	}
	break;
	case 1:
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				CubeEnabled[i][j][0] = block_L_0[i][j];
				CubeEnabled[i][j][1] = block_NULL[i][j];
				CubeEnabled[i][j][2] = block_NULL[i][j];

				color[i] = color_block_L[i];
			}
		}
	}
	break;
	case 2:
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				CubeEnabled[i][j][0] = block_T_0[i][j];
				CubeEnabled[i][j][1] = block_NULL[i][j];
				CubeEnabled[i][j][2] = block_NULL[i][j];

				color[i] = color_block_T[i];

			}
		}
	}
	break;
	case 3:
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				CubeEnabled[i][j][0] = block_O_0[i][j];
				CubeEnabled[i][j][1] = block_O_1[i][j];
				CubeEnabled[i][j][2] = block_NULL[i][j];

				color[i] = color_block_O[i];
			}
		}
	}
	break;
	case 4:
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				CubeEnabled[i][j][0] = block_S_0[i][j];
				CubeEnabled[i][j][1] = block_NULL[i][j];
				CubeEnabled[i][j][2] = block_NULL[i][j];

				color[i] = color_block_S[i];
			}
		}

	}
	break;
	case 5:
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				CubeEnabled[i][j][0] = block_L2_0[i][j];
				CubeEnabled[i][j][1] = block_NULL[i][j];
				CubeEnabled[i][j][2] = block_NULL[i][j];

				color[i] = color_block_L[i];
			}
		}

	}
	break;
	case 6:
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				CubeEnabled[i][j][0] = block_S2_0[i][j];
				CubeEnabled[i][j][1] = block_NULL[i][j];
				CubeEnabled[i][j][2] = block_NULL[i][j];

				color[i] = color_block_S[i];
			}
		}

	}
	break;
	}

	return true;
}

void Blocks::createCubes() {

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (CubeEnabled[i][j][k] == 1)
					cube_block.push_back(Cube(posx + i, posy + j, posz + k, color));
			}
		}
	}
}

void Blocks::drawBlock(bool g) {

	for (auto& element : cube_block)
		element.DrawCube(g);
	
}

bool Blocks::checkPosition(float x, float y, float z) {

	for (auto& element : cube_block)
		if (element.CheckPosition(x, y, z))
			return true;
	return false;
}

bool Blocks::setPosition(float x, float y, float z, std::vector<Blocks> blocks, std::vector<Cube> wall_cube)
{
	float px, py, pz;
	for (auto& element : cube_block) {

		px = element.GetPosition()[0];
		py = element.GetPosition()[1];
		pz = element.GetPosition()[2];

		for (auto& temp : blocks)
			if (temp.checkPosition(px + x, py + y, pz + z)) {
				//std::cout << "check position = false" << std::endl;
				return false;
			}
		for (auto& wall : wall_cube)
			if (wall.CheckPosition(px + x, py + y, pz + z)) {
				//std::cout << "check position = false" << std::endl;
				return false;
			}
	}
	for (auto& element : cube_block) {
		px = element.GetPosition()[0];
		py = element.GetPosition()[1];
		pz = element.GetPosition()[2];

		element.setpos(px + x, py + y, pz + z);
		//std::cout << "check position = true" << std::endl;
	}
	return true;
}

int Blocks::checkLevel(float _y)
{
	int count = 0;
	for (auto& ele : cube_block) {
		if (ele.CheckLevel(_y))
			count++;
	}
	return count;
}

void Blocks::destroyLevel(float _y)
{
	for (auto& ele : cube_block) {
		if (ele.GetLevel() < _y)
			cube_block_temp.push_back(ele);
		if (ele.GetLevel() > _y) {
			ele.fall();
			cube_block_temp.push_back(ele);
		}
	}

	cube_block = cube_block_temp;
	cube_block_temp.clear();
}

std::vector<float> Blocks::getmin(std::vector<Cube> vec)
{
	std::vector<float> aux_x;
	std::vector<float> aux_y;
	std::vector<float> aux_z;
	std::vector<float> min;
	float px, py, pz;

	float x_min = 100, y_min = 100, z_min = 100;

	for (auto& ele : vec) {

		px = ele.GetPosition()[0];
		py = ele.GetPosition()[1];
		pz = ele.GetPosition()[2];

		aux_x.push_back(px);
		aux_y.push_back(py);
		aux_z.push_back(pz);
	}

	for (auto& aux : aux_x) {
		if (aux < x_min)
			x_min = aux;
	}

	min.push_back(x_min);

	for (auto& aux : aux_y) {
		if (aux < y_min)
			y_min = aux;
	}

	min.push_back(y_min);

	for (auto& aux : aux_z) {
		if (aux < z_min)
			z_min = aux;
	}

	min.push_back(z_min);

	return min;
}

std::vector<float> Blocks::getmax(std::vector<Cube> vec)
{
	std::vector<float> aux_x;
	std::vector<float> aux_y;
	std::vector<float> aux_z;
	std::vector<float> max;
	float px, py, pz;

	float x_max = -1, y_max = -1, z_max = -1;

	for (auto& ele : vec) {

		px = ele.GetPosition()[0];
		py = ele.GetPosition()[1];
		pz = ele.GetPosition()[2];

		aux_x.push_back(px);
		aux_y.push_back(py);
		aux_z.push_back(pz);
	}

	for (auto& aux : aux_x) {
		if (aux > x_max)
			x_max = aux;
	}

	max.push_back(x_max);

	for (auto& aux : aux_y) {
		if (aux > y_max)
			y_max = aux;
	}

	max.push_back(y_max);

	for (auto& aux : aux_z) {
		if (aux > z_max)
			z_max = aux;
	}

	max.push_back(z_max);

	return max;
}




// TETRIS LOGO
void Blocks::createLogo() {

	for (int j = 0; j < 26; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (tetris[i][j] == 1)
				tetris_logo.push_back(Cube(i, j, 0, color_tetris));
		}
	}

	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (trois_d[i][j] == 1)
				tetris_logo_3d.push_back(Cube(i, j, 0, color_3d));
		}
	}
}

void Blocks::drawLogo() {


	for (auto& element : tetris_logo)
		element.DrawCube(false);

}

void Blocks::draw3d() {


	for (auto& element : tetris_logo_3d)
		element.DrawCube(false);

}

