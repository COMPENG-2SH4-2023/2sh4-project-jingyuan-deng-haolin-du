#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);
bool inSnackBody(objPosArrayList* obj, int x, int y);

GameMechs *m = new GameMechs();
Player *p = new Player(m);
Food *food = new Food();

int main(void)
{

    Initialize();

    while(m->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    
    food->generateFood(p->getPlayerPos(),m->getBoardSizeX(), m->getBoardSizeY());
}

void GetInput(void)
{
   if(MacUILib_hasChar()!=0){
        m->setInput(MacUILib_getChar());
    }
}

void RunLogic(void)
{
    if(m->getInput() == ' '){
        m->setExitFlag(true);
    }
    if(m->getInput() != '\0')  // if not null character
    {
       p->updatePlayerDir();
       m->clearInput();
    }
    p->movePlayer();
    objPos normFood;
    food->getFoodPos(normFood);
    if((p->getHead().x == normFood.getX())&&(p->getHead().y == normFood.getY())){
        p->eatFood();
        m->incrementScore();
        food->generateFood(p->getPlayerPos(),m->getBoardSizeX(), m->getBoardSizeY());
    }
    if(p->eatSelf()==true){
        m->setLoseFlag(true);
    }
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    
    if(m->getExitFlagStatus()==true){
        MacUILib_printf("\nUser Quit\n");
    }
    else if(m->getLoseFlagStatus()==true){
        MacUILib_printf("\nYou Lose\n");
        MacUILib_printf("\nScore: %d\n", m->getScore());
        MacUILib_printf("\nPress 'Space' to quit. \n");
    }
    else{
        MacUILib_clearScreen();
        int board[m->getBoardSizeX()][m->getBoardSizeY()];
        objPos nFood;
        food->getFoodPos(nFood);
        for(int i = 0; i<m->getBoardSizeX(); i++){
            for(int j = 0; j<m->getBoardSizeY(); j++){
                if(inSnackBody(p->getPlayerPos(), i, j) == true){
                    board[i][j] = 1;
                }
                else if(i == nFood.x && j == nFood.y){
                    board[i][j] = 2;
                }
                else{
                    board[i][j] = 0;
                }
            }
        }
        for(int j = 0; j<m->getBoardSizeY(); j++){
            for(int i = 0; i<m->getBoardSizeX(); i++){
                if(i==m->getBoardSizeX()-1){
                    MacUILib_printf("#\n");
                }
                else if(j==0&&i!=m->getBoardSizeX()-1||j==m->getBoardSizeY()-1||i==0){
                    MacUILib_printf("#");
                }
                else if(board[i][j]==1){
                    MacUILib_printf("%c", p->getHead().symbol);
                }
                else if(board[i][j] == 2){
                    MacUILib_printf("%c", nFood.symbol);
                }
                else if (board[i][j]==0){
                    MacUILib_printf(" ");
                }
            }
        }
        MacUILib_printf("\nScore: %d\n", m->getScore());
        MacUILib_printf("\nPress 'Space' to quit. \n");
    }
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();

    delete[] m;
    delete[] p;
    delete[] food;
}

bool inSnackBody(objPosArrayList* body, int x, int y)
{
	objPos part;
	for (int i = 0; i < body->getSize(); i++)
	{
		body->getElement(part, i);
		if (part.getX() == x && part.getY() == y) {
			return true;
		}
	}
	return false;
}