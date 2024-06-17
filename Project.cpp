#include <iostream> 
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"


using namespace std;

#define DELAY_CONST 100000

Player* myPlayer;

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
    myPlayer = new Player(myGM);

    GameMechs gameMechs; 
    
}

void GetInput(void)
{
    myGM->getInput();
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();  

    objPos tempPos;

    myPlayer->getPlayerPos(tempPos);  

    int i, j;

    for (i = 0; i < myGM->getBoardSizeY(); i++) 
    {
        for (j = 0; j < myGM->getBoardSizeX(); j++) 
        {
            // Prints # for the border 
            if (i == 0 || i == myGM->getBoardSizeY() - 1 || j == 0 || j == myGM->getBoardSizeX() - 1) 
            {
                MacUILib_printf("#");
            } 
            else if (i == tempPos.y && j == tempPos.x)
            {
                // Print the player symbol at the player's position
                MacUILib_printf("%c", tempPos.symbol);
            }
            else
            {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");  // Move to the next line after printing each row
    }
    
    MacUILib_printf("BoardSize: %dx%d, Player Position: <%d, %d> + %c", 
                    myGM->getBoardSizeX(), 
                    myGM->getBoardSizeY(),
                    tempPos.x, tempPos.y, tempPos.symbol);

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
