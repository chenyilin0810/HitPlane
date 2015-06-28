#ifndef ENEMY_H
#define ENEMY_H

#include "sEnemy.h"
#include "hEnemy.h"
#include <SFML/Graphics.hpp>
#include <List>

using namespace std;

class Bullet;
class hEnemy;
class sEnemy;

class Enemy
{
    public:
        Enemy();
        void draw(sf::RenderWindow& window);
        void move();
        void fire(std::list<Bullet> &);
        void checkdisappear(int &);
        void create(int v);
        virtual ~Enemy();
        friend Bullet;
    protected:
    private:
        std::list<sEnemy> sEnemies;
        std::list<hEnemy> hEnemies;

};

#endif // ENEMY_H
