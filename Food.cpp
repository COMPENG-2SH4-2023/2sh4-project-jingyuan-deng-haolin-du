#include "Food.h"

// Constructor for the Food class
Food::Food(){
    // Initialize the foodList as a new objPosArrayList
    foodList = new objPosArrayList();
}

// Destructor for the Food class
Food::~Food(){
    // Free the memory allocated for foodList
    delete[] foodList;
}

// Method to generate food items on the game field
void Food::generateFood(objPosArrayList* blockOff, const int xRange, const int yRange){
    srand(time(NULL)); // Seed the random number generator

    int usedPose[xRange - 2][yRange - 2]; // Array to keep track of used positions

    objPos temp; // Temporary object position holder

    // Mark positions in the blockOff list as used
    for(int i = 0; i < blockOff->getSize(); i++){
        blockOff->getElement(temp, i);
        usedPose[temp.getX()][temp.getY()] = 1;
    }

    objPos nFood, sFood; // Variables to store the new food positions

    // Loop to generate new food positions
    for(int i = 0; i < (xRange-2); i++){
        for(int j = 0; j < (yRange-2); j++){
            // Generate a random position for normal food
            do{
                nFood.x = rand() % (xRange-3) + 1;
                nFood.y = rand() % (yRange-3) + 1;
            } while(usedPose[nFood.getX()][nFood.getY()] == 1);
            nFood.symbol = 'o'; // Set the symbol for normal food
            foodList->insertHead(nFood); // Insert at the head of the list

            // Generate a random position for special food
            do{
                sFood.x = rand() % (xRange-3) + 1;
                sFood.y = rand() % (yRange-3) + 1;
            } while(usedPose[sFood.getX()][sFood.getY()] == 1);
            sFood.symbol = '$'; // Set the symbol for special food
            foodList->insertTail(sFood); // Insert at the tail of the list
        }
    }
}

// Method to get the position of a specific food item
void Food::getFoodPos(objPos &returnPos, int element){
    // Retrieve the position of the specified element from the list
    foodList->getElement(returnPos, element);
}

// Method to get the list of all food items
objPosArrayList* Food::getFoodList(){
    // Return the pointer to the food list
    return foodList;
}