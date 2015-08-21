#include "The_End.h"

extern Console console;
COORD theEndLocation;
char TheEndarr[100][1000];
int end_rows = 0;
int end_cols = 0;

void theendPosition() {
    ifstream inTheEnd;
    inTheEnd.open("displayTheEnd.txt");
    string theend;
    while ( getline(inTheEnd, theend) && !inTheEnd.eof() )
    {
        end_cols = 0;
        for ( size_t y = 0; y < theend.size(); ++y) {
            TheEndarr[end_rows][end_cols] = theend[y];
            ++end_cols;
        }
        ++end_rows;
    }
    inTheEnd.close();
    theEndLocation.X = 0;
    theEndLocation.Y = 1;
}

void displayTheEnd() {
    theEndLocation.Y = 1;
    for ( int i = 0; i < end_rows; ++i) {
        theEndLocation.X = 0;
        for ( int j = 0; j < end_cols; ++j) {
            console.writeToBuffer( theEndLocation, TheEndarr[i][j], 0x0F );
            theEndLocation.X += 1;
        }
        theEndLocation.Y += 1;
    }
}