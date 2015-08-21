#include "help.h"

extern Console console;
COORD helpLocation;
char helparr[50][1000];
int helprows = 0;
int helpcols = 0;
extern COORD helpreturn;

void helpPosition()
{
    ifstream inHelp;
    inHelp.open("displayHelp.txt");
    string Helping;
    while ( getline(inHelp, Helping) && !inHelp.eof() )
    {
        helpcols = 0;
        for ( size_t y = 0; y < Helping.size(); ++y) {
            helparr[helprows][helpcols] = Helping[y];
            ++helpcols;
        }
        ++helprows;
    }
    inHelp.close();
    helpLocation.X = 20;
    helpLocation.Y = 1;
    helpreturn.X = 0;
    helpreturn.Y = 0;
}

void displayHelp()
{
    helpLocation.Y = 1;
    for ( int i = 0; i < helprows; ++i) {
        helpLocation.X = 20;
        for ( int j = 0; j < helpcols; ++j) {
            if ( i == 10 && j == 0)
            {
                console.writeToBuffer( helpLocation, ' ' , 0x6A );
                helpLocation.X += 1;
                continue;
            }
            console.writeToBuffer( helpLocation, helparr[i][j], 0x0F );
            helpLocation.X += 1;
        }
        helpLocation.Y += 1;
    }
}