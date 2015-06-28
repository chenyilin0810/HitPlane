#include "sEnemy.h"

sf::Texture* sEnemy::texture=NULL;

sEnemy::sEnemy(int v){

    if(texture==NULL){
        sEnemy::texture=new sf::Texture();
        this->texture->loadFromFile("resources\\image\\shoot.png",sf::IntRect(534,612,57,43));
    }
    this->setTexture(*texture);
    this->setOrigin(57, 43);
    this->origin = this->getOrigin();
    this->x=rand()%303+57;this->y=0;
    this->setPosition(x,y);
    this->scale(sf::Vector2f(0.75, 0.75));
    vx=ax=ay=0;
    vy=1.5*v;
    life=1;

}

bool sEnemy::isDisappear(){

    return this->isDead();

    }


sEnemy::~sEnemy()
{
    //dtor
}
