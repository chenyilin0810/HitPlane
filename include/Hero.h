#ifndef HERO_H
#define HERO_H

#include "Plane.h"
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include <List>

class Hero:public Plane
{
    public:
        Hero();
        void fire(std::list<Bullet> &);
        void move();
        void reseta();
        void dead();
        virtual ~Hero();
    protected:
    private:
        sf::Texture texture;
        sf::Vector2f origin;
};

#endif // HERO_H
