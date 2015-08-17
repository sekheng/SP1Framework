// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include "levels.h"
double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNT];
COORD charLocation;
COORD startmenuLocation;
COORD consoleSize;
startscreen s = MAX_STATE;

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
    startmenuLocation.Y = 0;

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
    keyPressed[K_ESCAPE] = isKeyPressed(VK_ESCAPE);
    keyPressed[K_ENTER] = isKeyPressed(VK_RETURN);
}

void update(double dt)
{
	int x;
    if ( s == MAX_STATE ) {
        if (keyPressed[K_UP] && startmenuLocation.Y > 0)
        {
            Beep(1440, 30);
            startmenuLocation.Y--; 
        }
        if (keyPressed[K_DOWN] && startmenuLocation.Y < 2)
        {
            Beep(1440, 30);
            startmenuLocation.Y++; 
        }
        if (keyPressed[K_ENTER] && startmenuLocation.Y == 0) {
            s = Start;

        }
        if (keyPressed[K_ENTER] && startmenuLocation.Y == 2) {
            s = Exit;
        }

        if (keyPressed[K_ESCAPE]) {
            g_quitGame = true;   
        }
    }

    if ( s == Exit) {
        g_quitGame = true;
    }
	
    if ( s == Start) {
    // get the delta time
    elapsedTime += dt;
    deltaTime = dt;
    // Updating the location of the character based on the key press
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

    // quits the game if player hits the escape key
    if (keyPressed[K_ESCAPE])
        g_quitGame = true;   
    }
}

void render()
{
    if ( s == MAX_STATE) {
        colour(0x0F);
        cls();
        //render the game

        //render test screen code (not efficient at all)
        const WORD colors[] =   {
	                        0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
	                        0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	                        };
        // Rendering the Menu
        char *strt = "(1) START";
        gotoXY(0,0);
        //colour(colors[0x1A]);
        std::cout << strt << std::endl;
        char *hlp = "(2) HELP";
        gotoXY(0,1);
        //colour(colors[0x2B]);
        std::cout << hlp << std::endl;
        char *ext = "(3) EXIT";
        gotoXY(0,2);
        //colour(colors[0x3C]);
        std::cout << ext << std::endl;

        //Rendering the character
        gotoXY(startmenuLocation);
        //colour(0x1A);
        std::cout << (char)60;
    }
    if ( s == Start) {
    // clear previous screen
    colour(0x0F);
    cls();
    //render the game

    //render test screen code (not efficient at all)
    const WORD colors[] =   {
	                        0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
	                        0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	                        };
	
	for (int i = 0; i < 12; ++i)
	{
		gotoXY(3*i,i+1);
		colour(colors[i]);
		std::cout << "WOW";
	}

    // render time taken to calculate this frame
    gotoXY(70, 0);
    colour(0x1A);
    std::cout << 1.0 / deltaTime << "fps" << std::endl;
  
    gotoXY(0, 0);
    colour(0x59);
    std::cout << elapsedTime << "secs" << std::endl;

    // render character
    gotoXY(charLocation);
    colour(0x0C);
    std::cout << (char)1;
    }
}

