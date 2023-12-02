#include "gameMechanics.h"
#include "MacUILib.h"

gameMechanics::gameMechanics()
{
    boardSizeX = 30;
    boardSizeY = 15;

    input = ' ';
    exitFlag = false;
    loseFlag = false;
    score = 0;
}

gameMechanics::gameMechanics(int boardX, int boardY)
{
    boardSizeX = boardX;
    boardSizeY = boardY;

    input = ' ';
    exitFlag = false;
    loseFlag = false;
    score = 0;
}

// do you need a destructor?



bool gameMechanics::getExitFlagStatus()
{
    return exitFlag;
}

bool gameMechanics::getLoseFlagStatus()
{
    return loseFlag;
}

char gameMechanics::getInput()
{
    if (MacUILib_hasChar()) {
        return MacUILib_getChar();
    }
    return 0;
}

int gameMechanics::getBoardSizeX()
{
    return boardSizeX;
}

int gameMechanics::getBoardSizeY()
{
    return boardSizeY;
}

int gameMechanics::getScore()
{
    return score;
}


void gameMechanics::setExitTrue()
{
    exitFlag = true;
}

void gameMechanics::setLoseFlag()
{
    loseFlag = true;
}

void gameMechanics::setInput(char this_input)
{
    input = this_input;
}

void gameMechanics::clearInput()
{
    MacUILib_getChar();
}

void gameMechanics::incrementScore()
{
    score += 1;
}

void gameMechanics::generateFood(objPos blockOff)
{
    while(true)
    {
        int x = rand() % boardSizeX;
        int y = rand() % boardSizeX;
        objPos obj(x, y, ' ');
        if (blockOff.isPosEqual(&obj))
        {
            continue;
        }
        foodPos = obj;
        break;
    }
}

void gameMechanics::getFoodPos(objPos& returnPos)
{
    returnPos = foodPos;
}


