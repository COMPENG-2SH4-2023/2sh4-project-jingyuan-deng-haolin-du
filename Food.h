#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"

class Food{
    private:
        objPos* foodPos;
    public:
        Food();
        ~Food();

        void generateFood(objPosArrayList* blockOff,const int xRange, const int yRange);
        void getFoodPos(objPos &returnPos);
};

#endif