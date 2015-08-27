#include "block.h"

extern Console console;
extern COORD charLocation;
extern size_t g_map[200][200];
extern int bno;
extern bool keyPressed[K_COUNT];
extern startscreen state;
extern struct Cannon Right;
extern struct Cannon Left;
extern struct Cannon Up;
extern struct Cannon Down;
extern int cnoR;
extern int cnoL;
extern int cnoU;
extern int cnoD;

Block block;
int iblock = 0;
//to be placed in init
void setBlock(int x, int y, int z)
{
	block.directions[z].X = x;
	block.directions[z].Y = y;
}

//to be placed in update
void updateBlock(int z) // x= no of blocks and z=box number
{
	for (int i = 0; i < z; ++i)
	{
		if (charLocation.X == block.directions[i].X &&
			charLocation.Y == block.directions[i].Y && keyPressed[K_UP]
			|| charLocation.X == block.directions[i].X &&
			charLocation.Y == block.directions[i].Y && keyPressed[K_W])//player push upwards
		{
			if (g_map[block.directions[i].Y - 1][block.directions[i].X] != 1)
			{
				block.directions[i].Y--;
			}
			if (charLocation.X == block.directions[i].X && charLocation.Y == block.directions[i].Y)
			{
				charLocation.Y++;
			}
		}
		else if (charLocation.X == block.directions[i].X &&
			charLocation.Y == block.directions[i].Y && keyPressed[K_DOWN]
			|| charLocation.X == block.directions[i].X && charLocation.Y ==
			block.directions[i].Y && keyPressed[K_S])//player push downwards
		{
			if (g_map[block.directions[i].Y + 1][block.directions[i].X] != 1)
			{
				block.directions[i].Y++;
			}
			if (charLocation.X == block.directions[i].X && charLocation.Y == block.directions[i].Y)
			{
				charLocation.Y--;
			}
		}
		else if (charLocation.X == block.directions[i].X &&
			charLocation.Y == block.directions[i].Y && keyPressed[K_LEFT]
			|| charLocation.X == block.directions[i].X && charLocation.Y ==
			block.directions[i].Y && keyPressed[K_A])//player push left
		{
			if (g_map[block.directions[i].Y][block.directions[i].X - 1] != 1)
			{
				block.directions[i].X--;
			}
			if (charLocation.X == block.directions[i].X && charLocation.Y == block.directions[i].Y)
			{
				charLocation.X++;
			}
		}
		else if (charLocation.X == block.directions[i].X &&
			charLocation.Y == block.directions[i].Y && keyPressed[K_RIGHT]
			|| charLocation.X == block.directions[i].X && charLocation.Y ==
			block.directions[i].Y && keyPressed[K_D])//player push right
		{
			if (g_map[block.directions[i].Y][block.directions[i].X + 1] != 1)
			{
				block.directions[i].X++;
			}
			if (charLocation.X == block.directions[i].X && charLocation.Y == block.directions[i].Y)
			{
				charLocation.X--;
			}
		}
		if (block.directions[i + 1].X == block.directions[i].X &&
			block.directions[i].Y == block.directions[i].Y && keyPressed[K_RIGHT]
			|| block.directions[i + 1].X == block.directions[i].X &&
			block.directions[i].Y == block.directions[i].Y && keyPressed[K_D])
		{
			block.directions[i].X--;
			charLocation.X--;
		}
		else
			if (block.directions[i - 1].X == block.directions[i].X &&
				block.directions[i].Y == block.directions[i].Y && keyPressed[K_LEFT]
				|| block.directions[i - 1].X == block.directions[i].X &&
				block.directions[i].Y == block.directions[i].Y && keyPressed[K_A])
			{
				block.directions[i].X++;
				charLocation.X++;
			}
			else
				if (block.directions[i].X == block.directions[i].X &&
					block.directions[i + 1].Y == block.directions[i].Y && keyPressed[K_UP]
					|| block.directions[i].X == block.directions[i].X &&
					block.directions[i + 1].Y == block.directions[i].Y && keyPressed[K_W])
				{
					block.directions[i].Y++;
					charLocation.Y++;
				}
				else
					if (block.directions[i].X == block.directions[i].X &&
						block.directions[i - 1].Y == block.directions[i].Y && keyPressed[K_DOWN]
						|| block.directions[i].X == block.directions[i].X &&
						block.directions[i - 1].Y == block.directions[i].Y && keyPressed[K_S])
					{
						block.directions[i].Y--;
						charLocation.Y--;
					}

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