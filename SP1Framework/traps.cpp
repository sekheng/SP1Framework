#include "traps.h"

extern Console console;
//COORD cannonballLocationR[20];
//COORD cannonLocationR[20];
//COORD cannonballLocationL[20];
//COORD cannonLocationL[20];
//COORD cannonballLocationU[20];
//COORD cannonLocationU[20];
//COORD cannonballLocationD[20];
//COORD cannonLocationD[20];

Cannon Right;
Cannon Left;
Cannon Up;
Cannon Down;

//placed in render
void cannonR(int &i)
{
	for (int b = 0; b < i; b++)
	{
		console.writeToBuffer(Right.position[b], (char)67, 0x0C);
		console.writeToBuffer(Right.directions[b], (char)79, 0x0C);
	}
}
void cannonL(int &i)
{
	for (int b = 0; b < i; b++)
	{
		console.writeToBuffer(Left.position[b], (char)67, 0x0C);
		console.writeToBuffer(Left.directions[b], (char)79, 0x0C);
	}
}
void cannonU(int &i)
{
	for (int b = 0; b < i; b++)
	{
		console.writeToBuffer(Up.position[b], (char)67, 0x0C);
		console.writeToBuffer(Up.directions[b], (char)79, 0x0C);
	}
}
void cannonD(int &i)
{
	for (int b = 0; b < i; b++)
	{
		console.writeToBuffer(Down.position[b], (char)67, 0x0C);
		console.writeToBuffer(Down.directions[b], (char)79, 0x0C);
	}
}

//placed in update
void cannonballR(int x,int z)
{
	for (int no = 0; no < z;no++)
	{
		if (Right.directions[no].X != (Right.position[no].X + x) && g_timer.getElapsedTime() != -1)
		{
			Right.directions[no].X++;
		}
		else
		{
			Right.directions[no].X -= x;
		}
	}

}
void cannonballL(int x,int z)
{
	for (int no = 0; no < z; no++)
	{
		if (Left.directions[no].X != (Left.position[no].X - x) && g_timer.getElapsedTime() != -1)
		{
			Left.directions[no].X--;
		}
		else
		{
			Left.directions[no].X += x;
		}
	}

}
void cannonballU(int x,int z)
{
	for (int no = 0; no < z;no++)
	{
		if (Up.directions[no].Y != (Up.position[no].Y - x) && g_timer.getElapsedTime() != -1)
		{
			Up.directions[no].Y--;
		}
		else
		{
			Up.directions[no].Y += x;
		}
	}

}
void cannonballD(int x,int z)
{
	for (int no = 0; no < z;no++)
	{
		if (Down.directions[no].Y != (Down.position[no].Y + x) && g_timer.getElapsedTime() != -1)
		{
			Down.directions[no].Y++;
		}
		else
		{
			Down.directions[no].Y -= x;
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