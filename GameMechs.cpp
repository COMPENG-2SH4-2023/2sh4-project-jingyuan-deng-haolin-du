#include "GameMechs.h"

GameMechs::GameMechs()
{
    input = '\0';
    exitFlag = false;
    loseFlag = false;

    boardSizeX = 30;
    boardSizeY = 15;

    score = 0;

}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = '\0';
    exitFlag = false;
        
    boardSizeX = boardX;
    boardSizeY = boardY;

    score = 0;
    
}

// do you need a destructor?



bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}

char GameMechs::getInput()
{
    return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}


void GameMechs::setExitFlag(bool status)
{
    exitFlag = status;
}

void GameMechs::setLoseFlag(bool status)
{
    loseFlag = status;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = '\0';
}

int GameMechs::getScore(){
    return score;
}

void GameMechs::incrementScore(int num){
    score += num;
}