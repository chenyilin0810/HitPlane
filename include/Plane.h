#ifndef PLANE_H
#define PLANE_H

#include "Object.h"

class Plane:public Object
{
    public:
        Plane();
        void getHit();
        bool isDisappear();
        bool isDead();
        int life;
        virtual ~Plane();
    protected:
        int deadFraps;
        int deadCounter;
        bool dead;
    private:
};

#endif // PLANE_H
