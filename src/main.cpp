#include "TXLib.h"

#include "window.h"
#include "image.h"
#include "sound.h"
#include "file.h"

Window main_window(1500, 700, "Name", 13);

int main()
{
    char my[13];
    File file("configuration\\save_file.txt", 1); //open with ios_base::out
    file.read_string(my, 13);
    for(size_t i = 0; i < 13; i++)
        printf("%c", my[i]);
}
