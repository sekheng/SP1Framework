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
Block blockStartingPosition;
//to be placed in init
void setBlock(int x, int y, int z)
{
	block.directions[z].X = x;
	block.directions[z].Y = y;
    blockStartingPosition.directions[z].X = x;
    blockStartingPosition.directions[z].Y = y;
    //restartBlockPosition(z);
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
	}
	for (int y= z; y>0; y--)
	{
		for (int x = 0; x < y;x++)
		{
			if (block.directions[x].X == block.directions[y].X &&
				block.directions[x].Y == block.directions[y].Y && keyPressed[K_RIGHT]
				|| block.directions[x].X == block.directions[y].X &&
				block.directions[x].Y == block.directions[y].Y && keyPressed[K_D])
			{
				block.directions[y].X--;
				charLocation.X--;
			}
			else if (block.directions[x].X == block.directions[y].X &&
				block.directions[x].Y == block.directions[y].Y && keyPressed[K_LEFT]
				|| block.directions[x].X == block.directions[y].X &&
				block.directions[x].Y == block.directions[y].Y && keyPressed[K_A])
			{
				block.directions[y].X++;
				charLocation.X++;
			}
			else if (block.directions[x].X == block.directions[y].X &&
				block.directions[x].Y == block.directions[y].Y && keyPressed[K_UP]
				|| block.directions[x].X == block.directions[y].X &&
				block.directions[x].Y == block.directions[y].Y && keyPressed[K_W])
			{
				block.directions[y].Y++;
				charLocation.Y++;
			}
			else if (block.directions[x].X == block.directions[y].X &&
				block.directions[x].Y == block.directions[y].Y && keyPressed[K_DOWN]
				|| block.directions[x].X == block.directions[y].X &&
				block.directions[x].Y == block.directions[y].Y && keyPressed[K_S])
			{
				block.directions[y].Y--;
				charLocation.Y--;
			}
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

void restartBlockPosition(int z)
{
    for ( int i = 0; i < z; ++i)
    {
        block.directions[i].Y = blockStartingPosition.directions[i].Y;
        block.directions[i].X = blockStartingPosition.directions[i].X;
    }
}