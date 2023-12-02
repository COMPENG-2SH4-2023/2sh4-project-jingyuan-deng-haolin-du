#include "Player.h"


Player::Player(gameMechanics* thisGMRef)
{
    gameMecRef = thisGMRef;
    myDir = STOP;
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(objPos(rand() % thisGMRef->getBoardSizeX(), rand() % thisGMRef->getBoardSizeY(), SNACK_SIGN));
    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
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
        x -= 1;
        break;
    case DOWN:
        x += 1;
        break;
    case LEFT:
        y -= 1;
        break;
    case RIGHT:
        y += 1;
        break;
    default:
        return;
    }
    if (x < 0) {
        x = gameMecRef->getBoardSizeX() - 1;
    }
    else if (x >= gameMecRef->getBoardSizeX()) {
        x = 0;
    }

    if (y < 0) {
        y = gameMecRef->getBoardSizeY() - 1;
    }
    else if (y >= gameMecRef->getBoardSizeY()) {
        y = 0;
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
    playerPosList->getHeadElement(tmp);
    int x = tmp.getX(), y = tmp.getY();
    switch (myDir)
    {
    case UP:
        x -= 1;
        break;
    case DOWN:
        x += 1;
        break;
    case LEFT:
        y -= 1;
        break;
    case RIGHT:
        y += 1;
        break;
    default:
        return;
    }
    if (x < 0) {
        x = gameMecRef->getBoardSizeX() - 1;
    }
    else if (x >= gameMecRef->getBoardSizeX()) {
        x = 0;
    }

    if (y < 0) {
        y = gameMecRef->getBoardSizeY() - 1;
    }
    else if (y >= gameMecRef->getBoardSizeY()) {
        y = 0;
    }
    tmp.setObjPos(x, y, tmp.getSymbol());
    playerPosList->insertHead(tmp);
}

bool Player::eatSelf()
{
    objPos head, body;
    playerPosList->getHeadElement(head);
    for (int i = 1; i < playerPosList->getSize(); i++)
    {
        playerPosList->getElement(body, i);
        if (body.isPosEqual(&head)) {
            gameMecRef->setLoseFlag();
            return true;
        }
    }
    return false;
}


