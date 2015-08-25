#include "block.h"

extern Console console;
extern COORD charLocation;
extern size_t g_map[140][100];
extern int bno;
extern bool keyPressed[K_COUNT];
extern startscreen state;

Block block;
int iblock = 0;
//to be placed in init
void setBlock(int x, int y, int z)
{
	if (iblock <= z)
	{
		block.directions[iblock].X = x;
		block.directions[iblock].Y = y;
		iblock++;
	}
	
}

//to be placed in update
void updateBlock(int z) // x= no of blocks and z=box number
{
	for (int i = 0; i < z; ++i)
	{
		if (charLocation.X == block.directions[i].X && charLocation.Y == block.directions[i].Y && keyPressed[K_UP] || charLocation.X == block.directions[i].X && charLocation.Y == block.directions[i].Y && keyPressed[K_W])
		{
			block.directions[i].Y--;
		}
		else if (charLocation.X == block.directions[i].X && charLocation.Y == block.directions[i].Y && keyPressed[K_DOWN] || charLocation.X == block.directions[i].X && charLocation.Y == block.directions[i].Y && keyPressed[K_S])//player push downwards
		{
			block.directions[i].Y++;
		}
		else if (charLocation.X == block.directions[i].X && charLocation.Y == block.directions[i].Y && keyPressed[K_LEFT] || charLocation.X == block.directions[i].X && charLocation.Y == block.directions[i].Y && keyPressed[K_A])//player push left
		{
			block.directions[i].X--;
		}
		else if (charLocation.X == block.directions[i].X && charLocation.Y == block.directions[i].Y && keyPressed[K_RIGHT] || charLocation.X == block.directions[i].X && charLocation.Y == block.directions[i].Y && keyPressed[K_D])//player push right
		{
			block.directions[i].X++;
		}
		std::cout << block.directions[i].X << " " << block.directions[i].Y<< std::endl;
	}
}

//to be placed in render
void printBlock(int i)// i = bno
{
	for (int b = 0; b < i; b++)
	{
		console.writeToBuffer(block.directions[b], (char)35, 0x0C);
		
	}
}