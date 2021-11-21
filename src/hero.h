#ifndef HERO_H
#define HERO_H

#include "Image.h"

typedef struct Coords { double x; double y; } coords_t;

typedef enum Direction { LEFT, RIGHT, NONE } dirct_t;

class Hero
{
private:
    Image hero_img;
    coords_t coordinates;
    dirct_t direction;
public:
    Hero();
    ~Hero();
    inline void move_left();
    inline void move_right();
    inline void jump();
    void check_keys();
};

Hero::Hero() :
direction(NONE), hero_img(514, 578, "img\\hero_img.bmp")
{
    coordinates = {0.0, 0.0};
}

Hero::~Hero()
{
    txDeleteDC(hero_img.get_img());
}

inline void Hero::move_left()
{
    direction(LEFT);
    coordinates.x -= vx;
}

inline void Hero::move_right()
{
    direction(RIGHT);
    coordinates.x += vx;
}

inline void Hero::jump()
{
    direction(NONE);
    coordinates.y -= vy;
}

#endif //HERO_H
