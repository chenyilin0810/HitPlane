#ifndef BULLET_H
#define BULLET_H

#include "Object.h"
#include "Plane.h"
#include "Enemy.h"
class Enemy;

class Bullet:public Object
{
    public:
        Bullet();
        Bullet(int,int,int);
        bool isdisappear();
        //bool hit(Plane&);
        bool isdisappear(Enemy&);
        virtual ~Bullet();
    protected:
    private:
        static sf::Texture* texture;
        sf::Vector2f origin;
};

#endif // BULLET_H
