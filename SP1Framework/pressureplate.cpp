#include "pressureplate.h"

extern Console console;
extern COORD charLocation;
extern size_t g_map[200][200];
extern int bno;
extern bool keyPressed[K_COUNT];
extern startscreen state;

Plate plate;
int iplate = 0;
bool onPlate;
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
		if (charLocation.X == plate.directions[i].X && charLocation.Y == plate.directions[i].Y)
		{
			onPlate = true;
		}
		else
		{
			onPlate = false;
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