#include <iostream> 
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
#include "objPosArrayList.h"
#include "Food.h"


using namespace std;

#define DELAY_CONST 100000

Player* myPlayer;
Food* myFood;
GameMechs* myGM;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
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

    myGM = new GameMechs(26, 13);
    myFood = new Food(myGM);
    myPlayer = new Player(myGM, myFood);

    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    myFood->generateFood(playerBody); 
    
    
}

void GetInput(void)
{
    myGM->getInput();
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();

    myGM->clearInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();  

    bool drawn;
    bool drawnFood;

    objPosArrayList* playerBody = myPlayer->getPlayerPos();;
    objPosArrayList* foodBin = myFood->getFoodPos();;

    objPos tempBody;
   
    for (int i = 0; i < myGM->getBoardSizeY(); i++) 
    {
        for (int j = 0; j < myGM->getBoardSizeX(); j++) 
        {
            drawn = false;
            drawnFood = false;

            // iterate though all elements in the list
            for(int k = 0; k < playerBody->getSize(); k++)
            {
                playerBody->getElement(tempBody, k);
                if (tempBody.x == j && tempBody.y == i)
                {
                    MacUILib_printf("%c", tempBody.symbol);
                    drawn = true;
                    break;
                }
            }

            if(drawn) 
            {
                continue;
            }

            // iterate though all elements in the food bin
            for(int l = 0; l < foodBin->getSize(); l++)
            {
                foodBin->getElement(tempBody, l);                        
                if(tempBody.x == j && tempBody.y == i)
                {
                    cout << tempBody.getSymbol();
                    drawnFood = true;
                    break;
                }
            }

            if(drawnFood)
            {
                continue;
            }

            // Prints # for the border 
            if (i == 0 || i == myGM->getBoardSizeY() - 1 || j == 0 || j == myGM->getBoardSizeX() - 1) 
            {
                MacUILib_printf("#");
            } 
            
            else
            {
                MacUILib_printf(" ");
            }
            

        }
        MacUILib_printf("\n");  // Move to the next line after printing each row
        
    }
    MacUILib_printf("Score: %d", myGM->getScore());
    MacUILib_printf("\n");
    
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    delete myPlayer; 
    delete myGM;
    MacUILib_uninit();
}
