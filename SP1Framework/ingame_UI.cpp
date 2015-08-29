#include "ingame_UI.h"

extern char pausearr[40][150];
COORD pu;
int pauserows = 0;
int pausecols = 0;
extern Console console;
extern COORD pauseLocation;

char *restart = "RESTART";
char *quit = "QUIT GAME?";
char *conti = "CONTINUE";
COORD cont;
COORD rstrt;
COORD qit;

void pausePosition()
{
    ifstream inPause;
    inPause.open("displayPause.txt");
    string Pause;
    while ( getline(inPause, Pause) && !inPause.eof() )
    {
        pausecols = 0;
        for ( size_t y = 0; y < Pause.size(); ++y) {
            pausearr[pauserows][pausecols] = Pause[y];
            ++pausecols;
        }
        ++pauserows;
    }
    inPause.close();
    pu.X = 40;
    pu.Y = 1;
    cont.X = 55;
    cont.Y = 15;
    rstrt.X = 56;
    rstrt.Y = 16;
    qit.X = 55;
    qit.Y = 17;
    pauseLocation.X = 65;
    pauseLocation.Y = 15;
}

void displayPause()
{
    pu.Y = 1;
    for ( int i = 0; i < pauserows; ++i) {
        pu.X = 40;
        for ( int j = 0; j < pausecols; ++j) {
            if ( pausearr[i][j] != '.')
            {
                console.writeToBuffer( pu, (char)219 , 0x0F );
            }
            if ( pausearr[i][j] == '.')
            {
                 console.writeToBuffer( pu, ' ', 0x0F );
            }
            pu.X += 1;
        }
        pu.Y += 1;
    }
    console.writeToBuffer( cont, conti, 0x0F );
    console.writeToBuffer( rstrt, restart, 0x0F );
    console.writeToBuffer( qit, quit, 0x0F );
}
