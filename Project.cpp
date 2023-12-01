#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Food.h"
#include "GameMechs.h"
#include "objPosArrayList.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
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
    GameMechs m = new GameMechs();
    Food food = new Food();
    food.generateFood();
    exitFlag = false;
}

void GetInput(void)
{
   if(MacUILib_hasChar()!=0){
        m.setInput(MacUILib_getChar());
    }
}

void RunLogic(void)
{
    if(m.getInput != '\0')  // if not null character
    {
        /*switch(m.getInput()) 
        {                      
            case ' ':  // exit
                m.setExitTrue();
                break;

            // Add more key processing here
            case 'A':
            case 'a':
                if(direction != 'd'){ 
                    direction = 'a';
                }
                break;
                
            // Add more key processing here
            case 'S':
            case 's':
                if(direction != 'w'){//改
                    direction = 's';
                }
                break;
            // Add more key processing here    
            case 'D':
            case 'd':
                if(direction != 'a'){//改
                    direction = 'd';
                }
                break;
            case 'W':
            case 'w':
                if(direction != 's'){
                    direction = 'w';
                }
                break;
            default:
                break;
        }
        */
       player.updatePlayerDir();
       m.clearInput();
    }



    // [TODO] : Next, you need to update the player location by 1 unit 
    //          in the direction stored in the program
    /*if(direction == 'w'){
        player.YPos--;
        move_count++;
    }
    else if(direction == 's'){
        player.YPos++;
        move_count++;
    }
    else if(direction == 'a'){
        player.XPos--;
        move_count++;
    }
    else if(direction == 'd'){
        player.XPos++;
        move_count++;
    }
    // [TODO] : Heed the border wraparound!!!
    if(player.XPos == 0){
        player.XPos = 18;
    }
    if(player.XPos == 19){
        player.XPos = 1;
    }
    if(player.YPos == 0){
        player.YPos = 8;
    }
    if(player.YPos == 9){
        player.YPos = 1;
    }
    */
   player.movePlayer();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();

    delete m;
    ~Food();
}
