#include "monster.h"
extern Console console;
extern COORD charLocation;
extern size_t g_map[200][200];
extern double timeTriggeredCrazy;
int r[20];

COORD aiCoordinate[20];
COORD monCoordinate[20];

void crazyMon(int i)
{
	for(int b = 0; b < i; ++b)
	{
		console.writeToBuffer(aiCoordinate[b], (char)153, 0x0C);
	}
}
void crazyMonUpdate(int z)
{
		for (int no = 0; no < z;no++)
		{ 
			r[no] = rand() % 4;//0 for moving right, 1 for moving left, 2 for moving up, 3 for moving down.
			/*if(aiCoordinate[no].X + 1 == charLocation.X)
			{
				aiCoordinate[no].X++;
			}
			else if(aiCoordinate[no].X - 1 == charLocation.X)
			{
				aiCoordinate[no].X--;
			}
			else if(aiCoordinate[no].Y - 1 == charLocation.Y)
			{
				aiCoordinate[no].Y--;
			}
			else if(aiCoordinate[no].Y + 1 == charLocation.Y)
			{
				aiCoordinate[no].Y++;
			}*/
			if( r[no] == 0 && g_map[aiCoordinate[no].Y][aiCoordinate[no].X + 1] != 1)//right
			{
				aiCoordinate[no].X++;
			}
			else if( r[no] == 1 && g_map[aiCoordinate[no].Y][aiCoordinate[no].X - 1] != 1)//left
			{
				aiCoordinate[no].X--;
			}
			else if( r[no] == 2 && g_map[aiCoordinate[no].Y - 1][aiCoordinate[no].X] != 1)//up
			{
				aiCoordinate[no].Y--;
			}
			else if( r[no] == 3 && g_map[aiCoordinate[no].Y + 1][aiCoordinate[no].X] != 1)//down
			{
				aiCoordinate[no].Y++;
			}
		}
}
void crazyMonSpawn(int x,int y,int z)
{
	aiCoordinate[z].X = x;
	aiCoordinate[z].Y = y;
}


void followMon(int i)
{
	for(int b = 0; b < i; ++b)
	{
		console.writeToBuffer(monCoordinate[b], (char)154, 0x0C);
	}
}
void followMonUpdate(int z)
{
	for (int no = 0; no < z;no++)
	{
		if(aiCoordinate[no].X + 1 == charLocation.X)
		{
			monCoordinate[no].X++;
		}
		else if(aiCoordinate[no].X - 1 == charLocation.X)
		{
			monCoordinate[no].X--;
		}
		else if(aiCoordinate[no].Y - 1 == charLocation.Y)
		{
			monCoordinate[no].Y--;
		}
		else if(aiCoordinate[no].Y + 1 == charLocation.Y)
		{
			monCoordinate[no].Y++;
		}
	}
}
void followMonSpawn(int x,int y,int z)
{
	monCoordinate[z].X = x;
	monCoordinate[z].Y = y;
}