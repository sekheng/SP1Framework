#include "BGMsounds.h"

ISoundEngine* engine;
ISoundSource* PlayThemeSong;
ISoundSource* beingChased;
extern startscreen state;
bool playitOnce = true;
ISound*snd;
string soundnames[] = {
    "../irrKlang-1.5.0/media/Dear,_Human.mp3",
    "../irrKlang-1.5.0/media/BeingChased.mp3"
};

void initBGMsounds()
{
    engine = createIrrKlangDevice();
    //PlayThemeSong =
    //    engine->addSoundSourceFromFile("../irrKlang-1.5.0/media/Dear,_Human.mp3");
    //beingChased =
    //    engine->addSoundSourceFromFile("../irrKlang-1.5.0/media/BeingChased.mp3");
}

void playSoundEvent()
{
    if ( state == menu && playitOnce == true)
    { 
        //if ( snd->getIsPaused() )
        //{
        //    snd->stop();
        //}
        playitOnce = false;
        /*snd = */engine->play2D(soundnames[0]);
    }
    else if ( state == Start && playitOnce == true)
    {
        //if ( snd->getIsPaused() )
        //{
        //    snd->stop();
        //}
        playitOnce = false;
        snd = engine->play2D(beingChased);
    }
}

bool changesGameState(bool check_Game_State)
{
    return playitOnce = true;
}

void changesSoundEvent()
{
    changesGameState(playitOnce);
}