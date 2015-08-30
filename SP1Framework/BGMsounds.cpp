#include "BGMsounds.h"

ISoundEngine* engine;
ISoundSource* PlayThemeSong;
ISoundSource* beingChased;
extern startscreen state;
bool playitOnce = true; //This is to ensure that the music will be played once.
                        //Try removing this condition and it will be laggy.
//ISound *snd;
//ISound *snd2;
const string SoundName[] =
{
    "../irrKlang-1.5.0/media/Dear,_Human.mp3",
    "../irrKlang-1.5.0/media/BeingChased.mp3"
};  

void initBGMsounds()
{
    engine = createIrrKlangDevice();
    PlayThemeSong =
        engine->addSoundSourceFromFile( SoundName[0].c_str() );
    beingChased =
        engine->addSoundSourceFromFile( SoundName[1].c_str() );
    //snd = engine->play2D(PlayThemeSong, false, true);
    //snd2 = engine->play2D(beingChased, false, true);
}

void playSoundEvent()
{
    if ( state == menu && playitOnce == true)   // When player is at the main menu
    {                                           // Theme song will be played.
        /*if ( engine->isCurrentlyPlaying( SoundName[1].c_str() ) )
        {
            engine->play2D(beingChased,false,true);
        }*/
        playitOnce = false;
        /*snd =*/ engine->play2D(PlayThemeSong, false, false);
        //snd2 = engine->play2D(beingChased, false, true);
    }
    else if ( state == Start && playitOnce == true) // Another song will be played when the player start game
    {
        //if ( engine->isCurrentlyPlaying( SoundName[0].c_str() ) )
        //{
        //    engine->play2D( PlayThemeSong,false,true );
        //}
        playitOnce = false;
        /*snd2 = */engine->play2D(beingChased, false, false);
        //snd = engine->play2D(PlayThemeSong, false, true);
    }
}

bool changesGameState(bool check_Game_State)
{
    return playitOnce = true;
}

void changesSoundEvent()    // Whenever the player changes state, this function will be called
{                           // currently only works when state == Start
    changesGameState(playitOnce);
}

void removingEngine()   //This is to remove the unncessary memory after exiting the game
{
    engine->drop();
}

void PlayingThemeSong()
{
    if ( state == menu && playitOnce == true )
    {
        playitOnce = false;
        engine->play2D(PlayThemeSong, true);
    }
    else
    {
        engine->play2D(PlayThemeSong, false, true);
    }
}

void PlayingBeingChased()
{
    if ( (state == Start ||state == LevelCustom) && playitOnce == true )
    {
        playitOnce = false;
        engine->play2D(beingChased, true);
    }
    else
    {
         engine->play2D(beingChased, false, true);
    }
}