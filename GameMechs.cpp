#include "GameMechs.h"

// Default constructor for GameMechs
GameMechs::GameMechs()
{
    input = '\0'; // Initialize input with a null character
    exitFlag = false; // Flag to control game exit, initially set to false
    loseFlag = false; // Flag to indicate losing condition, initially set to false

    boardSizeX = 30; // Default horizontal size of the game board
    boardSizeY = 15; // Default vertical size of the game board

    score = 0; // Initialize score to 0
}
// Overloaded constructor for GameMechs allowing custom board sizes
GameMechs::GameMechs(int boardX, int boardY)
{
    input = '\0';
    exitFlag = false;
        
    boardSizeX = boardX;
    boardSizeY = boardY;

    score = 0;
    
}

// do you need a destructor?
// A destructor for GameMechs is not necessarily required here unless you have dynamically generated GameMechs.


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