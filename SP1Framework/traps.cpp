#include "traps.h"

extern Console console;
extern double elapsedTime;
extern double deltaTime;
double velocity;

Cannon Right;
Cannon Left;
Cannon Up;
Cannon Down;

//g_timer.getElapsedTime()

//placed in render
void cannonR(int &i)
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
void cannonL(int &i)
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
void cannonU(int &i)
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
void cannonD(int &i)
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
void speed(int x, int y, double w)
{
	if(velocity > w)
		return;
	velocity = w + 0.250;
	cannonballR(x, y);
	cannonballL(x, y);
	cannonballU(x, y);
	cannonballD(x, y);
}

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