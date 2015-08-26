// This is the main file for the game logic and function
#include "game.h"
#include "traps.h"
#include "Framework\console.h"
#include "levels.h"
#include "Converter.h"
#include "title.h"
#include "Loadlevel.h"
#include "playerchar.h"
#include "ingame_UI.h"
#include "help.h"
#include "Gameover.h"
#include "The_End.h"
#include "item.h"
#include "windows.h"    // For Music Feature
#include "mmsystem.h"   // For Music Feature
#include "speedControl.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::string;

// Console object
Console console(140, 30, "SP1 Framework");

int i = 0;
double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNT];
startscreen state = menu;
int titlearr[40][150];
size_t g_map[140][100];    //For Collision System
size_t g_custommap[140][100]; //for custom lvl legend
size_t g_customizemap[140][100]; //for customising lvl
char pausearr[40][150];

// For Menu Display's coordinates
COORD st;
COORD lvled;
COORD custom;
COORD hp;
COORD opt;
COORD et;

// Game specific variables here
COORD charLocation;
COORD charCustomLocation;
COORD startmenuLocation;
int levelno = 5;
string level;
int counter = 0;//counter for custom map
int endcounter = 0;
int change;
int cuschange;
int row = 1;    // For collision Detection and map coordinates
int col = 0;    // For collision Detection and map coordinates
int cusrow = 1;
int cuscol = 0;
COORD LvL;
COORD CusLvL;
COORD Ttle;
int ttlerow = 0;
int ttlecol = 0;
string content;
int color;
int tempEndX; // x end point coord
int tempEndY;// y end point coord
int cno = 0; //cannon number
int mno = 0; //monster number
int bno = 0; //box number
COORD pu;
int pauserows = 0;
int pausecols = 0;

extern COORD pauseLocation;
extern COORD helpreturn;
extern COORD gameoverptr;


const WORD colors[] =
{
	0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
	0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
};

// Initialize variables, allocate memory, load data from file, etc. 
// This is called once before entering into your main loop

void init()
{
    // Set precision for floating point output
	elapsedTime = 0.0; 
	charCustomLocation.X = 0;
	charCustomLocation.Y = 1;

	characterInit();

	levelcheck(levelno, level);
	loadlevel(level); // loads the main level

	loadcustomlevel(); // load custom lvl txt

    // Title
    menuPosition();

    //Pause
    pausePosition();

    // Help
    helpPosition();

    // Game Over
    gameoverPosition();

    // The End
    theendPosition();

    // Displey Level UI
    initLevelText();

    // Display Inventory UI
    initinventorysystem();
}

// Do your clean up of memory here
// This is called once just before the game exits

void shutdown()
{
    // Reset to white text on black background
	colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

    console.clearBuffer();
}

/*
	This function checks if any key had been pressed since the last time we checked
	If a key is pressed, the value for that particular key will be true
	
	Add more keys to the enum in game.h if you need to detect more keys
	To get other VK key defines, right click on the VK define (e.g. VK_UP) and choose "Go To Definition" 
	For Alphanumeric keys, the values are their ascii values (uppercase).
*/

/*
	This is the update function
	double dt - This is the amount of time in seconds since the previous call was made

	Game logic should be done here.
	Such as collision checks, determining the position of your game characters, status updates, etc
	If there are any calls to write to the console here, then you are doing it wrong.

    If your game has multiple states, you should determine the current state, and call the relevant function here.
*/

void update(double dt)
{
    // get the delta time
    elapsedTime += dt;
    deltaTime = dt;

    processUserInput(); // checks if you should change states or do something else with the game, e.g. pause, exit
    update_charSpeed(elapsedTime);
	update_ballSpeed(10, cno, elapsedTime);
	update_crazyMonSpeed(mno, elapsedTime);// moves the character, collision detection, physics, etc
	updateBlock(bno);
    update_keys();
    update_gates();
    // sound can be played here too.
}

/*
    This is the render loop
    At this point, you should know exactly what to draw onto the screen.
    Just draw it!
    To get an idea of the values for colours, look at console.h and the URL listed there
*/

void render()
{
    clearScreen();      // clears the current screen and draw from scratch 
    renderMap();        // renders the map to the buffer first
    renderCharacter();  // renders the character into the buffer
    renderFramerate();  // renders debug information, frame rate, elapsed time, etc
    renderToScreen();   // dump the contents of the buffer to the screen, one frame worth of game
}

void moveCharacter(double x)
{
	characterMovement(x);
}

void processUserInput()
{
    // quits the game if player hits the escape key
    if (keyPressed[K_ESCAPE])
    {
        g_quitGame = true;
    }
}

void clearScreen()
{
    // Clears the buffer with this colour attribute
    console.clearBuffer(0x0F);
}

void renderMap()
{
    if ( state ==  menu) 
	{
        // Display The Title
        displayMenu();   
    }
    else if ( state == Pause)
    {
        // Display in-game Pause
        displayPause();
    }
    else if ( state == Help)
    {
        displayHelp();
    }
    else if ( state == GameOver)
    {
        displayGameOver();
    }
	else if (state == Start)
	{
		if(counter == 1)
		{
			levelno = 1;
			level = "levels1.txt";
			loadlevel(level);
			counter--;
		}
		reloadlevel(); // reloads level
        displayleveltext();
        displayinventory();
	}
	else if (state == LevelCustomized)
	{
		counter = 0;
		reloadcustomlevel();
		renderwrittenlevel();
	}
	else if (state == LevelCustom)
	{
		if (endcounter == 1)
		{
			counter = 0;
			endcounter--;
		}
		for (; counter < 1; counter++)
		{
			loadcustomizedlevel();
		}
		reloadcustomizedlevel();
	}
    else if (state == End)
    {
		displayTheEnd();
		if (counter == 0)
		{
			counter = 1;
		}
	}
}

void renderCharacter()
{
    if ( state == menu) 
	{
        console.writeToBuffer(startmenuLocation, (char)60, 0x0C);
        pauseLocation.Y = 15;   //These are to reset the location of where the arrow is pointing
        gameoverptr.Y = 8;  //These are to reset the location of where the arrow is pointing
    }
    else if (state == Start|| state == LevelCustom) 
	{
		// Draw the location of the character
		render_cannons(cno);
		crazyMon(mno);
		printBlock(bno);
        display_keys();
        display_gate();
		console.writeToBuffer(charLocation, (char)2, 0x1E);
        pauseLocation.Y = 15;
    }
    else if ( state == Pause)
    {
        console.writeToBuffer(pauseLocation, (char)60, 0x0C);
    }
    else if ( state == Help )
    {
        console.writeToBuffer(helpreturn, (char)60, 0x0C);
    }
    else if ( state == LevelCustomized)
    {
		console.writeToBuffer(charCustomLocation, (char)2, 0x1E);
    }
    else if ( state == GameOver)
    {
       console.writeToBuffer(gameoverptr, (char)60, 0x0C);
    }
}

void renderFramerate()
{
    COORD c;
    // displays the framerate
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(3);
    ss << 1.0 / deltaTime << "fps";
    c.X = console.getConsoleSize().X - 9;
    c.Y = 0;
    console.writeToBuffer(c, ss.str());

    // displays the elapsed time
    ss.str("");
    ss << elapsedTime << "secs";
    c.X = 0;
    c.Y = 0;
    console.writeToBuffer(c, ss.str(), 0x59);
}

void renderToScreen()
{
    // Writes the buffer to the console, hence you will see what you have written
    console.flushBufferToConsole();
}
