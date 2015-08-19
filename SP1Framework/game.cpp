// This is the main file for the game logic and function
#include "game.h"
#include "traps.h"
#include "Framework\console.h"
#include "levels.h"
#include "Converter.h"
#include "title.h"
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
size_t g_map[140][100];    //For Collision System
int titlearr[40][150];

// For Menu Display
char *strt = "(1) START";
COORD st;
char *lvlcustomized = "(2) LEVEL CUSTOMIZATION";
COORD lvled;
char *playcustom = "(3) PLAY CUSTOM LEVEL";
COORD custom;
char *hlp = "(4) HELP";
COORD hp;
char *option = "(5) OPTIONS";
COORD opt;
char *ext = "(6) EXIT";
COORD et;

// Game specific variables here
COORD charLocation;
COORD startmenuLocation;
int levelno;
string level;
int change;
int row = 1;    // For collision Detection
int col = 0;    // For collision Detection
COORD LvL;
COORD Ttle;
int ttlerow = 0;
int ttlecol = 0;
string content;
int color;
int tempX; //store X coord
int tempY; //store Y coord
int cno = 0; //cannon number

// Initialize variables, allocate memory, load data from file, etc. 
// This is called once before entering into your main loop
void init()
{
    // Set precision for floating point output
    elapsedTime = 0.0;

    //charLocation.X = console.getConsoleSize().X / 2;
    //charLocation.Y = console.getConsoleSize().Y / 2;
    charLocation.X = 10;
    charLocation.Y = 10;

    // Starting menu location
    startmenuLocation.X = 23;
    startmenuLocation.Y = 21;
	/////////////////////////////////////////

	int levelno = 1;
	levelcheck(levelno,level);
	ifstream inData;
	inData.open(level);
	string Data;

	while (!inData.eof())
	{
		col = 0;
		getline(inData, Data);
		for (unsigned int x = 0; x < Data.length(); x++)
		{
			tempX = col;
			tempY = row;
			change = Data[x];
			if (change == 67)
			{
				convert(tempY, tempX,cno);
				cno++;
			}
			else
			{
				convert(change);

			}
			g_map[row][col] = change;
			++col;
		}
		++row;
	}
	inData.close();
	

    // Title
    
    ifstream inTitle;
    inTitle.open("displayTitle.txt");
    string Title;
    while ( getline (inTitle, Title) && !inTitle.eof() )
    {
        ttlecol = 0;
        for ( size_t y = 0; y < Title.size(); ++y) {
            int change = Title[y];
            titleconvert(change);
            titlearr[ttlerow][ttlecol] = change;
            ++ttlecol;
        }
        ++ttlerow;
    }
    //cout << ttlerow << " " << ttlecol;
    inTitle.close();

    Ttle.X = 0;
    Ttle.Y = 1;
    
    // Menu's coordinates.
    st.X = 0;
    st.Y = 21;
    lvled.X = 0;
    lvled.Y = 22;
    custom.X = 0;
    custom.Y = 23;
    hp.X = 0;
    hp.Y = 24;
    opt.X = 0;
    opt.Y = 25;
    et.X = 0;
    et.Y = 26;

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
    moveCharacter();    // moves the character, collision detection, physics, etc
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

void moveCharacter()
{
    if ( state == menu ) 
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
        if ( keyPressed[K_ENTER] && startmenuLocation.Y == 22)
        {
            state = LevelCustomized;
        }
        if ( keyPressed[K_ENTER] && startmenuLocation.Y == 23) 
        {
            state = LevelCustom;
        }
        if (keyPressed[K_ENTER] && startmenuLocation.Y == 26) 
		{
            state = Exit;
        }
    }

    if ( state == Exit ) 
	{
        g_quitGame = true;
    }

    if ( state == Start )   // The Game Begins!
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
		if (keyPressed[K_DOWN] & keyPressed[K_S] && charLocation.Y - 1 && g_map[charLocation.Y ][charLocation.X] != 1)
		{
			Beep(1440, 30);
			charLocation.Y--;
		}
		if (keyPressed[K_RIGHT] & keyPressed[K_D] && charLocation.X - 1 && g_map[charLocation.Y][charLocation.X - 1] != 1)
		{
			Beep(1440, 30);
			charLocation.X--;
		}

		if (keyPressed[K_UP] && charLocation.Y > 0 && g_map[charLocation.Y-1][charLocation.X] != 1)
		{
			Beep(1440, 30);
			charLocation.Y--;
		}
		if (keyPressed[K_LEFT] && charLocation.X > 0 && g_map[charLocation.Y][charLocation.X - 1 ] != 1)
		{
		    Beep(1440, 30);
			charLocation.X--;
		}
		if (keyPressed[K_DOWN] && charLocation.Y < console.getConsoleSize().Y - 1 && g_map[charLocation.Y + 1][charLocation.X] != 1)
		{
			Beep(1440, 30);
			charLocation.Y++;
		}
		if (keyPressed[K_RIGHT] /*&& charLocation.X < console.getConsoleSize().X - 1*/ && g_map[charLocation.Y][charLocation.X + 1] != 1 )
		{
			Beep(1440, 30);
			charLocation.X++;
		}

		if (keyPressed[K_W] && charLocation.Y > 0 && g_map[charLocation.Y-1][charLocation.X] != 1)  //up
		{
			Beep(1440, 30);
			charLocation.Y--;
		}
		if (keyPressed[K_A] && charLocation.X > 0 && g_map[charLocation.Y][charLocation.X - 1] != 1)  //left
		{
			Beep(1440, 30);
			charLocation.X--;
		}
		if (keyPressed[K_S] && charLocation.Y < console.getConsoleSize().Y - 1 && g_map[charLocation.Y + 1][charLocation.X] != 1 )  //down
		{
			Beep(1440, 30);
			charLocation.Y++;
		}
		if (keyPressed[K_D] /*&& charLocation.X < console.getConsoleSize().X - 1*/ && g_map[charLocation.Y][charLocation.X + 1] != 1)   //right
		{
			Beep(1440, 30);
			charLocation.X++;
		}
		
<<<<<<< HEAD
		cannonballR(3);
    }
    if ( state == LevelCustomized)
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

    if ( state == LevelCustom)
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
		if (keyPressed[K_DOWN] & keyPressed[K_S] && charLocation.Y - 1 && g_map[charLocation.Y ][charLocation.X] != 1)
		{
			Beep(1440, 30);
			charLocation.Y--;
		}
		if (keyPressed[K_RIGHT] & keyPressed[K_D] && charLocation.X - 1 && g_map[charLocation.Y][charLocation.X - 1] != 1)
		{
			Beep(1440, 30);
			charLocation.X--;
		}

		if (keyPressed[K_UP] && charLocation.Y > 0 && g_map[charLocation.Y-1][charLocation.X] != 1)
		{
			Beep(1440, 30);
			charLocation.Y--;
		}
		if (keyPressed[K_LEFT] && charLocation.X > 0 && g_map[charLocation.Y][charLocation.X - 1 ] != 1)
		{
		    Beep(1440, 30);
			charLocation.X--;
		}
		if (keyPressed[K_DOWN] && charLocation.Y < console.getConsoleSize().Y - 1 && g_map[charLocation.Y + 1][charLocation.X] != 1)
		{
			Beep(1440, 30);
			charLocation.Y++;
		}
		if (keyPressed[K_RIGHT] /*&& charLocation.X < console.getConsoleSize().X - 1*/ && g_map[charLocation.Y][charLocation.X + 1] != 1 )
		{
			Beep(1440, 30);
			charLocation.X++;
		}

		if (keyPressed[K_W] && charLocation.Y > 0 && g_map[charLocation.Y-1][charLocation.X] != 1)  //up
		{
			Beep(1440, 30);
			charLocation.Y--;
		}
		if (keyPressed[K_A] && charLocation.X > 0 && g_map[charLocation.Y][charLocation.X - 1] != 1)  //left
		{
			Beep(1440, 30);
			charLocation.X--;
		}
		if (keyPressed[K_S] && charLocation.Y < console.getConsoleSize().Y - 1 && g_map[charLocation.Y + 1][charLocation.X] != 1 )  //down
		{
			Beep(1440, 30);
			charLocation.Y++;
		}
		if (keyPressed[K_D] /*&& charLocation.X < console.getConsoleSize().X - 1*/ && g_map[charLocation.Y][charLocation.X + 1] != 1)   //right
		{
			Beep(1440, 30);
			charLocation.X++;
		}

    }
=======
			cannonballR(3, cno);//3 is ball movement distance
	}
>>>>>>> 526bc568018842f8c2d608769e937b5093a08cd3
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
    console.clearBuffer(0x1F);
}
void renderMap()
{
    if ( state ==  menu) 
	{
        const WORD colors[] = 
		{
            0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
            0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
        };
        // Display The Title
        /*
    ifstream inTitle;
    inTitle.open("displayTitle.txt");
    string Title;
    while ( getline(inTitle, Title) && !inTitle.eof() )
    {
        //Ttle.X = 0;
        for ( size_t y = 0; y < Title.size(); ++y) {
            console.writeToBuffer(Ttle, Title,colors[0]);
        }
        Ttle.Y += 1;
    }
    //cout << ttlerow << " " << ttlecol;
    inTitle.close();
    */
        Ttle.Y = 1;
        for ( int i = 0; i < ttlerow; ++i) {
            Ttle.X = 0;
            for ( int j = 0; j < ttlecol; ++j) {
                string str;
                int num;
                int change = titlearr[i][j];
                titleconvert2(change, str, num);
                console.writeToBuffer( Ttle, str, colors[0] );
                Ttle.X += 1;
            }
            Ttle.Y += 1;
        }
        
        // Rendering the Menu
        console.writeToBuffer(st, strt, colors[0]);

        console.writeToBuffer(lvled, lvlcustomized, colors[0]);

        console.writeToBuffer(custom, playcustom, colors[0]);

        console.writeToBuffer(hp, hlp, colors[0]);

        console.writeToBuffer(opt, option, colors[0]);

        console.writeToBuffer(et, ext, colors[0]);
    }

	if (state == Start)
	{
		
		const WORD colors[] =
		{
			0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
			0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
		};

		LvL.Y = 1;
		LvL.X = 0;
		// Set up sample colours, and output shadings
		for (int i = 1; i < row; ++i)
		{
			LvL.X = 0;
			for (int j = 0; j < col; ++j) {
				int write = g_map[i][j];
				convert2(write, content, color);
				console.writeToBuffer(LvL, content, colors[color]);
				LvL.X += 1;
			}
			LvL.Y += 1;
		}
	}
}
void renderCharacter()
{
    if ( state == menu) 
	{
        console.writeToBuffer(startmenuLocation, (char)60, 0x0C);
    }
    if ( state == Start) 
	{
		
		// Draw the location of the character
		cannonR(cno);
		console.writeToBuffer(charLocation, (char)1, 0x0C);
    }
    if ( state == LevelCustomized)
    {
       console.writeToBuffer(charLocation, (char)1, 0x0C);
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
