#include "help.h"

extern Console console;
COORD helpLocation;
char helparr[40][150];

void helpPosition()
{
    ifstream inHelp;
    inHelp.open("displayHelp.txt");
    string Helping;
    while ( getline(inHelp, Helping) && !inHelp.eof() )
    {
        for ( size_t y = 0; y < Helping.size(); ++y) {
            Helping[y];
        }
    }
    inHelp.close();
}

void helpConverter(char &c)
{

}

void displayHelp()
{

}