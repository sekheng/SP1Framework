#include "GateandKeyCutscenes.h"

extern Console console;
extern startscreen state;

char *gatescenes[30];
char *openGateScenes[30];
int gaterow = 0;
int opengaterow = 0;

COORD ClosedGateLocation;

double Animate = 0;
double timeforAnimation = 8;
WORD ColorForTheGate;

char *YouShallPass;

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
    YouShallPass = "YOU SHALL PASS";
}

void displayGateCutscenes(WORD ColorForGate)
{    
    ClosedGateLocation.Y = 1;
    for ( int i = 0; i < gaterow; ++i)
    {
        console.writeToBuffer(ClosedGateLocation, gatescenes[i], ColorForGate);
        ClosedGateLocation.Y +=1;
    }
}

void displayOpenCutscenes(WORD ColorForGate)
{
    COORD OpenGateLocation;
    OpenGateLocation.X = 0;
    OpenGateLocation.Y = 1;
    for ( int i = 0; i < opengaterow; ++i)
    {
        console.writeToBuffer( OpenGateLocation,openGateScenes[i], ColorForGate);
        OpenGateLocation.Y += 1;
    }
    OpenGateLocation.Y = 10;
    OpenGateLocation.X = 33;
    console.writeToBuffer( OpenGateLocation, YouShallPass, ColorForGate);
}

void displayAnimationofOpenAndClose()
{
   //WORD getcolorFromGate(WORD GateColor);
   if ( Animate > timeforAnimation) {
       state = Start;
       Animate = 0;
   }
   else if ( (Animate + 5) <= timeforAnimation)
   {
       Animate += 0.75;
       displayGateCutscenes(ColorForTheGate);
   }
   else
   {
       Animate += 0.5;
       displayOpenCutscenes(ColorForTheGate);
   }
   
}

void getcolorFromGate(WORD GateColor)
{
    ColorForTheGate = GateColor;
}