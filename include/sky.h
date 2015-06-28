#ifndef SKY_H
#define SKY_H

#include <list>
#include "Bullet.h"
#include "Enemy.h"
#include "Hero.h"
#include "SFML/Graphics.hpp"

using namespace std;

class Sky{
    public:
        Sky();
        std::list<Bullet> bullets;
        Enemy enemies;
        Hero hero;
        int score;
        void refresh();
        void draw(sf::RenderWindow& window);
        void createnemies(int);
        virtual ~Sky();
    protected:
    private:
        sf::Texture backgroundtexture;
        sf::Sprite background;


};

#endif // SKY_H
