#include "BGMsounds.h"

ISoundEngine* engine;
ISoundSource* PlayThemeSong;
ISoundSource* beingChased;
ISoundSource* gotExploded;
extern startscreen state;
bool playitOnce = true; //This is to ensure that the music will be played once.
                        //Try removing this condition and it will be laggy.
ISound *beingChasedSnd;
ISound *gotShot;
ISound *alwaysPlaying;

extern COORD aiCoordinate[MAX_SPACE];
extern COORD monCoordinate[MAX_SPACE];

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
    alwaysPlaying = 
        engine->play2D(PlayThemeSong, true, false, true);
    alwaysPlaying->setVolume(0.7f);
    beingChasedSnd = 
        engine->play2D( beingChased, false, true, true);
    gotShot = 
        engine->play2D( gotExploded, false, true, true);
}

void playSoundEvent()
{
    if ( state != menu )   // When player is at the main menu
    {                                           // Theme song will be played.
        alwaysPlaying->setVolume(0.1f);
    }
    else
    {
        alwaysPlaying->setVolume(0.7f);
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

void PlayingBeingChased()
{
    if ( engine->isCurrentlyPlaying(beingChased) == 0 )
    {
        beingChasedSnd = 
            engine->play2D(beingChased, false, false, true);
        beingChasedSnd->setVolume(1);
    }
}

void ShotByCannon()
{
    gotShot = 
        engine->play2D(gotExploded, false, false, true);
    gotShot->setVolume(1);
}

void setAllSoundToPause()
{
    engine->setAllSoundsPaused();
}

void pauseTheChasingSound()
{
    beingChasedSnd->stop();
    //beingChasedSnd->drop();
    //beingChasedSnd->isSetPaused();
}