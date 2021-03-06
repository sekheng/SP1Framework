#include "playerchar.h"
#include "Loadlevel.h"
#include "BGMsounds.h"

extern Console console;
extern startscreen state;
// CHARACTER INTERACTION EXTERNS REQUIRED//

extern COORD charLocation;
int RestartX;
int RestartY;
int gatelimit = 0;
int keylimit = 0;
extern int levelno;
extern int endcounter;
extern COORD aiCoordinate[20];
extern COORD monCoordinate[20];
extern int cnoR;
extern int cnoL;
extern int cnoU;
extern int cnoD;
extern int mno;
extern int sno;
extern struct Cannon Right;
extern struct Cannon Left;
extern struct Cannon Up;
extern struct Cannon Down;
//extern startscreen state;

//// CHARACTER INTERACTION EXTERNS REQUIRED END////

////////////////////STATE EXTERNS REQUIRED/////////////////////////

extern COORD startmenuLocation;
// extern COORD charLocation;
extern int tempEndX;
extern int tempEndY;
extern COORD charCustomLocation;
COORD pauseLocation;
COORD gameoverptr;
extern int bno;
extern int hno;
extern size_t g_map[200][200];
extern int counter;
//extern startscreen state;

///////////////////STATE EXTERNS END///////////////////////////////

extern bool keyPressed[K_COUNT];

void characterInit()
{
	charLocation.X = 10;
	charLocation.Y = 10;
}

void characterMovement(double x)
{
	if (state == menu)
	{
		menustate();
	}
	else if (state == Exit)
	{
		g_quitGame = true;
	}

	else if (state == Start || state == LevelCustom)   // The Game Begins!
	{
        PlayState();
	}
    //Level Editing
	else if (state == LevelCustomized)
	{
        LevelEditingState();
    }

    else if ( state == Pause )
    {
        PauseState();
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
        GameOverState();
    }

    else if (state == End)
    {
        if ( keyPressed[K_SPACE] )
        {
			state = menu;
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
	keyPressed[K_N] = isKeyPressed(0x4E);
	keyPressed[K_K] = isKeyPressed(0x4B);
	keyPressed[K_G] = isKeyPressed(0x47);
	keyPressed[K_P] = isKeyPressed(0x50);
	keyPressed[K_H] = isKeyPressed(0x48);
	keyPressed[K_BOX] = isKeyPressed(0x42);
	keyPressed[K_BACK] = isKeyPressed(VK_BACK);
	keyPressed[K_ESCAPE] = isKeyPressed(VK_ESCAPE);
	keyPressed[K_ENTER] = isKeyPressed(VK_RETURN);
	keyPressed[K_SPACE] = isKeyPressed(VK_SPACE);
}

/////////////CHARACTER INTERACTIONS CPP///////////////////

void characterSpawn(int x, int y)
{
	charLocation.X = x;
	charLocation.Y = y;
    RestartX = x;
    RestartY = y;
}

void characterEnd(int y, int x)//temp y , temp x
{
	string level;
	if (charLocation.X == x && charLocation.Y == y)
	{
        setAllSoundToPause();
        if ( levelno == 5)
        {
            state = End;
        }
        else {
		    levelno++;
		    levelcheck(levelno,level);
		    loadlevel(level);
            initLevelText();
        }
	}
}

void characterCustomEnd(int tempEndY, int tempEndX)
{
	if (charLocation.X == tempEndX && charLocation.Y == tempEndY)
	{
        setAllSoundToPause();
		endcounter++;
		state = End;
	}
}

void characterInteraction()
{
	//For normal levels
	for (int i = 0; i < cnoR; ++i)
	{
		if (charLocation.X == Right.directions[i].X && charLocation.Y == Right.directions[i].Y)
		{
            ShotByCannon();
			state = GameOver;
		}
	}
	for (int i = 0; i < cnoL; ++i)
	{
		if (charLocation.X == Left.directions[i].X && charLocation.Y == Left.directions[i].Y)
		{
            ShotByCannon();
			state = GameOver;
		}
	}
	for (int i = 0; i < cnoU; ++i)
	{
		if (charLocation.X == Up.directions[i].X && charLocation.Y == Up.directions[i].Y)
		{
            ShotByCannon();
			state = GameOver;
		}
	}
	for (int i = 0; i < cnoD; ++i)
	{
		if (charLocation.X == Down.directions[i].X && charLocation.Y == Down.directions[i].Y)
		{
            ShotByCannon();
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
	for (int i = 0; i < sno; ++i)
	{
		if (charLocation.X == monCoordinate[i].X && charLocation.Y == monCoordinate[i].Y)
		{
			state = GameOver;
		}
	}
}
 
////////////////CHARACTER INTERACTION CPP END///////////

////////////////////STATE CPP/////////////////////////

void menustate()
{
    setAllSoundToPause();
	if (keyPressed[K_UP] && startmenuLocation.Y > 21)
	{
		startmenuLocation.Y--;
	}
	else if (keyPressed[K_DOWN] && startmenuLocation.Y < 25)
	{
		startmenuLocation.Y++;
	}
	else if (keyPressed[K_ENTER] && startmenuLocation.Y == 21)
	{
		state = Start;
	}
	else if (keyPressed[K_ENTER] && startmenuLocation.Y == 22)
	{
		state = LevelCustomized;
	}
	else if (keyPressed[K_ENTER] && startmenuLocation.Y == 23)
	{
		state = LevelCustom;
	}
	else if (keyPressed[K_ENTER] && startmenuLocation.Y == 24)
	{
		state = Help;
	}
	else if (keyPressed[K_ENTER] && startmenuLocation.Y == 25)
	{
		state = Exit;
	}

	if (startmenuLocation.Y == 21)
	{
		startmenuLocation.X = 9;
	}
	else if (startmenuLocation.Y == 22)
	{
		startmenuLocation.X = 23;
	}
	else if (startmenuLocation.Y == 23)
	{
		startmenuLocation.X = 21;
	}
	else if (startmenuLocation.Y == 24)
	{
		startmenuLocation.X = 8;
	}
	else
	{
		startmenuLocation.X = 8;
	}
}

void PlayState()
{
		if (keyPressed[K_UP] & keyPressed[K_W] && charLocation.Y > 0 && g_map[charLocation.Y + 2][charLocation.X] != 1)
		{
			charLocation.Y++;
		}
		else if (keyPressed[K_LEFT] & keyPressed[K_A] && charLocation.X && g_map[charLocation.Y][charLocation.X + 1] != 1)
		{
			charLocation.X++;
		}
		else if (keyPressed[K_DOWN] & keyPressed[K_S] && charLocation.Y - 1 && g_map[charLocation.Y][charLocation.X] != 1)
		{
			charLocation.Y--;
		}
		else if (keyPressed[K_RIGHT] & keyPressed[K_D] && charLocation.X - 1 && g_map[charLocation.Y][charLocation.X - 1] != 1)
		{
			charLocation.X--;
		}

		if (keyPressed[K_UP] && charLocation.Y > 0 && g_map[charLocation.Y - 1][charLocation.X] != 1) //up
		{
			charLocation.Y--;
		}
		else if (keyPressed[K_LEFT] && charLocation.X > 0 && g_map[charLocation.Y][charLocation.X - 1] != 1) //left
		{
			charLocation.X--;
		}
		else if (keyPressed[K_DOWN] && charLocation.Y < console.getConsoleSize().Y - 1 && g_map[charLocation.Y + 1][charLocation.X] != 1) //down
		{
			charLocation.Y++;
		}
		else if (keyPressed[K_RIGHT] && g_map[charLocation.Y][charLocation.X + 1] != 1) //right
		{
			charLocation.X++;
		}

		if (keyPressed[K_W] && charLocation.Y > 0 && g_map[charLocation.Y - 1][charLocation.X] != 1)  //up
		{
			charLocation.Y--;
		}
		else if (keyPressed[K_A] && charLocation.X > 0 && g_map[charLocation.Y][charLocation.X - 1] != 1)  //left
		{
			charLocation.X--;
		}
		else if (keyPressed[K_S] && charLocation.Y < console.getConsoleSize().Y - 1 && g_map[charLocation.Y + 1][charLocation.X] != 1)  //down
		{
			charLocation.Y++;
		}
		else if (keyPressed[K_D] && g_map[charLocation.Y][charLocation.X + 1] != 1)   //right
		{
			charLocation.X++;
		}
		characterInteraction();
		// To Pause in-game
		if (keyPressed[K_SPACE])
		{
			state = Pause;
		}
		if (state == Start)
		{
			characterEnd(tempEndY, tempEndX);
		}
		else if (state == LevelCustom)
		{
			characterCustomEnd(tempEndY, tempEndX);
		}
}

void PauseState()
{
		if (keyPressed[K_UP] && pauseLocation.Y > 15)
		{
			//Beep(1440, 30);
			pauseLocation.Y--;
		}
		else if (keyPressed[K_DOWN] && pauseLocation.Y < 17)
		{
			pauseLocation.Y++;
		}
        else if ( keyPressed[K_ENTER] && pauseLocation.Y == 15)
        {
			if (counter == 1)
			{
				state = LevelCustom;
			}
			else
			{
				state = Start;
			}
        }
        else if ( keyPressed[K_ENTER] && pauseLocation.Y == 16 )
        {
            setAllSoundToPause();
            restart_level_forKeysAndGates();
            restartBlockPosition(bno);
			restartCrazyMonLocation(mno);
			restartFollowMonLocation(sno);
            characterSpawn(RestartX,RestartY);
			if (counter == 1)
			{
				state = LevelCustom;
			}
			else
			{
				state = Start;
			}
        }
        else if ( keyPressed[K_ENTER] && pauseLocation.Y == 17 )
        {
            restart_level_forKeysAndGates();
            restartBlockPosition(bno);
			restartCrazyMonLocation(mno);
			restartFollowMonLocation(sno);
            characterSpawn(RestartX,RestartY);
            state = menu;
        }
}

void GameOverState()
{
    pauseTheChasingSound();
		if (keyPressed[K_UP] && gameoverptr.Y > 8)
		{
			gameoverptr.Y--;
		}
		else if (keyPressed[K_DOWN] && gameoverptr.Y < 9)
		{
			gameoverptr.Y++;
		}
        else if ( keyPressed[K_ENTER] && gameoverptr.Y == 8)
        {
            setAllSoundToPause();
            restartBlockPosition(bno);
            restart_level_forKeysAndGates();
			restartCrazyMonLocation(mno);
			restartFollowMonLocation(sno);
			characterSpawn(RestartX, RestartY);
			if (counter == 1)
			{
				state = LevelCustom;
			}
			else
			{
				state = Start;
			}
        }
        else if ( keyPressed[K_ENTER] && gameoverptr.Y == 9 )
        {
            setAllSoundToPause();
            restartBlockPosition(bno);
            restart_level_forKeysAndGates();
			restartCrazyMonLocation(mno);
			restartFollowMonLocation(sno);
            characterSpawn(RestartX, RestartY);
            state = menu;
        }
}

void LevelEditingState()
{
		char edit;
		if (keyPressed[K_SPACE])
		{
			state = menu;
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
			edit = '\0';
			writelevel(edit);
		}
		if (keyPressed[K_L])
		{
			edit = 'L';
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
		if (keyPressed[K_N])
		{
			edit = 'N';
			writelevel(edit);
		}
		if (keyPressed[K_BOX])
		{
			edit = '#';
			writelevel(edit);
		}
		if (keyPressed[K_P])
		{
			edit = 'P';
			writelevel(edit);
		}
		if (keyPressed[K_H])
		{
			edit = 'H';
			writelevel(edit);
		}
		if (keyPressed[K_K])
		{
			if (keylimit < 10)
			{
				edit = 'K';
				writelevel(edit);
				keylimit++;
			}
		}
		if (keyPressed[K_G])
		{
			if (gatelimit < 10)
			{
				edit = 'G';
				writelevel(edit);
				gatelimit++;
			}
		}
		if (keyPressed[K_ENTER])
		{
			savecustomlevel();
			state = menu;
		}
		if (keyPressed[K_UP] && charCustomLocation.Y > 1)
		{
			charCustomLocation.Y--;
		}
		if (keyPressed[K_LEFT] && charCustomLocation.X >40 )
		{
			charCustomLocation.X--;
		}
		if (keyPressed[K_DOWN] && charCustomLocation.Y < 16 )
		{
			charCustomLocation.Y++;
		}
		if (keyPressed[K_RIGHT] && charCustomLocation.X < 95)
		{
			charCustomLocation.X++;
		}
}

/////////STATE CPP END///////////////////////////////
