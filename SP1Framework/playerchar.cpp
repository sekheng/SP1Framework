#include "playerchar.h"

//#include "traps.cpp"

double velocityChar;
extern COORD startmenuLocation;
extern COORD charLocation;
extern COORD charCustomLocation;
extern size_t g_map[140][100];
extern struct Cannon Right;
extern struct Cannon Left;
extern struct Cannon Up;
extern struct Cannon Down;
extern struct Block block;
extern COORD aiCoordinate[20];
extern Console console;
extern int cno;
extern int mno;
extern int bno;
extern startscreen state;
extern bool keyPressed[K_COUNT];
extern string &level;
extern int levelno;
extern int tempX;
extern int tempY;
extern int tempEndX;
extern int tempEndY;
int RestartX;
int RestartY;
bool TheEndDoesNotContinue = false;
extern COORD CusLvL;
COORD pauseLocation;
COORD helpreturn;
COORD gameoverptr;

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
			//Beep(1440, 30);
			startmenuLocation.Y--;
		}
		else if (keyPressed[K_DOWN] && startmenuLocation.Y < 26)
		{
			//Beep(1440, 30);
			startmenuLocation.Y++;
		}
		else if (keyPressed[K_ENTER] && startmenuLocation.Y == 21)
		{
            if ( TheEndDoesNotContinue == true )
            {
                state = End;
            }
            else
            {
			    state = Start;
            }
		}
		else if (keyPressed[K_ENTER] && startmenuLocation.Y == 22)
		{
			state = LevelCustomized;
		}
		else if (keyPressed[K_ENTER] && startmenuLocation.Y == 23)
		{
			state = LevelCustom;
		}
        else if ( keyPressed[K_ENTER] && startmenuLocation.Y == 24 )
        {
            state = Help;
        }
		else if (keyPressed[K_ENTER] && startmenuLocation.Y == 26)
		{
			state = Exit;
		}

        if ( startmenuLocation.Y == 21)
        {
            startmenuLocation.X = 9;
        }
        else if (startmenuLocation.Y == 22) {
            startmenuLocation.X = 23;
        }
        else if ( startmenuLocation.Y == 23) {
            startmenuLocation.X = 21;
        }
        else if ( startmenuLocation.Y == 24)
        {
            startmenuLocation.X = 8;
        }
        else if ( startmenuLocation.Y == 25)
        {
            startmenuLocation.X = 11;
        }
        else
        {
            startmenuLocation.X = 8;
        }

	}

	else if (state == Exit)
	{
		g_quitGame = true;
	}

	else if (state == Start)   // The Game Begins!
	{
		// Updating the location of the character based on the key press
		if (keyPressed[K_UP] & keyPressed[K_W] && charLocation.Y > 0 && g_map[charLocation.Y + 2][charLocation.X] != 1)
		{
			//Beep(1440, 30);
			charLocation.Y++;
		}
		if (keyPressed[K_LEFT] & keyPressed[K_A] && charLocation.X && g_map[charLocation.Y][charLocation.X + 1] != 1)
		{
			//Beep(1440, 30);
			charLocation.X++;
		}
		if (keyPressed[K_DOWN] & keyPressed[K_S] && charLocation.Y - 1 && g_map[charLocation.Y][charLocation.X] != 1)
		{
			//Beep(1440, 30);
			charLocation.Y--;
		}
		if (keyPressed[K_RIGHT] & keyPressed[K_D] && charLocation.X - 1 && g_map[charLocation.Y][charLocation.X - 1] != 1)
		{
			//Beep(1440, 30);
			charLocation.X--;
		}

		if (keyPressed[K_UP] && charLocation.Y > 0 && g_map[charLocation.Y - 1][charLocation.X] != 1)
		{
			//Beep(1440, 30);
			charLocation.Y--;
		}
		if (keyPressed[K_LEFT] && charLocation.X > 0 && g_map[charLocation.Y][charLocation.X - 1] != 1)
		{
			//Beep(1440, 30);
			charLocation.X--;
		}
		if (keyPressed[K_DOWN] && charLocation.Y < console.getConsoleSize().Y - 1 && g_map[charLocation.Y + 1][charLocation.X] != 1)
		{
			//Beep(1440, 30);
			charLocation.Y++;
		}
		if (keyPressed[K_RIGHT] && g_map[charLocation.Y][charLocation.X + 1] != 1)
		{
			//Beep(1440, 30);
			charLocation.X++;
		}

		if (keyPressed[K_W] && charLocation.Y > 0 && g_map[charLocation.Y - 1][charLocation.X] != 1)  //up
		{
			//Beep(1440, 30);
			charLocation.Y--;
		}
		if (keyPressed[K_A] && charLocation.X > 0 && g_map[charLocation.Y][charLocation.X - 1] != 1)  //left
		{
			//Beep(1440, 30);
			charLocation.X--;
		}
		if (keyPressed[K_S] && charLocation.Y < console.getConsoleSize().Y - 1 && g_map[charLocation.Y + 1][charLocation.X] != 1)  //down
		{
			//Beep(1440, 30);
			charLocation.Y++;
		}
		if (keyPressed[K_D] && g_map[charLocation.Y][charLocation.X + 1] != 1)   //right
		{
			//Beep(1440, 30);
			charLocation.X++;
		}
		characterInteraction();
        // To Pause in-game
        if ( keyPressed[K_SPACE])
        {
            state = Pause;
		}
		characterEnd(tempEndY, tempEndX);
	}
    //Level Editing
	else if (state == LevelCustomized)
	{
		char edit = '0';
		if (keyPressed[K_SPACE])
		{
			state = menu;
		}
		if (keyPressed[K_L])
		{
			edit = 'L';
			writelevel(edit);
		}
		if (keyPressed[K_0])
		{
			edit = '0';
			writelevel(edit);
		}
		if (keyPressed[K_R])
		{
			edit = 'R';
			writelevel(edit);
		}
		if (keyPressed[K_U])
		{
			edit = 'U';
			writelevel(edit);
		}
		if (keyPressed[K_D])
		{
			edit = 'D';
			writelevel(edit);
		}
		if (keyPressed[K_1])
		{
			edit = '1';
			writelevel(edit);
		}
		if (keyPressed[K_S])
		{
			edit = 'S';
			writelevel(edit);
		}
		if (keyPressed[K_E])
		{
			edit = 'E';
			writelevel(edit);
		}
		if (keyPressed[K_M])
		{
			edit = 'M';
			writelevel(edit);
		}
		if (keyPressed[K_BOX])
		{
			edit = 'B';
			writelevel(edit);
		}
		if (keyPressed[K_1])
		{
			edit = '1';
			writelevel(edit);
		}
		if (keyPressed[K_0])
		{
			edit = '0';
			writelevel(edit);
		}
		if (keyPressed[K_BACK])
		{
			edit = '0';
			writelevel(edit);
		}
		if (keyPressed[K_ENTER])
		{
			savecustomlevel();
			state = menu;
		}
		if (keyPressed[K_UP] && charCustomLocation.Y > 0 )
		{
			//Beep(1440, 30);
			charCustomLocation.Y--;
		}
		if (keyPressed[K_LEFT] && charCustomLocation.X > 0 )
		{
			//Beep(1440, 30);
			charCustomLocation.X--;
		}
		if (keyPressed[K_DOWN] && charCustomLocation.Y < 17 )
		{
			//Beep(1440, 30);
			charCustomLocation.Y++;
		}
		if (keyPressed[K_RIGHT] )
		{
			//Beep(1440, 30);
			charCustomLocation.X++;
		}

    }

	else if (state == LevelCustom)
	{

		// Updating the location of the character based on the key press
		if (keyPressed[K_UP] & keyPressed[K_W] && charLocation.Y > 0 && g_map[charLocation.Y + 2][charLocation.X] != 1)
		{
			//Beep(1440, 30);
			charLocation.Y++;
		}
		if (keyPressed[K_LEFT] & keyPressed[K_A] && charLocation.X && g_map[charLocation.Y][charLocation.X + 1] != 1)
		{
			//Beep(1440, 30);
			charLocation.X++;
		}
		if (keyPressed[K_DOWN] & keyPressed[K_S] && charLocation.Y - 1 && g_map[charLocation.Y][charLocation.X] != 1)
		{
			//Beep(1440, 30);
			charLocation.Y--;
		}
		if (keyPressed[K_RIGHT] & keyPressed[K_D] && charLocation.X - 1 && g_map[charLocation.Y][charLocation.X - 1] != 1)
		{
			//Beep(1440, 30);
			charLocation.X--;
		}
		if (keyPressed[K_UP] && charLocation.Y > 0 && g_map[charLocation.Y - 1][charLocation.X] != 1)
		{
			//Beep(1440, 30);
			charLocation.Y--;
		}
		if (keyPressed[K_LEFT] && charLocation.X > 0 && g_map[charLocation.Y][charLocation.X - 1] != 1)
		{
			//Beep(1440, 30);
			charLocation.X--;
		}
		if (keyPressed[K_DOWN] && charLocation.Y < console.getConsoleSize().Y - 1 && g_map[charLocation.Y + 1][charLocation.X] != 1)
		{
			//Beep(1440, 30);
			charLocation.Y++;
		}
		if (keyPressed[K_RIGHT] /*&& charLocation.X < console.getConsoleSize().X - 1*/ && g_map[charLocation.Y][charLocation.X + 1] != 1)
		{
			//Beep(1440, 30);
			charLocation.X++;
		}

		if (keyPressed[K_W] && charLocation.Y > 0 && g_map[charLocation.Y - 1][charLocation.X] != 1)  //up
		{
			//Beep(1440, 30);
			charLocation.Y--;
		}
		if (keyPressed[K_A] && charLocation.X > 0 && g_map[charLocation.Y][charLocation.X - 1] != 1)  //left
		{
			//Beep(1440, 30);
			charLocation.X--;
		}
		if (keyPressed[K_S] && charLocation.Y < console.getConsoleSize().Y - 1 && g_map[charLocation.Y + 1][charLocation.X] != 1)  //down
		{
			//Beep(1440, 30);
			charLocation.Y++;
		}
		if (keyPressed[K_D] /*&& charLocation.X < console.getConsoleSize().X - 1*/ && g_map[charLocation.Y][charLocation.X + 1] != 1)   //right
		{
			//Beep(1440, 30);
			charLocation.X++;
		}
	}

    else if ( state == Pause )
    {
		if (keyPressed[K_UP] && pauseLocation.Y > 15)
		{
			//Beep(1440, 30);
			pauseLocation.Y--;
		}
		else if (keyPressed[K_DOWN] && pauseLocation.Y < 17)
		{
			//Beep(1440, 30);
			pauseLocation.Y++;
		}
        else if ( keyPressed[K_ENTER] && pauseLocation.Y == 15)
        {
            state = Start;
        }
        else if ( keyPressed[K_ENTER] && pauseLocation.Y == 16 )
        {
            characterSpawn(RestartX,RestartY);
            state = Start;
        }
        else if ( keyPressed[K_ENTER] && pauseLocation.Y == 17 )
        {
            state = menu;
        }
    }

    else if ( state == Help )
    {
        if ( keyPressed[K_SPACE] )
        {
            state = menu;
        }
    }

    else if ( state == GameOver)
    {
		if (keyPressed[K_UP] && gameoverptr.Y > 8)
		{
			//Beep(1440, 30);
			gameoverptr.Y--;
		}
		else if (keyPressed[K_DOWN] && gameoverptr.Y < 9)
		{
			//Beep(1440, 30);
			gameoverptr.Y++;
		}
        else if ( keyPressed[K_ENTER] && gameoverptr.Y == 8)
        {
			characterSpawn(RestartX, RestartY);
            state = Start;
        }
        else if ( keyPressed[K_ENTER] && gameoverptr.Y == 9 )
        {
            characterSpawn(RestartX, RestartY);
            state = menu;
        }
    }

    else if (state == End)
    {
        if ( keyPressed[K_SPACE] )
        {
            state = menu;
           TheEndDoesNotContinue = true;
        }
		
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
	keyPressed[K_R] = isKeyPressed(0x52);
	keyPressed[K_L] = isKeyPressed(0x4C);
	keyPressed[K_U] = isKeyPressed(0x55);
	keyPressed[K_E] = isKeyPressed(0x45);
	keyPressed[K_M] = isKeyPressed(0x4D);
	keyPressed[K_0] = isKeyPressed(0x30);
	keyPressed[K_1] = isKeyPressed(0x31);
	keyPressed[K_BOX] = isKeyPressed(0x42);
	keyPressed[K_BACK] = isKeyPressed(VK_BACK);
	keyPressed[K_ESCAPE] = isKeyPressed(VK_ESCAPE);
	keyPressed[K_ENTER] = isKeyPressed(VK_RETURN);
	keyPressed[K_SPACE] = isKeyPressed(VK_SPACE);
}

void characterSpawn(int x, int y)
{
	charLocation.X = x;
	charLocation.Y = y;
    RestartX = x;
    RestartY = y;
}

void characterEnd(int y, int x)//temp y , temp x
{
	if (charLocation.X == x&& charLocation.Y == y)
	{
		levelno++;
		loadlevel();
	}
}

void characterInteraction()
{
	for (int i = 0; i < cno; ++i)
	{
		if (charLocation.X == Right.directions[i].X && charLocation.Y == Right.directions[i].Y)
		{
			state = GameOver;
		}
	}
	for (int i = 0; i < cno; ++i)
	{
		if (charLocation.X == Left.directions[i].X && charLocation.Y == Left.directions[i].Y)
		{
			state = GameOver;
		}
	}
	for (int i = 0; i < cno; ++i)
	{
		if (charLocation.X == Up.directions[i].X && charLocation.Y == Up.directions[i].Y)
		{
			state = GameOver;
		}
	}
	for (int i = 0; i < cno; ++i)
	{
		if (charLocation.X == Down.directions[i].X && charLocation.Y == Down.directions[i].Y)
		{
			state = GameOver;
		}
	}
	for (int i = 0; i < mno; ++i)
	{
		if (charLocation.X == aiCoordinate[i].X && charLocation.Y == aiCoordinate[i].Y)
		{
			state = GameOver;
		}
	}
}

void speedDown(double x)
{
	if(velocityChar > x)
		return;
	velocityChar = x + 0.102;
	moveCharacter();
}