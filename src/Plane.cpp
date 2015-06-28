#include "Plane.h"

#include <iostream>

Plane::Plane(){
    this->dead = false;
}

Plane::~Plane()
{
    //dtor
}

void Plane::getHit(){
    life--;
}

bool Plane::isDead(){
    return life<=0;
}

bool Plane::isDisappear(){
    return deadCounter > deadFraps;
}
