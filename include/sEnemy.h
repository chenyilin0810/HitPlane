#ifndef SENEMY_H
#define SENEMY_H

#include "Plane.h"
#include <SFML/Graphics.hpp>
#include <stdlib.h>

class sEnemy:public Plane
{
    public:
        sEnemy(int);
        bool isDisappear();
        virtual ~sEnemy();
    protected:
    private:
        static sf::Texture* texture;
        sf::Vector2f origin;
};

#endif // SENEMY_H
