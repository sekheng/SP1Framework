#include "BGMsounds.h"

ISoundEngine* engine;
ISoundSource* PlayThemeSong;
ISoundSource* beingChased;
ISoundSource* gotExploded;
ISoundSource* gateOpening;
ISoundSource* hatchOpening;
extern startscreen state;
bool playitOnce = true; //This is to ensure that the music will be played once.
                        //Try removing this condition and it will be laggy.
ISound *beingChasedSnd;
ISound *gotShotsnd;
ISound *alwaysPlaying;

extern COORD aiCoordinate[MAX_SPACE];
extern COORD monCoordinate[MAX_SPACE];

const string SoundName[] =
{
    "../irrKlang-1.5.0/media/Dear,_Human.mp3",
    "../irrKlang-1.5.0/media/BeingChased.ogg",
    "../irrKlang-1.5.0/media/explosion.wav",
    "../irrKlang-1.5.0/media/gate_opened.wav",
    "../irrKlang-1.5.0/media/hatch_opened.wav"
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
    gateOpening =
        engine->addSoundSourceFromFile( SoundName[3].c_str() );
    hatchOpening =
        engine->addSoundSourceFromFile( SoundName[4].c_str() );
    // The following statements is to ensure that ISound pointer can be used
    alwaysPlaying = 
        engine->play2D(PlayThemeSong, true, false, true);
    alwaysPlaying->setVolume(0.7f);
    beingChasedSnd = 0;
    gotShotsnd = 0;
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
    if ( engine->isCurrentlyPlaying(beingChased))
        return;

        beingChasedSnd = 
            engine->play2D(beingChased, false, false, true);
        beingChasedSnd->setVolume(1);
}

void ShotByCannon()
{
    if ( engine->isCurrentlyPlaying(gotExploded) )
        return;

    gotShotsnd = 
        engine->play2D(gotExploded, false, false, true);
    gotShotsnd->setVolume(1);
}

void setAllSoundToPause()
{
    engine->setAllSoundsPaused();
}

void pauseTheChasingSound()
{
    if ( beingChasedSnd )
        beingChasedSnd->stop();
}

void pauseCannonSnd()
{
    if ( gotShotsnd )
        gotShotsnd->stop();
}

void playHatchSound()
{

}

void playGateSound()
{

}