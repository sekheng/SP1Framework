#include "traps.h"

extern Console console;
COORD cannonballLocationR[20];
COORD cannonLocationR[20];
COORD cannonballLocationL[20];
COORD cannonLocationL[20];
COORD cannonballLocationU[20];
COORD cannonLocationU[20];
COORD cannonballLocationD[20];
COORD cannonLocationD[20];

void cannonR(int &i)
{
	for (int b = 0; b < i; b++)
	{
		console.writeToBuffer(cannonLocationR[b], (char)67, 0x0C);
		console.writeToBuffer(cannonballLocationR[b], (char)79, 0x0C);
	}
}
void cannonballR(int x,int z)
{
	for (int no = 0; no < z;no++)
	{
		if (cannonballLocationR[no].X != (cannonLocationR[no].X + x) && g_timer.getElapsedTime() != -1)
		{
			cannonballLocationR[no].X++;
		}
		else
		{
			cannonballLocationR[no].X -= x;
		}
	}

}
void locationR(int x, int y,int z)
{
	cannonballLocationR[z].X = x;
	cannonballLocationR[z].Y = y;
	cannonLocationR[z].X = x;
	cannonLocationR[z].Y = y;
}

void cannonL(int &i)
{
	for (int b = 0; b < i; b++)
	{
		console.writeToBuffer(cannonLocationL[b], (char)67, 0x0C);
		console.writeToBuffer(cannonballLocationL[b], (char)79, 0x0C);
	}
}
void cannonballL(int x,int z)
{
	for (int no = 0; no < z; no++)
	{
		if (cannonballLocationL[no].X != (cannonLocationL[no].X - x) && g_timer.getElapsedTime() != -1)
		{
			cannonballLocationL[no].X--;
		}
		else
		{
			cannonballLocationL[no].X += x;
		}
	}

}
void locationL(int x, int y,int z)
{
	cannonballLocationL[z].X = x;
	cannonballLocationL[z].Y = y;
	cannonLocationL[z].X = x;
	cannonLocationL[z].Y = y;
}

void cannonU(int &i)
{
	for (int b = 0; b < i; b++)
	{
		console.writeToBuffer(cannonLocationU[b], (char)67, 0x0C);
		console.writeToBuffer(cannonballLocationU[b], (char)79, 0x0C);
	}
}
void cannonballU(int x,int z)
{
	for (int no = 0; no < z;no++)
	{
		if (cannonballLocationU[no].Y != (cannonLocationU[no].Y - x) && g_timer.getElapsedTime() != -1)
		{
			cannonballLocationU[no].Y--;
		}
		else
		{
			cannonballLocationU[no].Y += x;
		}
	}

}
void locationU(int x, int y,int z)
{
	cannonballLocationU[z].X = x;
	cannonballLocationU[z].Y = y;
	cannonLocationU[z].X = x;
	cannonLocationU[z].Y = y;
}

void cannonD(int &i)
{
	for (int b = 0; b < i; b++)
	{
		console.writeToBuffer(cannonLocationD[b], (char)67, 0x0C);
		console.writeToBuffer(cannonballLocationD[b], (char)79, 0x0C);
	}
}
void cannonballD(int x,int z)
{
	for (int no = 0; no < z;no++)
	{
		if (cannonballLocationD[no].Y != (cannonLocationD[no].Y + x) && g_timer.getElapsedTime() != -1)
		{
			cannonballLocationD[no].Y++;
		}
		else
		{
			cannonballLocationD[no].Y -= x;
		}
	}

}
void locationD(int x, int y,int z)
{
	cannonballLocationD[z].X = x;
	cannonballLocationD[z].Y = y;
	cannonLocationD[z].X = x;
	cannonLocationD[z].Y = y;
}