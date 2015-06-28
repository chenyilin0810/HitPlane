#include "hEnemy.h"

#include <iostream>

const sf::IntRect deadRect[7] ={
    sf::IntRect(0, 0, 0, 0),
    sf::IntRect(0, 486, 165, 261),
    sf::IntRect(0, 225, 165, 261),
    sf::IntRect(839, 748, 165, 260),
    sf::IntRect(165, 486, 165, 261),
    sf::IntRect(673, 748, 166, 260),
    sf::IntRect(0, 747, 166, 261)
};

sf::Texture* hEnemy::texture=NULL;

hEnemy::hEnemy(int v){

    if(texture==NULL){
        hEnemy::texture=new sf::Texture();
        this->texture->loadFromFile("resources\\image\\shoot.png");
    }

    this->setTexture(*texture);
    this->setTextureRect(sf::IntRect(335,750,169,258));
    this->setOrigin(169, 258);
    this->origin = this->getOrigin();
    this->x=rand()%191+169;this->y=0;
    this->setPosition(x,y);
    this->scale(sf::Vector2f(0.75, 0.75));
    vx=ax=ay=0;
    vy=v;
    life=5;
    count=0;
    deadCounter=0;
    deadFraps=6;
}

void hEnemy::fire(std::list<Bullet> &bullets){
    if(count==40){
        count=0;
        bullets.push_back(Bullet(x-60,y+20,10));
    }
    count++;
}

hEnemy::~hEnemy()
{
    //dtor
}

bool hEnemy::isDisappear(){

    return deadCounter > deadFraps;
}

void hEnemy::move(){
    if(this->isDead()) {
     //   std::cout<<deadCounter<<std::endl;
        this->setTextureRect(deadRect[++deadCounter]);
    }
    Object::move();
}
