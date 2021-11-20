#ifndef SOUND_H
#define SOUND_H

#include "audiere.h"

using namespace audiere;

class Sound
{
private:
    AudioDevicePtr device;
    OutputStreamPtr sound;
public:
    Sound();
    Sound(const LPCSTR wav_file_name, BOOL wav_dntload);
    ~Sound();
    VOID error_handler();
    VOID play(float plng_speed, BOOL repeat, float volume);
    VOID stop();
};

Sound::Sound() :
device(OpenDevice()), sound(OpenSound(device , "sound.wav" , false))
{
    error_handler();
}

Sound::Sound(const LPCSTR wav_file_name, BOOL wav_dntload) :
device(OpenDevice()), sound(OpenSound(device , wav_file_name, wav_dntload))
{
    error_handler();
}

Sound::~Sound()
{
    sound->stop();
}

VOID Sound::error_handler()
{
    if(!device)
    {
        txMessageBox("[sound.h 22-1||28-1] Device variable does not loaded!");
        exit(0);
    }
    if(!sound)
    {
        txMessageBox("[sound.h 22-23||28-23] Sound file does not open!");
        exit(0);
    }
}

VOID Sound::play(float plng_speed, BOOL repeat, float volume)
{
    sound->setVolume(volume);
    sound->setRepeat(repeat);
    sound->setPitchShift(plng_speed);
    sound->play();
}

VOID Sound::stop() { sound->stop(); }



#endif //SOUND_H
