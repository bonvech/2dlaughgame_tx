#include "TXLib.h"

#include "window.h"
#include "image.h"
#include "sound.h"
//#include "file.h"


int main()
{
    Sound sound("song.wav", true);
    while(!GetAsyncKeyState(VK_ESCAPE))
        sound.play(1.0, false, 0.3);
}
