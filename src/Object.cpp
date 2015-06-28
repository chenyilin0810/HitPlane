#include "Object.h"
#include<iostream>
Object::Object()
{
    //ctor
}

void Object::move(){

 //   std::cout<<this->y<<std::endl;

    this->x+=vx;this->y+=vy;
    this->setPosition(this->x,this->y);

}

void Object::changev(float detx,float dety){

    vx+=detx;
    vy+=dety;


}

Object::~Object()
{
    //dtor
}

bool Object::hit(sf::FloatRect someThing)
{
    return this->getGlobalBounds().intersects( someThing );
}
