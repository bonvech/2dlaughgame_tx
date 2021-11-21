#ifndef SAVING_H
#define SAVING_H

class File
{
private:
    FILE *file;
public:
    File();
    File(char* name, char* mode);
    ~File();
    inline void error_handler();
    inline void get_string();
};

File::File()
{
    txMessageBox("File does not open!");
}

File::File(char* name, char* mode) :
file(fopen(name, mode))
{
}

File::~File()
{
    fclose(file);
}

inline void File::error_handler()
{
    if(file == nullptr)
    {
        txMessageBox("[file.h 22-1||18-6] File does not opened!");
        exit(0);
    }
}

inline void File::get_string()
{
     fgets
}
#endif //SAVING_H
