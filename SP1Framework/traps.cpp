#include "traps.h"

extern Console console;
extern double elapsedTime;
extern double deltaTime;
extern size_t g_map[200][200];;
extern size_t g_customizemap[140][100];
extern Block block;

Cannon Right;
Cannon Left;
Cannon Up;
Cannon Down;
//g_timer.getElapsedTime()

//placed in render
void cannonR(int i)
{
	for (int b = 0; b < i; b++)
	{
		if(Right.position[b].X != 0 && Right.position[b].Y != 0)
		{
			console.writeToBuffer(Right.position[b], (char)67, 0x0C);
			console.writeToBuffer(Right.directions[b], (char)79, 0x0C);
		}
	}
}
void cannonL(int i)
{
	for (int b = 0; b < i; b++)
	{
		if(Left.position[b].X != 0 && Left.position[b].Y != 0)
		{
			console.writeToBuffer(Left.position[b], (char)67, 0x0C);
			console.writeToBuffer(Left.directions[b], (char)79, 0x0C);
		}
	}
}
void cannonU(int i)
{
	for (int b = 0; b < i; b++)
	{
		if(Up.position[b].X != 0 && Up.position[b].Y != 0)
		{
			console.writeToBuffer(Up.position[b], (char)67, 0x0C);
			console.writeToBuffer(Up.directions[b], (char)79, 0x0C);
		}
	}
}
void cannonD(int i)
{
	for (int b = 0; b < i; b++)
	{
		if(Down.position[b].X != 0 && Down.position[b].Y != 0)
		{
			console.writeToBuffer(Down.position[b], (char)67, 0x0C);
			console.writeToBuffer(Down.directions[b], (char)79, 0x0C);
		}
	}
}

//placed in init under converter
void locationR(int x, int y,int z)
{
	
	Right.directions[z].X = x;
	Right.directions[z].Y = y;
	Right.position[z].X = x;
	Right.position[z].Y = y;
	
}
void locationL(int x, int y,int z)
{
	Left.directions[z].X = x;
	Left.directions[z].Y = y;
	Left.position[z].X = x;
	Left.position[z].Y = y;
}
void locationU(int x, int y,int z)
{
	Up.directions[z].X = x;
	Up.directions[z].Y = y;
	Up.position[z].X = x;
	Up.position[z].Y = y;
}
void locationD(int x, int y,int z)
{
	Down.directions[z].X = x;
	Down.directions[z].Y = y;
	Down.position[z].X = x;
	Down.position[z].Y = y;
}

//placed in update

void cannonballR(int x,int z, int i)
{
	for (int no = 0; no < z;no++)
	{
		//double velocity = j +0.001;
		if (Right.directions[no].X != (Right.position[no].X + x) && g_map[Right.directions[no].Y][Right.directions[no].X + 1] == 0)
		{
			Right.directions[no].X++;
		}
		else if( g_map[Right.directions[no].Y][Right.directions[no].X + 1] != 0 || Right.directions[no].X == (Right.position[no].X + x))
		{
			Right.directions[no].X =Right.position[no].X;
		}
		for(int a  = 0; a < i; a++)
		{
			if(block.directions[a].X == Right.directions[no].X
				&& block.directions[a].Y == Right.directions[no].Y 
				|| block.directions[a].X == Right.position[no].X)
			{
				Right.directions[no].X = Right.position[no].X;
			}
		}
	}
}
void cannonballL(int x,int z, int i)
{
	for (int no = 0; no < z; no++)
	{
		if (Left.directions[no].X != (Left.position[no].X - x) && g_map[Left.directions[no].Y][Left.directions[no].X - 1] != 1 )
		{
			Left.directions[no].X--;
		}
		else if ( g_map[Left.directions[no].Y][Left.directions[no].X - 1] == 1 || Left.directions[no].X == (Left.position[no].X - x)) 
		{
			Left.directions[no].X = Left.position[no].X;
		}
		for(int a  = 0; a < i; a++)
		{
			if(block.directions[a].X == Left.directions[no].X
				&& block.directions[a].Y == Left.directions[no].Y 
				|| block.directions[a].X == Left.position[no].X)
			{
				Left.directions[no].X = Left.position[no].X;
			}
		}
	}

}
void cannonballU(int x,int z, int i)
{
	for (int no = 0; no < z;no++)
	{
		if (Up.directions[no].Y != (Up.position[no].Y - x) && g_map[Up.directions[no].Y - 1][Up.directions[no].X] != 1)
		{
			Up.directions[no].Y--;
		}
		else if (Up.directions[no].Y == (Up.position[no].Y - x) || g_map[Up.directions[no].Y - 1][Up.directions[no].X] == 1)
		{
			Up.directions[no].Y = Up.position[no].Y;
		}
		for(int a  = 0; a < i; a++)
		{
			if(block.directions[a].X == Up.directions[no].X
				&& block.directions[a].Y == Up.directions[no].Y 
				|| block.directions[a].Y == Up.position[no].Y)
			{
				Up.directions[no].Y = Up.position[no].Y;
			}
		}
	}

}
void cannonballD(int x,int z, int i)
{
	for (int no = 0; no < z;no++)
	{
		if (Down.directions[no].Y != (Down.position[no].Y + x) && g_map[Down.directions[no].Y + 1][Down.directions[no].X] != 1)
		{
			Down.directions[no].Y++;
		}
		else if(Down.directions[no].Y == (Down.position[no].Y + x) || g_map[Down.directions[no].Y + 1][Down.directions[no].X] == 1)
		{
			Down.directions[no].Y = Down.position[no].Y;
		}
		for(int a  = 0; a < i; a++)
		{
			if(block.directions[a].X == Down.directions[no].X
				&& block.directions[a].Y == Down.directions[no].Y 
				|| block.directions[a].Y == Down.position[no].Y)
			{
				Down.directions[no].Y = Down.position[no].Y;
			}
		}
	}

}

void render_cannons(int z,int a, int b, int c)
{
	cannonR(z);
	cannonL(a);
	cannonU(b);
	cannonD(c);
}