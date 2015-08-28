#include "GateandKeyCutscenes.h"

extern Console console;
extern startscreen state;

char *gatescenes[30];
char *openGateScenes[30];
int gaterow = 0;
int opengaterow = 0;

COORD ClosedGateLocation;

double Animate = 15;
double secondAnimation;

void initGateCutscenes()
{
    ifstream cutscenes;
    cutscenes.open("Display_ClosedGate2.txt");
    string scenesStr;
    int cS = 80;
    while ( !cutscenes.eof() && getline(cutscenes, scenesStr) )
    {
        gatescenes[gaterow] = new char[cS];
        for ( size_t i = 0; i < scenesStr.size(); ++i)
        {
            *(gatescenes[gaterow] + i) = scenesStr[i];
        }
        *(gatescenes[gaterow] + scenesStr.size()) = '\0';
        ++gaterow;
    }
    cutscenes.close();

    ifstream openCutscenes;
    openCutscenes.open("Display_OpenGate.txt");
    string openstr;
    while ( !openCutscenes.eof() && getline(openCutscenes, openstr) )
    {
        openGateScenes[opengaterow] = new char[cS];
        for ( size_t i = 0; i < openstr.size(); ++i)
        {
            *( openGateScenes[opengaterow] + i) = openstr[i];
        }
        *( openGateScenes[opengaterow] + openstr.size() ) = '\0';
        ++opengaterow;
    }
    openCutscenes.close();   
    ClosedGateLocation.X = 0;
    ClosedGateLocation.Y = 1;
}

void displayGateCutscenes(double animation)
{    
    //if ( animation > Animate)
    //    return;
    ClosedGateLocation.Y = 1;
    for ( int i = 0; i < gaterow; ++i)
    {
        console.writeToBuffer(ClosedGateLocation, gatescenes[i], 0x0F);
        ClosedGateLocation.Y +=1;
    }
}

void displayOpenCutscenes()
{
    COORD OpenGateLocation;
    OpenGateLocation.X = 0;
    OpenGateLocation.Y = 1;
    for ( int i = 0; i < opengaterow; ++i)
    {
        console.writeToBuffer( OpenGateLocation,openGateScenes[i], 0x0F);
        OpenGateLocation.Y += 1;
    }
}

void displayAnimationofOpenAndClose(double Timer)
{
   if ( timer(Animate) < Timer) {
      state = Start;
   }
   else 
   {
       displayGateCutscenes(Timer);
   }
}