#include "Bullet.h"

Bullet::Bullet(){

}
sf::Texture* Bullet::texture=NULL;

Bullet::Bullet(int x,int y,int vy):Object(){
    this->x=x;
    this->y=y;
    if(texture==NULL){
        Bullet::texture=new sf::Texture();
        this->texture->loadFromFile("resources\\image\\shoot.png",sf::IntRect(1004,987,9,21));
    }
    this->setTexture(*texture);
    this->setOrigin(9, 21);
    this->origin = this->getOrigin();
    this->setPosition(x,y);
    this->scale(sf::Vector2f(0.75, 0.75));

    vx=ax=ay=0;

    this->vy=vy;
}

bool Bullet::isdisappear(){

    if(this->y<=0||this->y>=600)
        return true;
    return false;
    }

Bullet::~Bullet()
{
    //dtor
}
/*
bool Bullet::hit(Plane& plane)
{
    return Object::hit( plane.getGlobalBounds() );
}
*/
bool Bullet::isdisappear(Enemy& enemies)
{
    bool flag = this->isdisappear();
    for (sEnemy &s : enemies.sEnemies) {
        if (Object::hit(s.getGlobalBounds())) {
            s.getHit();
            flag = true;
        }
    }

    for(hEnemy &h : enemies.hEnemies) {
        if(Object::hit(h.getGlobalBounds())) {
            h.getHit();
            flag = true;
        }
    }
    return flag;
}
