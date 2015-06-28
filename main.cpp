#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Sky.h"
#include <list>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>

int stageamount[3]={1000,800,500};
int stagespeed[3]={1,5,8};

void action(Sky &sky,sf::Event& operate){
    if(operate.key.code==sf::Keyboard::Up)
        sky.hero.changev(0,-2);
    if(operate.key.code==sf::Keyboard::Down)
        sky.hero.changev(0,2);
    if(operate.key.code==sf::Keyboard::Right)
        sky.hero.changev(2,0);
    if(operate.key.code==sf::Keyboard::Left)
        sky.hero.changev(-2,0);
    if(operate.key.code==sf::Keyboard::Space){
        sky.hero.fire(sky.bullets);
        //sky.score--;
        }

}

int main(){

    sf::RenderWindow window(sf::VideoMode(360, 600), "HitPlane");
    window.setFramerateLimit(60);

    sf::Music music;
    if (!music.openFromFile("resources\\sound\\game_music.ogg"))
        return EXIT_FAILURE;
    music.play();

    Sky sky;
    sf::Texture *deadPic=NULL;
    sf::Sprite deadScene;
    sf::Font font;
    if (!font.loadFromFile("resources\\font\\STHeiti Light.ttc"))
        return EXIT_FAILURE;

    clock_t start=std::clock();
    while (window.isOpen()){
        sf::Text text,stagetext;
        sf::Event operate;
        text.setFont(font);
        text.setCharacterSize(20);
        char score[25];
        sprintf(score, "%s%d","score:",sky.score);
        text.setString(score);
        text.setPosition(240,10);
        text.setColor(sf::Color::Red);
        stagetext.setFont(font);
        stagetext.setCharacterSize(20);
        stagetext.setString("STAGE1");
        stagetext.setPosition(20,10);
        stagetext.setColor(sf::Color::Black);

        while (window.pollEvent(operate)){
            if(operate.type==sf::Event::Closed){
                window.close();
            }

            if(operate.type==sf::Event::KeyPressed){
                action(sky,operate);

            }
        }

        if(sky.score<0){
                if(deadPic==NULL){
                    deadPic=new sf::Texture();
                    deadPic->loadFromFile("resources\\image\\gameover.png");
                    deadScene.setTexture(*deadPic);
                    deadScene.scale(sf::Vector2f(0.75, 0.75));
                }
                window.draw(deadScene);
                window.display();
                continue;
        }

        clock_t end=std::clock();
            sky.refresh();
        double timeh=stageamount[0];
        int speed=stagespeed[0],stage=0;
        if(sky.score>=500&&stage!=2){
            stage=2;
            timeh=stageamount[stage];
            speed=stagespeed[stage];
            stagetext.setString("STAGE3");
        }
        else if(sky.score>=200&&stage!=1){
            stage=1;
            timeh=stageamount[stage];
            speed=stagespeed[stage];
            stagetext.setString("STAGE2");
        }

        if(double((end-start))>=timeh){
            sky.enemies.create(speed);
            start=std::clock();
        }
        window.clear();
        sky.draw(window);
        window.draw(stagetext);
        window.draw(text);
        window.display();

    }
    return 0;

}



