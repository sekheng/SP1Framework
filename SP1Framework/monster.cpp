#include "monster.h"
extern Console console;
extern COORD charLocation;
extern size_t g_map[200][200];
extern double timeTriggeredCrazy;
int r[MAX_SPACE];

COORD aiCoordinate[MAX_SPACE];
COORD monCoordinate[MAX_SPACE];

Monster crazy;
Monster follow;

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
			if((aiCoordinate[no].X + 1) == charLocation.X 
				||(aiCoordinate[no].X - 1) == charLocation.X
				||(aiCoordinate[no].Y + 1) == charLocation.Y
				||(aiCoordinate[no].Y - 1) == charLocation.Y)
			{
				if(aiCoordinate[no].X > charLocation.X && g_map[aiCoordinate[no].Y][aiCoordinate[no].X - 1] == 0)
				{
					aiCoordinate[no].X--;
				}
				else if(aiCoordinate[no].Y > charLocation.Y && g_map[aiCoordinate[no].Y - 1][aiCoordinate[no].X] == 0)
				{
					aiCoordinate[no].Y--;
				}
				else if(aiCoordinate[no].Y < charLocation.Y && g_map[aiCoordinate[no].Y + 1][aiCoordinate[no].X] == 0)
				{
					aiCoordinate[no].Y++;
				}
				else if(aiCoordinate[no].X < charLocation.X && g_map[aiCoordinate[no].Y][aiCoordinate[no].X + 1] == 0)
				{
					aiCoordinate[no].X++;
				}
			}
			//else if( r[no] == 0 && g_map[aiCoordinate[no].Y][aiCoordinate[no].X + 1] != 1)//right
			//{
			//	aiCoordinate[no].X++;
			//}
			//else if( r[no] == 1 && g_map[aiCoordinate[no].Y][aiCoordinate[no].X - 1] != 1)//left
			//{
			//	aiCoordinate[no].X--;
			//}
			//else if( r[no] == 2 && g_map[aiCoordinate[no].Y - 1][aiCoordinate[no].X] != 1)//up
			//{
			//	aiCoordinate[no].Y--;
			//}
			//else if( r[no] == 3 && g_map[aiCoordinate[no].Y + 1][aiCoordinate[no].X] != 1)//down
			//{
			//	aiCoordinate[no].Y++;
			//}
		}
}
void crazyMonSpawn(int x,int y,int z)
{
	aiCoordinate[z].X = x;
	aiCoordinate[z].Y = y;
	crazy.resetCoord[z].X = x;
	crazy.resetCoord[z].Y = y;
	//restartCrazyMonLocation(z);
}


void followMon(int i)
{
	for(int b = 0; b < i; ++b)
	{
		console.writeToBuffer(monCoordinate[b], (char)154, 0x0C);
	}
}
void followMonUpdate(int z,double w)
{
	for (int no = 0; no < z;no++)
	{
		r[no] = rand() %10;
		
		if(monCoordinate[no].X > charLocation.X && g_map[monCoordinate[no].Y][monCoordinate[no].X - 1] == 0)
		{
			monCoordinate[no].X--;
		}
		else if(monCoordinate[no].Y > charLocation.Y && g_map[monCoordinate[no].Y - 1][monCoordinate[no].X] == 0)
		{
			monCoordinate[no].Y--;
		}
		else if(monCoordinate[no].Y < charLocation.Y && g_map[monCoordinate[no].Y + 1][monCoordinate[no].X] == 0)
		{
			monCoordinate[no].Y++;
		}
		else if(monCoordinate[no].X < charLocation.X && g_map[monCoordinate[no].Y][monCoordinate[no].X + 1] == 0)
		{
			monCoordinate[no].X++;
		}
	}
}
void followMonSpawn(int x,int y,int z)
{
	monCoordinate[z].X = x;
	monCoordinate[z].Y = y;
	follow.resetCoord[z].X = x;
	follow.resetCoord[z].Y = y;
	//restartFollowMonLoca tion(z);
}

void restartCrazyMonLocation(int z)
{
	for ( int i = 0; i < z; ++i)
    {
		aiCoordinate[i].X = crazy.resetCoord[i].X;
		aiCoordinate[i].Y = crazy.resetCoord[i].Y;
	}
}

void restartFollowMonLocation(int z)
{
	for ( int i = 0; i < z; ++i)
    {
		monCoordinate[i].X = follow.resetCoord[i].X;
		monCoordinate[i].Y = follow.resetCoord[i].Y;
	}
}


