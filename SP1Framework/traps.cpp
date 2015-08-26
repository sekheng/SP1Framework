#include "traps.h"

extern Console console;
extern double elapsedTime;
extern double deltaTime;

int icoordR = 0;
int icoordL = 0;
int icoordU = 0;
int icoordD = 0;

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
	if (icoordR <= z)
	{
		Right.directions[icoordR].X = x;
		Right.directions[icoordR].Y = y;
		Right.position[icoordR].X = x;
		Right.position[icoordR].Y = y;
		icoordR++;
	}
}
void locationL(int x, int y,int z)
{
	if (icoordL <= z)
	{
		Left.directions[icoordL].X = x;
		Left.directions[icoordL].Y = y;
		Left.position[icoordL].X = x;
		Left.position[icoordL].Y = y;
		icoordL++;
	}
}
void locationU(int x, int y,int z)
{
	if (icoordU <= z)
	{
		Up.directions[icoordU].X = x;
		Up.directions[icoordU].Y = y;
		Up.position[icoordU].X = x;
		Up.position[icoordU].Y = y;
		icoordU++;
	}
}
void locationD(int x, int y,int z)
{
	if (icoordD <= z)
	{
		Down.directions[icoordD].X = x;
		Down.directions[icoordD].Y = y;
		Down.position[icoordD].X = x;
		Down.position[icoordD].Y = y;
		icoordD++;
	}
}

//placed in update

void cannonballR(int x,int z)
{
	for (int no = 0; no < z;no++)
	{
		//double velocity = j +0.001;
		if (Right.directions[no].X != (Right.position[no].X + x))
		{
			Right.directions[no].X+= 1;
		}
		else
		{
			Right.directions[no].X =Right.position[no].X;
		}
	}
}
void cannonballL(int x,int z)
{
	for (int no = 0; no < z; no++)
	{
		if (Left.directions[no].X != (Left.position[no].X - x))
		{
			Left.directions[no].X--;
		}
		else
		{
			Left.directions[no].X = Left.position[no].X;
		}
	}

}
void cannonballU(int x,int z)
{
	for (int no = 1; no < z;no++)
	{
		if (Up.directions[no].Y != (Up.position[no].Y - x))
		{
			Up.directions[no].Y--;
		}
		else
		{
			Up.directions[no].Y = Up.position[no].Y;
		}
	}

}
void cannonballD(int x,int z)
{
	for (int no = 0; no < z;no++)
	{
		if (Down.directions[no].Y != (Down.position[no].Y + x))
		{
			Down.directions[no].Y++;
		}
		else
		{
			Down.directions[no].Y = Down.position[no].Y;
		}
	}

}

void render_cannons(int z)
{
	cannonL(z);
	cannonR(z);
	cannonU(z);
	cannonD(z);
}