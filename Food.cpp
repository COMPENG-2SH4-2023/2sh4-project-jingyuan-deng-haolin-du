#include "Food.h"

Food::Food(){
    foodList = new objPosArrayList();
}

Food::~Food(){
    delete[] foodList;
}

void Food::generateFood(objPosArrayList* blockOff, const int xRange, const int yRange){
    srand(time(NULL));
    int usedPose[xRange - 2][yRange - 2];
    objPos temp;
    for(int i = 0; i<blockOff->getSize(); i++){
        blockOff->getElement(temp, i);
        usedPose[temp.getX()][temp.getY()] = 1;
    }
    objPos nFood,sFood;
    
    for(int i=0; i<(xRange-2); i++){
        for(int j=0; j<(yRange-2); j++){
            do{
                nFood.x = rand()%(xRange-3)+1;
                nFood.y = rand()%(yRange-3)+1;
            }while(usedPose[nFood.getX()][nFood.getY()]==1);
            nFood.symbol = 'o';
            foodList->insertHead(nFood);
            do{
                sFood.x = rand()%(xRange-3)+1;
                sFood.y = rand()%(yRange-3)+1;
            }while(usedPose[sFood.getX()][sFood.getY()]==1);
            sFood.symbol = '$';
            foodList->insertTail(sFood);
        }
    }
    
}

void Food::getFoodPos(objPos &returnPos, int element){
    foodList->getElement(returnPos, element);
}

objPosArrayList* Food::getFoodList(){
    return foodList;
}