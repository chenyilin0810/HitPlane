#include "Sky.h"
#include<iostream>
Sky::Sky(){

    backgroundtexture.loadFromFile("resources\\image\\background.png");
    this->background.setTexture(backgroundtexture);
    score=0;

}

void Sky::draw(sf::RenderWindow& window){

    window.draw(this->background);
    list<Bullet>::iterator it = bullets.begin();
    for(;it!=bullets.end();++it)
        window.draw(*it);
    enemies.draw(window);
    window.draw(hero);

}
void Sky::refresh(){

        hero.move();
        std::list<Bullet>::iterator it=bullets.begin();

        for(;it!=bullets.end();it++)
            it->move();

        it = bullets.begin();
        while(it != bullets.end()){
            if((it->vy<0)&&it->isdisappear( enemies )){
                it = bullets.erase(it);
            }
            else if((it->vy>0)&&it->hit(hero.getGlobalBounds())){
                hero.getHit();
                score+=hero.life*10;
                it= bullets.erase(it);
            }
            else ++it;
        }

        enemies.fire(bullets);
        enemies.move();
        enemies.checkdisappear(score);

}
void Sky::createnemies(int speed){

    enemies.create(speed);


}

Sky::~Sky()
{
    //dtor
}
