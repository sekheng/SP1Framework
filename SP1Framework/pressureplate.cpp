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
Door door;
int idoor = 0;

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
			if (charLocation.X == plate.directions[i].X && charLocation.Y == plate.directions[i].Y)
			{
				onPlate = true;
			}
			else if (block.directions[a].X == plate.directions[i].X && block.directions[a].Y == plate.directions[i].Y)
			{
				onPlate = true;
			}
			else
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
		console.writeToBuffer(plate.directions[p], (char)80, 0x0C);
	}
}

void setDoor(int x, int y, int z)
{
	door.position[z].X = x;
	door.position[z].Y = y;
}

void updateDoor(int z)
{
	for (int i = 0; i < z; i++)
	{
		if (charLocation.X == door.position[i].X &&
			charLocation.Y == door.position[i].Y && keyPressed[K_UP]
			|| charLocation.X == door.position[i].X &&
			charLocation.Y == door.position[i].Y && keyPressed[K_W])//player push upwards
		{
			if (charLocation.X == door.position[i].X && charLocation.Y == door.position[i].Y)
			{
				charLocation.Y++;
			}
		}
		else if (charLocation.X == door.position[i].X &&
			charLocation.Y == door.position[i].Y && keyPressed[K_DOWN]
			|| charLocation.X == door.position[i].X && charLocation.Y ==
			door.position[i].Y && keyPressed[K_S])//player push downwards
		{
			if (charLocation.X == door.position[i].X && charLocation.Y == door.position[i].Y)
			{
				charLocation.Y--;
			}
		}
		else if (charLocation.X == door.position[i].X &&
			charLocation.Y == door.position[i].Y && keyPressed[K_LEFT]
			|| charLocation.X == door.position[i].X && charLocation.Y ==
			door.position[i].Y && keyPressed[K_A])//player push left
		{
			if (charLocation.X == door.position[i].X && charLocation.Y == door.position[i].Y)
			{
				charLocation.X++;
			}
		}
		if (onPlate = true)
		{
			g_map[door.position[i].X][door.position[i].Y] = 0;
		}
	}
}

void printDoor(int i)
{
	for (int d = 0; d < i; d++)
	{
		console.writeToBuffer(door.position[d], (char)68, 0x0C);
	}
}