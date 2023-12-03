#include "Food.h"

Food::Food(){
    foodPos = new objPos();
}

Food::~Food(){
    delete[] foodPos;
}

void Food::generateFood(objPosArrayList* blockOff, const int xRange, const int yRange){

    srand(time(NULL));
    int usedPose[xRange - 2][yRange - 2];
    objPos temp;
    for(int i = 0; i<blockOff->getSize(); i++){
        blockOff->getElement(temp, i);
        usedPose[temp.getX()][temp.getY()] = 1;
    }
    for(int i=0; i < xRange - 2; i++){
        for(int j =0; j<yRange - 2; j++){
            do{
                foodPos->x = rand()%(xRange-3)+1;
                foodPos->y = rand()%(yRange-3)+1;
            }while(usedPose[foodPos->x][foodPos->y]==1);
        }
    }    
    foodPos->symbol = '$';

}

void Food::getFoodPos(objPos &returnPos){
    returnPos.x = foodPos->x;
    returnPos.y = foodPos->y;
    returnPos.symbol = foodPos->symbol;
}