// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "levels.h"
#include "monster.h"
#include "traps.h"
#include "collision.h"

using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::ofstream;

double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNT];
COORD charLocation;
COORD startmenuLocation;
COORD consoleSize;
startscreen s = MAX_STATE;
char Title[200][200];
int row = 0;
int col = 0;

void init()
{
    // Set precision for floating point output
    std::cout << std::fixed << std::setprecision(3);

    SetConsoleTitle(L"SP1 Framework");

    // Sets the console size, this is the biggest so far.
    setConsoleSize(79, 28);

    // Get console width and height
    CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */     

    /* get the number of character cells in the current buffer */ 
    GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );
    consoleSize.X = csbi.srWindow.Right + 1;
    consoleSize.Y = csbi.srWindow.Bottom + 1;

    // set the character to be in the center of the screen.
    charLocation.X = consoleSize.X / 2;
    charLocation.Y = consoleSize.Y / 2;

    //Set the arrow to be near the start
    startmenuLocation.X = 10;
    startmenuLocation.Y = 20;

    // Display The Title
    ifstream inData;
    inData.open("displayTitle.txt");
    char c;

    while ( !inData.eof() && inData.get(c) ) {
        Title[row][col] = c;
        ++col;
    }
    inData.close();

    elapsedTime = 0.0;
}

void shutdown()
{
    // Reset to white text on black background
	colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
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

void update(double dt)
{
    if ( s == MAX_STATE ) 
	{
        if (keyPressed[K_UP] && startmenuLocation.Y > 20)
        {
            Beep(1440, 30);
            startmenuLocation.Y--; 
        }
        if (keyPressed[K_DOWN] && startmenuLocation.Y < 22)
        {
            Beep(1440, 30);
            startmenuLocation.Y++; 
        }
        if (keyPressed[K_ENTER] && startmenuLocation.Y == 20) 
		{
            s = Start;

        }
        if (keyPressed[K_ENTER] && startmenuLocation.Y == 22) 
		{
            s = Exit;
        }

        if (keyPressed[K_ESCAPE]) 
		{
            g_quitGame = true;   
        }
    }

    if ( s == Exit) 
	{
        g_quitGame = true;
    }
	
	if (s == Start)
	{
		// get the delta time
		elapsedTime += dt;
		deltaTime = dt;
	}
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
    if (keyPressed[K_DOWN] && charLocation.Y < consoleSize.Y - 1)
    {
        Beep(1440, 30);
        charLocation.Y++; 
    }
    if (keyPressed[K_RIGHT] && charLocation.X < consoleSize.X - 1)
    {
        Beep(1440, 30);
        charLocation.X++; 
    }

	if (keyPressed[K_W] && charLocation.Y > 0)
	{
		Beep(1440, 30);
		charLocation.Y--;
	}
	if (keyPressed[K_A] && charLocation.X > 0)
	{
		Beep(1440, 30);
		charLocation.X--;
	}
	if (keyPressed[K_S] && charLocation.Y < consoleSize.Y - 1)
	{
		Beep(1440, 30);
		charLocation.Y++;
	}
	if (keyPressed[K_D] && charLocation.X < consoleSize.X - 1)
	{
		Beep(1440, 30);
		charLocation.X++;
	}
    // quits the game if player hits the escape key
    if (keyPressed[K_ESCAPE])
	{
        g_quitGame = true;   
    }
}

void render()
{
	int levelno = 1;
    if ( s == MAX_STATE) {
        colour(0x0F);
        cls();
        //render the game
        //render test screen code (not efficient at all)
        const WORD colors[] =   
		{
			0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
			0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	    };
        // To Display title
        for ( int i = 0; i < col; ++i) 
		{
            cout << Title[0][i];
        }
        /*ifstream inData;
        inData.open("displayTitle.txt");
        string Data;
        while ( !inData.eof() ) {
            getline ( inData, Data);
            cout << Data << endl;
        }*/

        // Rendering the Menu
        char *strt = "(1) START";
        gotoXY(0,20);
        //colour(colors[0x1A]);
        cout << strt << endl;
        char *hlp = "(2) HELP";
        gotoXY(0,21);
        //colour(colors[0x2B]);
        cout << hlp << endl;
        char *ext = "(3) EXIT";
        gotoXY(0,22);
        //colour(colors[0x3C]);
        cout << ext << endl;

        //Rendering the character
        gotoXY(startmenuLocation);
        //colour(0x1A);
        cout << (char)60;
    }
    if ( s == Start) 
	{
    // clear previous screen
    colour(0x0F);
    cls();
	cout << endl;
    //render the game

	level(levelno);
    // render time taken to calculate this frame
    gotoXY(70, 0);
    colour(0x1A);
    cout << 1.0 / deltaTime << "fps" << endl;
  
    //gotoXY(0, 0);
    //colour(0x59);
    //std::cout << elapsedTime << "secs" << std::endl;

    // render character
    gotoXY(charLocation);
    colour(0x0C);
    cout << (char)1;
    }
	
}
