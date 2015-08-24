#include "block.h"

extern Console console;
extern COORD charLocation;
extern int bno;

Block block;

//to be placed in init
void setBlock(int x, int y, int z)
{
	for(int b = 0; b < z; b++)
	{
		block.directions[b].X = x;
		block.directions[b].Y = y;
	}
}

//to be placed in update
void updateBlock(int x, int z)
{
	for (int i = 0; i < bno; ++i)
	{
		if (charLocation.X == block.directions[i].X && charLocation.Y == block.directions[i].Y++)
		{
			block.directions[i].Y--;
		}
	}
	for (int i = 0; i < bno; ++i)
	{
		if (charLocation.X == block.directions[i].X && charLocation.Y == block.directions[i].Y--)
		{
			block.directions[i].Y++;
		}
	}
	for (int i = 0; i < bno; ++i)
	{
		if (charLocation.X == block.directions[i].X++ && charLocation.Y == block.directions[i].Y)
		{
			block.directions[i].X--;
		}
	}
	for (int i = 0; i < bno; ++i)
	{
		if (charLocation.X == block.directions[i].X-- && charLocation.Y == block.directions[i].Y)
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