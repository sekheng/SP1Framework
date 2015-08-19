#include "playerchar.h"
//#include "traps.cpp"

extern COORD startmenuLocation;
extern COORD charLocation;
extern size_t g_map[140][100];
extern COORD cannonballLocationR[20];	
extern Console console;
extern int cno;
extern startscreen state;
extern bool keyPressed[K_COUNT];

void characterInit()
{
	charLocation.X = 10;
	charLocation.Y = 10;
}

void characterMovement()
{
	if (state == menu)
	{
		if (keyPressed[K_UP] && startmenuLocation.Y > 21)
		{
			Beep(1440, 30);
			startmenuLocation.Y--;
		}
		if (keyPressed[K_DOWN] && startmenuLocation.Y < 26)
		{
			Beep(1440, 30);
			startmenuLocation.Y++;
		}
		if (keyPressed[K_ENTER] && startmenuLocation.Y == 21)
		{
			state = Start;

		}
		if (keyPressed[K_ENTER] && startmenuLocation.Y == 22)
		{
			state = LevelCustomized;
		}
		if (keyPressed[K_ENTER] && startmenuLocation.Y == 23)
		{
			state = LevelCustom;
		}
		if (keyPressed[K_ENTER] && startmenuLocation.Y == 26)
		{
			state = Exit;
		}
	}

	if (state == Exit)
	{
		g_quitGame = true;
	}

	if (state == Start)   // The Game Begins!
	{
		// Updating the location of the character based on the key press
		if (keyPressed[K_UP] & keyPressed[K_W] && charLocation.Y > 0 && g_map[charLocation.Y + 2][charLocation.X] != 1)
		{
			Beep(1440, 30);
			charLocation.Y++;
		}
		if (keyPressed[K_LEFT] & keyPressed[K_A] && charLocation.X && g_map[charLocation.Y][charLocation.X + 1] != 1)
		{
			Beep(1440, 30);
			charLocation.X++;
		}
		if (keyPressed[K_DOWN] & keyPressed[K_S] && charLocation.Y - 1 && g_map[charLocation.Y][charLocation.X] != 1)
		{
			Beep(1440, 30);
			charLocation.Y--;
		}
		if (keyPressed[K_RIGHT] & keyPressed[K_D] && charLocation.X - 1 && g_map[charLocation.Y][charLocation.X - 1] != 1)
		{
			Beep(1440, 30);
			charLocation.X--;
		}

		if (keyPressed[K_UP] && charLocation.Y > 0 && g_map[charLocation.Y - 1][charLocation.X] != 1)
		{
			Beep(1440, 30);
			charLocation.Y--;
		}
		if (keyPressed[K_LEFT] && charLocation.X > 0 && g_map[charLocation.Y][charLocation.X - 1] != 1)
		{
			Beep(1440, 30);
			charLocation.X--;
		}
		if (keyPressed[K_DOWN] && charLocation.Y < console.getConsoleSize().Y - 1 && g_map[charLocation.Y + 1][charLocation.X] != 1)
		{
			Beep(1440, 30);
			charLocation.Y++;
		}
		if (keyPressed[K_RIGHT] /*&& charLocation.X < console.getConsoleSize().X - 1*/ && g_map[charLocation.Y][charLocation.X + 1] != 1)
		{
			Beep(1440, 30);
			charLocation.X++;
		}

		if (keyPressed[K_W] && charLocation.Y > 0 && g_map[charLocation.Y - 1][charLocation.X] != 1)  //up
		{
			Beep(1440, 30);
			charLocation.Y--;
		}
		if (keyPressed[K_A] && charLocation.X > 0 && g_map[charLocation.Y][charLocation.X - 1] != 1)  //left
		{
			Beep(1440, 30);
			charLocation.X--;
		}
		if (keyPressed[K_S] && charLocation.Y < console.getConsoleSize().Y - 1 && g_map[charLocation.Y + 1][charLocation.X] != 1)  //down
		{
			Beep(1440, 30);
			charLocation.Y++;
		}
		if (keyPressed[K_D] /*&& charLocation.X < console.getConsoleSize().X - 1*/ && g_map[charLocation.Y][charLocation.X + 1] != 1)   //right
		{
			Beep(1440, 30);
			charLocation.X++;
		}
		cannonballR(3, cno);//3 is ball movement distance
		characterInteraction();
	}
	if (state == LevelCustomized)
	{
		// Updating the location of the character based on the key press
		if (keyPressed[K_UP] & keyPressed[K_W] && charLocation.Y > 0)
		{
			Beep(1440, 30);
			charLocation.Y++;
		}
		if (keyPressed[K_LEFT] & keyPressed[K_A] && charLocation.X)
		{
			Beep(1440, 30);
			charLocation.X++;
		}
		if (keyPressed[K_DOWN] & keyPressed[K_S] && charLocation.Y - 1)
		{
			Beep(1440, 30);
			charLocation.Y--;
		}
		if (keyPressed[K_RIGHT] & keyPressed[K_D] && charLocation.X - 1)
		{
			Beep(1440, 30);
			charLocation.X--;
		}

		if (keyPressed[K_UP] && charLocation.Y > 0)
		{
			Beep(1440, 30);
			charLocation.Y--;
		}
		if (keyPressed[K_LEFT] && charLocation.X > 0)
		{
			Beep(1440, 30);
			charLocation.X--;
		}
		if (keyPressed[K_DOWN] && charLocation.Y < console.getConsoleSize().Y - 1)
		{
			Beep(1440, 30);
			charLocation.Y++;
		}
		if (keyPressed[K_RIGHT] && charLocation.X < console.getConsoleSize().X - 1)
		{
			Beep(1440, 30);
			charLocation.X++;
		}

		if (keyPressed[K_W] && charLocation.Y > 0)  //up
		{
			Beep(1440, 30);
			charLocation.Y--;
		}
		if (keyPressed[K_A] && charLocation.X > 0)  //left
		{
			Beep(1440, 30);
			charLocation.X--;
		}
		if (keyPressed[K_S] && charLocation.Y < console.getConsoleSize().Y - 1)  //down
		{
			Beep(1440, 30);
			charLocation.Y++;
		}
		if (keyPressed[K_D] && charLocation.X < console.getConsoleSize().X - 1)   //right
		{
			Beep(1440, 30);
			charLocation.X++;
		}
	}

	if (state == LevelCustom)
	{
		// Updating the location of the character based on the key press
		if (keyPressed[K_UP] & keyPressed[K_W] && charLocation.Y > 0 && g_map[charLocation.Y + 2][charLocation.X] != 1)
		{
			Beep(1440, 30);
			charLocation.Y++;
		}
		if (keyPressed[K_LEFT] & keyPressed[K_A] && charLocation.X && g_map[charLocation.Y][charLocation.X + 1] != 1)
		{
			Beep(1440, 30);
			charLocation.X++;
		}
		if (keyPressed[K_DOWN] & keyPressed[K_S] && charLocation.Y - 1 && g_map[charLocation.Y][charLocation.X] != 1)
		{
			Beep(1440, 30);
			charLocation.Y--;
		}
		if (keyPressed[K_RIGHT] & keyPressed[K_D] && charLocation.X - 1 && g_map[charLocation.Y][charLocation.X - 1] != 1)
		{
			Beep(1440, 30);
			charLocation.X--;
		}

		if (keyPressed[K_UP] && charLocation.Y > 0 && g_map[charLocation.Y - 1][charLocation.X] != 1)
		{
			Beep(1440, 30);
			charLocation.Y--;
		}
		if (keyPressed[K_LEFT] && charLocation.X > 0 && g_map[charLocation.Y][charLocation.X - 1] != 1)
		{
			Beep(1440, 30);
			charLocation.X--;
		}
		if (keyPressed[K_DOWN] && charLocation.Y < console.getConsoleSize().Y - 1 && g_map[charLocation.Y + 1][charLocation.X] != 1)
		{
			Beep(1440, 30);
			charLocation.Y++;
		}
		if (keyPressed[K_RIGHT] /*&& charLocation.X < console.getConsoleSize().X - 1*/ && g_map[charLocation.Y][charLocation.X + 1] != 1)
		{
			Beep(1440, 30);
			charLocation.X++;
		}

		if (keyPressed[K_W] && charLocation.Y > 0 && g_map[charLocation.Y - 1][charLocation.X] != 1)  //up
		{
			Beep(1440, 30);
			charLocation.Y--;
		}
		if (keyPressed[K_A] && charLocation.X > 0 && g_map[charLocation.Y][charLocation.X - 1] != 1)  //left
		{
			Beep(1440, 30);
			charLocation.X--;
		}
		if (keyPressed[K_S] && charLocation.Y < console.getConsoleSize().Y - 1 && g_map[charLocation.Y + 1][charLocation.X] != 1)  //down
		{
			Beep(1440, 30);
			charLocation.Y++;
		}
		if (keyPressed[K_D] /*&& charLocation.X < console.getConsoleSize().X - 1*/ && g_map[charLocation.Y][charLocation.X + 1] != 1)   //right
		{
			Beep(1440, 30);
			charLocation.X++;
		}
		cannonballR(3, cno);//3 is ball movement distance
	}

}

void getInput()
{
	keyPressed[K_UP] = isKeyPressed(VK_UP);
	keyPressed[K_DOWN] = isKeyPressed(VK_DOWN);
	keyPressed[K_LEFT] = isKeyPressed(VK_LEFT);
	keyPressed[K_RIGHT] = isKeyPressed(VK_RIGHT);
	keyPressed[K_W] = isKeyPressed(0x57);
	keyPressed[K_A] = isKeyPressed(0x41);
	keyPressed[K_S] = isKeyPressed(0x53);
	keyPressed[K_D] = isKeyPressed(0x44);
	keyPressed[K_ESCAPE] = isKeyPressed(VK_ESCAPE);
	keyPressed[K_ENTER] = isKeyPressed(VK_RETURN);
	keyPressed[K_SPACE] = isKeyPressed(VK_SPACE);
}

void characterInteraction()
{
	for (int i = 0; i < cno; ++i)
	{
		if (charLocation.X == cannonballLocationR[i].X && charLocation.Y == cannonballLocationR[i].Y)
		{
			g_quitGame = true;
		}
	}
}