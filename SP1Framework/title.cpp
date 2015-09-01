#include "title.h"

int titlearr[40][150];
COORD Ttle;
int ttlerow = 0;
int ttlecol = 0;
char *strt = "(1) START";
char *lvlcustomized = "(2) LEVEL CUSTOMIZATION";
char *playcustom = "(3) PLAY CUSTOM LEVEL";
char *hlp = "(4) HELP";
char *ext = "(5) EXIT";
// For Menu Display's coordinates
COORD st;
COORD lvled;
COORD custom;
COORD hp;
COORD et;
extern Console console;
COORD startmenuLocation;

void titleconvert(int &g) 
{
    if ( g == ' ' ) 
    {
        g = 0;
    }
    if  ( g == 'O' )
    {
        g = 1;
    }
    if ( g == 'o' ) 
    {
        g = 2;
    }
    if ( g == '.' ) 
    {
        g = 3;
    }
    if ( g == '`' )
    {
        g = 4;
    }
    if ( g == 39 ) 
    {
        g = 5;
    }
}

void titleconvert2(int &a, string &x, int &c)
{
    if (a == 0) {
		x = " ";
		c = 0;
	}
	if (a == 1){
		x = "O";
		c = 0;
	}
	if (a == 2) {
		x = "o";
		c = 0;
	}
	if (a == 3) {
		x = ".";
		c = 0;
	}
	if (a == 4) {
		x = "`";
		c = 0;
	}
    if ( a == 5 ) 
    {
        x = "'";
        c = 0;
    }
}

void menuPosition()
{
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
    et.X = 0;
    et.Y = 25;
    startmenuLocation.X = 23;
    startmenuLocation.Y = 21;
}

void displayMenu() {
    Ttle.Y = 1;
    for ( int i = 0; i < ttlerow; ++i) {
        Ttle.X = 0;
        for ( int j = 0; j < ttlecol; ++j) {
            string str;
            int num;
            int change = titlearr[i][j];
            titleconvert2(change, str, num);
            console.writeToBuffer( Ttle, str, 0x0F );
            Ttle.X += 1;
        }
        Ttle.Y += 1;
    }
        
        // Rendering the Menu
    console.writeToBuffer(st, strt, 0x0F);
    console.writeToBuffer(lvled, lvlcustomized, 0x0F);
    console.writeToBuffer(custom, playcustom, 0x0F);
    console.writeToBuffer(hp, hlp, 0x0F);
    console.writeToBuffer(et, ext, 0x0F);
}