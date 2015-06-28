#include "Enemy.h"
#include <iostream>
#include "SFML/Audio.hpp"
Enemy::Enemy()
{
    //ctor
}

void Enemy::draw(sf::RenderWindow& window){

    list<sEnemy>::iterator it1 = sEnemies.begin();
    for(;it1!=sEnemies.end();it1++)
        window.draw(*it1);
    list<hEnemy>::iterator it2 = hEnemies.begin();
    for(;it2!=hEnemies.end();it2++)
        window.draw(*it2);

}

void Enemy::checkdisappear(int &score){

    list<sEnemy>::iterator it1 = sEnemies.begin();
    for(;it1!=sEnemies.end();it1++){
        if(it1->y>=600){
            std::list<sEnemy>::iterator tmp=it1--;
            sEnemies.erase(tmp);
        }
        else if( it1->isDisappear()){
            score+=10;
            sf::Music music;
            music.openFromFile("resources\\sound\\enemy1_down.ogg");
            music.play();
            std::list<sEnemy>::iterator tmp=it1--;
            sEnemies.erase(tmp);
        }
    }
    list<hEnemy>::iterator it2 = hEnemies.begin();
    for(;it2!=hEnemies.end();it2++){
        if(it2->y>=600){
            std::list<hEnemy>::iterator tmp=it2--;
            hEnemies.erase(tmp);
        }
        else if(it2->isDisappear()){
            score+=50;
            sf::Music music;
            music.openFromFile("resources\\sound\\enemy3_down.ogg");
            music.play();
            std::list<hEnemy>::iterator tmp=it2--;
            hEnemies.erase(tmp);
        }
    }



}

void Enemy::move(){

    list<sEnemy>::iterator it1 = sEnemies.begin();
    for(;it1!=sEnemies.end();it1++)
        it1->move();
    list<hEnemy>::iterator it2 = hEnemies.begin();
    for(;it2!=hEnemies.end();it2++){
        it2->move();
    }


}
void Enemy::fire(std::list<Bullet> &bullets){
    list<hEnemy>::iterator it2 = hEnemies.begin();
    for(;it2!=hEnemies.end();it2++){
        it2->fire(bullets);
    }

}
void Enemy::create(int v){

        int k=rand()%2;
        if(k==0){
            sEnemy temp(v);
            sEnemies.push_back(temp);
        }
        else{
            hEnemy temp(v);
            hEnemies.push_back(temp);
        }

}

Enemy::~Enemy()
{
    //dtor
}
