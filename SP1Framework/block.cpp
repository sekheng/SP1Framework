#include "block.h"

extern Console console;
extern COORD charLocation;
extern size_t g_map[140][100];
extern int bno;
extern bool keyPressed[K_COUNT];

Block block;

//to be placed in init
void setBlock(int x, int y, int z)
{
	for(int b = 0; b < z; b++)
	{
		block.directions[z].X = x;
		block.directions[z].Y = y;
	}
}

//to be placed in update
void updateBlock(int x, int z)
{
	for (int i = 0; i < bno; ++i)
	{	
		if (charLocation.X == block.directions[i].X && charLocation.Y == block.directions[i].Y-- && keyPressed[K_UP] || keyPressed[K_W])
		{
			block.directions[i].Y++;
		}
	}
	for (int i = 0; i < bno; ++i)
	{
		if (charLocation.X == block.directions[i].X && charLocation.Y == block.directions[i].Y++ && keyPressed[K_DOWN] || keyPressed[K_S])
		{
			block.directions[i].Y--;
		}
	}
	for (int i = 0; i < bno; ++i)
	{
		if (charLocation.X == block.directions[i].X++ && charLocation.Y == block.directions[i].Y && keyPressed[K_LEFT] || keyPressed[K_A])
		{
			block.directions[i].X--;
		}
	}
	for (int i = 0; i < bno; ++i)
	{
		if (charLocation.X == block.directions[i].X-- && charLocation.Y == block.directions[i].Y && keyPressed[K_RIGHT] || keyPressed[K_D])
		{
			block.directions[i].X++;
		}
	}
}

//to be placed in render
void printBlock(int &i)
{
	for (int b = 0; b < i; b++)
	{
		console.writeToBuffer(block.directions[b], (char)35, 0x0C);
	}
}