#include "monster.h"
#include "BGMsounds.h"
extern Console console;
extern COORD charLocation;
extern size_t g_map[200][200];
extern double timeTriggeredCrazy;
extern Block block;
int r[MAX_SPACE];

COORD aiCoordinate[MAX_SPACE];
COORD monCoordinate[MAX_SPACE];

Monster crazy;
Monster follow;

void crazyMon(int i)
{
	for(int b = 0; b < i; ++b)
	{
		console.writeToBuffer(aiCoordinate[b], (char)153, 0x1D);
	}
}
void crazyMonUpdate(int z, int y)
{
		for (int no = 0; no < z;no++)
		{ 
			for(int a = 0; a < y; a++)
			{
				if((aiCoordinate[no].X - 1 == block.directions[a].X 
						&& aiCoordinate[no].Y == block.directions[a].Y)
						&& g_map[aiCoordinate[no].Y][aiCoordinate[no].X + 1] != 1)
				{
					aiCoordinate[no].X++;
				}
				if((aiCoordinate[no].Y - 1 == block.directions[a].Y 
						&& aiCoordinate[no].X == block.directions[a].X)
						&& g_map[aiCoordinate[no].Y + 1][aiCoordinate[no].X] != 1)
				{
					aiCoordinate[no].Y++;
				}
				if((aiCoordinate[no].Y + 1 == block.directions[a].Y 
						&& aiCoordinate[no].X == block.directions[a].X)
						&& g_map[aiCoordinate[no].Y - 1][aiCoordinate[no].X] != 1)
				{
					aiCoordinate[no].Y--;
				}
				if((aiCoordinate[no].X + 1 == block.directions[a].X 
						&& aiCoordinate[no].Y == block.directions[a].Y)
						&& g_map[aiCoordinate[no].Y][aiCoordinate[no].X - 1] != 1)
				{
					monCoordinate[no].X--;
				}
			}
				r[no] = rand() % 4;//0 for moving right, 1 for moving left, 2 for moving up, 3 for moving down.
				if(((((aiCoordinate[no].X + 3) >= charLocation.X) &&(aiCoordinate[no].X - 3) <= charLocation.X) 
					&& ((aiCoordinate[no].Y +3) >= charLocation.Y) && (aiCoordinate[no].Y - 3) <= charLocation.Y))
				{
				
					if(aiCoordinate[no].X > charLocation.X 
						&& g_map[aiCoordinate[no].Y][aiCoordinate[no].X - 1] != 1)
					{
						aiCoordinate[no].X--;
                        PlayingBeingChased();
					}
					if(aiCoordinate[no].Y > charLocation.Y 
						&& g_map[aiCoordinate[no].Y - 1][aiCoordinate[no].X] != 1)
					{
						aiCoordinate[no].Y--;
                        PlayingBeingChased();
					}
					if(aiCoordinate[no].Y < charLocation.Y 
						&& g_map[aiCoordinate[no].Y + 1][aiCoordinate[no].X] != 1)
					{
						aiCoordinate[no].Y++;
                        PlayingBeingChased();
					}
					if(aiCoordinate[no].X < charLocation.X 
						&& g_map[aiCoordinate[no].Y][aiCoordinate[no].X + 1] != 1)
					{
						aiCoordinate[no].X++;
                        PlayingBeingChased();
					}
				}
				else
				{
				    pauseTheChasingSound();
					if( r[no] == 0 && g_map[aiCoordinate[no].Y][aiCoordinate[no].X + 1] != 1)//right
					{
						aiCoordinate[no].X++;
					}
					if( r[no] == 1 && g_map[aiCoordinate[no].Y][aiCoordinate[no].X - 1] != 1)//left
					{
						aiCoordinate[no].X--;
					}
					if( r[no] == 2 && g_map[aiCoordinate[no].Y - 1][aiCoordinate[no].X] != 1)//up
					{
						aiCoordinate[no].Y--;
					}
					if( r[no] == 3 && g_map[aiCoordinate[no].Y + 1][aiCoordinate[no].X] != 1)//down
					{
						aiCoordinate[no].Y++;
					}
				
				}
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
		console.writeToBuffer(monCoordinate[b], (char)154, 0x1B);
	}
}
void followMonUpdate(int z,int y, double w)
{
	for (int no = 0; no < z;no++)
	{
		for(int a = 0; a < y; a++)
		{
			if((monCoordinate[no].X - 1 == block.directions[a].X 
					&& monCoordinate[no].Y == block.directions[a].Y)
					&& g_map[monCoordinate[no].Y][monCoordinate[no].X + 1] != 1)
			{
				monCoordinate[no].X++;
			}
			if((monCoordinate[no].Y - 1 == block.directions[a].Y 
					&& monCoordinate[no].X == block.directions[a].X)
					&& g_map[monCoordinate[no].Y + 1][monCoordinate[no].X] != 1)
			{
				monCoordinate[no].Y++;
			}
			if((monCoordinate[no].Y + 1 == block.directions[a].Y 
					&& monCoordinate[no].X == block.directions[a].X)
					&& g_map[monCoordinate[no].Y - 1][monCoordinate[no].X] != 1)
			{
				monCoordinate[no].Y--;
			}
			if((monCoordinate[no].X + 1 == block.directions[a].X 
					&& monCoordinate[no].Y == block.directions[a].Y)
					&& g_map[monCoordinate[no].Y][monCoordinate[no].X - 1] != 1)
			{
				monCoordinate[no].X--;
			}
		}
		
			if(monCoordinate[no].X > charLocation.X 
				&& g_map[monCoordinate[no].Y][monCoordinate[no].X - 1] != 1)
			{
				monCoordinate[no].X--;
			}
			if(monCoordinate[no].Y > charLocation.Y 
				&& g_map[monCoordinate[no].Y - 1][monCoordinate[no].X] != 1)
			{
				monCoordinate[no].Y--;
			}
			if(monCoordinate[no].Y < charLocation.Y 
				&& g_map[monCoordinate[no].Y + 1][monCoordinate[no].X] != 1)
			{
				monCoordinate[no].Y++;
			}
			if(monCoordinate[no].X < charLocation.X 
				&& g_map[monCoordinate[no].Y][monCoordinate[no].X + 1] != 1)
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


