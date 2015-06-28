#ifndef OBJECT_H
#define OBJECT_H

#include "SFML/Graphics.hpp"

class Object:public sf::Sprite
{
    public:
        Object();
        void move();
        void changev(float,float);
        bool hit(sf::FloatRect);
        virtual ~Object();
        float x,y;
        float vx,vy;
        float ax,ay;
    protected:
    private:
};

#endif // OBJECT_H
