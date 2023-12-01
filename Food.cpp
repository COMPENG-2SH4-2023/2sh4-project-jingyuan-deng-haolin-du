#include "Food.h"

Food::Food(){
    foodPos = new objPos();
}

Food::~Food(){
    delete foodPos;
}

void Food::generateFood(objPos blockOff, const int xRange, const int yRange){

    srand(time(NULL));
    do{
        foodPos.x = rand()%(xRange-3)+1;
        foodPos.y = rand()%(yRange-3)+1;
    }while(foodPos.x!=blockOff.x&&foodPos.y!=blockOff.y);
    
    foodPos.symbol = '*';

}

void Food::getFoodPos(objPos &returnPos){
    returnPos.x = foodPos.x;
    returnPos.y = foodPos.y;
    returnPos.symbol = foodPos.symbol;
}