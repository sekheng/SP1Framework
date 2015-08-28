#include "pressureplate.h"

extern Console console;
extern COORD charLocation;
extern size_t g_map[200][200];
extern int bno;
extern bool keyPressed[K_COUNT];
extern struct Block block;
extern startscreen state;

Plate plate;
int iplate = 0;
bool onPlate;
Hatch hatch;
int ihatch = 0;

//to be placed in init
void setPlate(int x, int y, int z)
{
	plate.directions[z].X = x;
	plate.directions[z].Y = y;
}

void updatePlate(int z)
{
	for (int i = 0; i < z; i++)
	{
		for (int a = 0; a < bno; a++)
		{
			if (block.directions[a].X == plate.directions[i].X && block.directions[a].Y == plate.directions[i].Y)
			{
				onPlate = true;
			}

			if (charLocation.X == plate.directions[i].X && charLocation.Y == plate.directions[i].Y)
			{
				onPlate = true;
			}
			else if (charLocation.X != plate.directions[i].X && charLocation.Y != plate.directions[i].Y)
			{
				onPlate = false;
			}
		}
	}
}

void printPlate(int i)
{
	for (int p = 0; p < i; p++) //i = pno
	{
		console.writeToBuffer(plate.directions[p], (char)80, 0x1C);
	}
}

void setHatch(int x, int y, int z)
{
	hatch.position[z].X = x;
	hatch.position[z].Y = y;
}

void updateHatch(int z)
{
	for (int i = 0; i < z; i++)
	{
		for (int a = 0; a < bno; a++)
		{
			if (block.directions[a].X == hatch.position[i].X && block.directions[a].Y == hatch.position[i].Y && keyPressed[K_RIGHT])
			{
				block.directions[a].X--;
				charLocation.X--;
			}
			if (block.directions[a].X == hatch.position[i].X && block.directions[a].Y == hatch.position[i].Y && keyPressed[K_LEFT])
			{
				block.directions[a].X++;
				charLocation.X++;
			}
			if (block.directions[a].X == hatch.position[i].X && block.directions[a].Y == hatch.position[i].Y && keyPressed[K_UP])
			{
				block.directions[a].Y++;
				charLocation.Y++;
			}
			if (block.directions[a].X == hatch.position[i].X && block.directions[a].Y == hatch.position[i].Y && keyPressed[K_DOWN])
			{
				block.directions[a].Y--;
				charLocation.Y--;
			}
			if (charLocation.X == hatch.position[i].X &&
				charLocation.Y == hatch.position[i].Y && keyPressed[K_UP]
				|| charLocation.X == hatch.position[i].X &&
				charLocation.Y == hatch.position[i].Y && keyPressed[K_W])//player push upwards
			{
				charLocation.Y++;
			}
			else if (charLocation.X == hatch.position[i].X &&
				charLocation.Y == hatch.position[i].Y && keyPressed[K_DOWN]
				|| charLocation.X == hatch.position[i].X && charLocation.Y ==
				hatch.position[i].Y && keyPressed[K_S])//player push downwards
			{
				charLocation.Y--;
			}
			else if (charLocation.X == hatch.position[i].X &&
				charLocation.Y == hatch.position[i].Y && keyPressed[K_LEFT]
				|| charLocation.X == hatch.position[i].X && charLocation.Y ==
				hatch.position[i].Y && keyPressed[K_A])//player push left
			{
				charLocation.X++;
			}
			else if (charLocation.X == hatch.position[i].X &&
				charLocation.Y == hatch.position[i].Y && keyPressed[K_RIGHT]
				|| charLocation.X == hatch.position[i].X && charLocation.Y ==
				hatch.position[i].Y && keyPressed[K_D])//player push right
			{
				charLocation.X--;
			}
			if (onPlate == true)
			{
				//state = GameOver;
				g_map[hatch.position[i].X][hatch.position[i].Y] = 0;
				//hatch.position[i].X = 1000;
				//hatch.position[i].Y = 1000;
			}
		}
	}
}

void printHatch(int i)
{
	for (int h = 0; h < i; h++)
	{
		console.writeToBuffer(hatch.position[h], (char)72, 0x1F);
	}
}