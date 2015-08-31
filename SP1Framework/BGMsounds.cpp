#include "BGMsounds.h"

ISoundEngine* engine;
ISoundSource* PlayThemeSong;
ISoundSource* beingChased;
ISoundSource* gotExploded;
extern startscreen state;
bool playitOnce = true; //This is to ensure that the music will be played once.
                        //Try removing this condition and it will be laggy.
const string SoundName[] =
{
    "../irrKlang-1.5.0/media/Dear,_Human.mp3",
    "../irrKlang-1.5.0/media/BeingChased.mp3",
    "../irrKlang-1.5.0/media/explosion.wav"
};  

void initBGMsounds()
{
    engine = createIrrKlangDevice();
    PlayThemeSong =
        engine->addSoundSourceFromFile( SoundName[0].c_str() );
    beingChased =
        engine->addSoundSourceFromFile( SoundName[1].c_str() );
    gotExploded =
        engine->addSoundSourceFromFile( SoundName[2].c_str() );
}

void playSoundEvent()
{
    if ( state == menu && playitOnce == true)   // When player is at the main menu
    {                                           // Theme song will be played.
        playitOnce = false;
        engine->play2D(PlayThemeSong, false, false);
    }
    //else 
    //{
    //    engine->setAllSoundsPaused(true);
    //}
    if ( state == Start && playitOnce == true) // Another song will be played when the player start game
    {
        playitOnce = false;
        engine->play2D(beingChased, false, false);
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
    if ( (state == Start || state == LevelCustom) && playitOnce == true )
    {
        playitOnce = false;
        engine->play2D(beingChased, true);
    }
    else
    {
         engine->play2D(beingChased, false, true);
    }
}

void ShotByCannon()
{
    engine->play2D( gotExploded);
}