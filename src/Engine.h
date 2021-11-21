#ifndef ENGINE_H
#define ENGINE_H

class Engine
{
private:
    Window main_window();
    //Sound sound();
    Image image();
    File file();
    Camera cam();
public:
    Engine();
    ~Engine();
    void start();
    void stop();
};

#endif //ENGINE_H
