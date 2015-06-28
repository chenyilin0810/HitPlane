#include "Hero.h"
#include <iostream>

Hero::Hero()
{
    texture.loadFromFile("resources\\image\\shoot.png",sf::IntRect(0,99,102,126));

    this->setTexture(texture);

    this->setOrigin(51,126);

    this->origin = this->getOrigin();

    this->x=180;this->y=600;

    this->setPosition(x,y);

    this->scale(sf::Vector2f(0.75, 0.75));

    vx=vy=ax=ay=0;

    this->life = 1;

}

void Hero::fire(std::list<Bullet> &bullets){

    Bullet bullet(x+4,y-94.5,-10);
    bullets.push_back(bullet);

}

void Hero::move(){
    int tempx=this->x+vx,tempy=this->y+vy;
    if(tempx<0||tempx>360)
        vx=0;
    if(tempy<94.5||tempy>600)
        vy=0;
    this->x+=vx;this->y+=vy;
    this->setPosition(this->x,this->y);
    vx/=1.1;
    vy/=1.1;

}

Hero::~Hero()
{
    //dtor
}
