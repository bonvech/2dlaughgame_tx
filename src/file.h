#ifndef SAVING_H
#define SAVING_H

#include <fstream>

class File
{
private:
    std::fstream file;
public:
    inline File();
    inline File(char* name, int mode);
    inline ~File();
    inline void open (char* name, int mode);
    inline bool is_all_right();
    inline bool open_and_check (char* name, int mode);
    inline void read_string(char* pointer, int length);
    inline void readContent (char* pointer, int length);

};

inline File::File(char* name, int mode) { open(name, mode); }

inline File::~File() { file.close(); }

inline void File::open (char* name, int mode)
{
    switch(mode)
    {
        case 0:
            file.open(name, std::ios_base::in);
            break;
        case 1:
            file.open(name, std::ios_base::out);
            break;
        case 2:
            file.open(name, std::ios_base::ate);
            break;
        case 3:
            file.open(name, std::ios_base::app);
            break;
        case 4:
            file.open(name, std::ios_base::trunc);
            break;
        default:
            file.open(name, std::ios_base::app);
            break;
    }
}

inline bool File::is_all_right() { return file.good(); }

inline bool File::open_and_check (char* name, int mode)
{
    open(name, mode);
    return is_all_right();
}

inline void File::read_string (char* pointer, int length)
{
    file.read(pointer, length);
    *(pointer+length) = '\0';
}

inline void File::readContent (char* pointer, int length) { file.read(pointer, length); }
#endif //SAVING_H
