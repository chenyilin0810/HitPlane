# 打飞机实验报告<br>
## 给谁做的？
自己没事干打着玩的。。biubiubiu放松一下<br><br>

##哪些功能及游戏规则？
* 左右键移动<br>
* 空格键开炮<br>
* 两种飞机，小飞机飞行速度较快&不会攻击，大飞机飞行速度较慢但是可以biubiubiu<br>
* 有三个关卡，按分数进入，飞机飞行速度线性增加<br>
* 计分方式诡异：玩家第一次被击中扣10分，第二次被击中扣20分。。以此类推，得分为0时游戏结束<br><br>

##实现
###工具&环境
* windows7
* CodeBlocks13.12 with gcc4.7.1
* SFML2.3

###UML

###关键代码
```cpp

    window.setFramerateLimit(60);
    music.play();
    Sky sky;

    clock_t start=std::clock();
    while (window.isOpen()){

        while (window.pollEvent(operate)){
            if(operate.type==sf::Event::Closed){
                window.close();
            }

            if(operate.type==sf::Event::KeyPressed){
                action(sky,operate);//the function react to keyboard operation

            }
        }

        if(sky.score<0){//game over
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
        
            sky.refresh();//refresh status of the sky
            
        //stage control
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
        
			//the speed to create enemies
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

```
##做得如何？
###游戏截图
###运行速度
我觉得还行吧。。
###玩家评价
不够难，功能也不够多

##总结与心得
* 深深地感受到了大神们的威力以及差距
* 感谢飞宇大神，感谢雷神
* 第一次用图形引擎写程序，也算是写的第一个有点意思的完整的C++程序，心情很复杂
* 了解了面向对象的思想，还是有点意思
* 过程是艰辛的，成品出来了是开心的
* 以后有空再重构再优化，希望能做出来一个让自己觉得好玩的游戏
* 要学会用git，不然一朝回到解放前哭都哭不出来
