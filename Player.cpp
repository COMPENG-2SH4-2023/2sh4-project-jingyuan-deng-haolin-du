#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    gameMecRef = thisGMRef;
    myDir = STOP;
    playerPosList = new objPosArrayList();
    objPos aPos(rand() % thisGMRef->getBoardSizeX(), rand() % thisGMRef->getBoardSizeY(), SNACK_SIGN);
    playerPosList->insertHead(aPos);
    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
    delete[] playerPosList;
}

objPosArrayList* Player::getPlayerPos()
{
    // return the reference to the playerPos arrray list
    return playerPosList;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic 
    char c = gameMecRef->getInput();
    switch (c)
    {
    case 'A':
    case 'a':
        if (myDir != RIGHT) {
            myDir = LEFT;
        }
        break;
    case 'S':
    case 's':
        if (myDir != UP) {
            myDir = DOWN;
        }
        break;
    case 'D':
    case 'd':
        if (myDir != LEFT) {
            myDir = RIGHT;
        }
        break;
    case 'W':
    case 'w':
        if (myDir != DOWN) {
            myDir = UP;
        }
        break;
    case 'F':
    case 'f':
        myDir = STOP;
        break;
    }
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    objPos tmp;
    playerPosList->getHeadElement(tmp);
    int x = tmp.getX(), y = tmp.getY();
    switch (myDir)
    {
    case UP:
        y -= 1;
        break;
    case DOWN:
        y += 1;
        break;
    case LEFT:
        x -= 1;
        break;
    case RIGHT:
        x += 1;
        break;
    default:
        return;
    }
    if (x < 1) {
        x = gameMecRef->getBoardSizeX() - 2;
    }
    else if (x >= gameMecRef->getBoardSizeX()-1) {
        x = 1;
    }

    if (y < 1) {
        y = gameMecRef->getBoardSizeY() - 2;
    }
    else if (y >= gameMecRef->getBoardSizeY()-1) {
        y = 1;
    }
    tmp.setObjPos(x, y, tmp.getSymbol());
    playerPosList->insertHead(tmp);
    playerPosList->removeTail();
}

objPos Player::getHead()
{
    objPos t;
    playerPosList->getHeadElement(t);
    return t;
}
    
void Player::eatFood()
{
    objPos tmp;
    playerPosList->getHeadElement(tmp); // Get the current head position
    int x = tmp.getX(), y = tmp.getY(); // Extract x and y coordinates

    // Update the head position based on the current direction
    switch (myDir)
    {
    case UP:
        y -= 1;
        break;
    case DOWN:
        y += 1;
        break;
    case LEFT:
        x -= 1;
        break;
    case RIGHT:
        x += 1;
        break;
    default:
        return; // Exit if direction is undefined
    }

    // Wrap around the game board if the new position is out of bounds
    if (x < 1) {
        x = gameMecRef->getBoardSizeX() - 2;
    }
    else if (x >= gameMecRef->getBoardSizeX() - 1) {
        x = 1;
    }

    if (y < 1) {
        y = gameMecRef->getBoardSizeY() - 2;
    }
    else if (y >= gameMecRef->getBoardSizeY() - 1) {
        y = 1;
    }

    // Set the new head position and insert it at the head of the list
    tmp.setObjPos(x, y, tmp.getSymbol());
    playerPosList->insertHead(tmp);
}

// Method to check if the player has eaten itself
bool Player::eatSelf()
{
    objPos head, body;
    playerPosList->getHeadElement(head); // Get the head position

    // Iterate through the player's body to check for collision with the head
    for (int i = 1; i < playerPosList->getSize(); i++)
    {
        playerPosList->getElement(body, i);
        if (body.isPosEqual(&head)) {
            gameMecRef->setLoseFlag(true); // Set the lose flag if collision is detected
            return true;
        }
    }
    return false; // Return false if no collision is detected
}


