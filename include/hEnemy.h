#ifndef HENEMY_H
#define HENEMY_H

#include "Plane.h"
#include <List>
#include "Bullet.h"

class Bullet;

class hEnemy:public Plane
{
    public:
        hEnemy(int);
        void move();
        void fire(std::list<Bullet> &);
        bool isDisappear();
        virtual ~hEnemy();
    protected:
    private:
        static sf::Texture* texture;
        sf::Vector2f origin;
        int count;
};

#endif // HENEMY_H
