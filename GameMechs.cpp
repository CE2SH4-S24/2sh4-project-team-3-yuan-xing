#include "GameMechs.h"
#include "MacUILib.h"



GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    boardSizeX = 20;
    boardSizeY = 10;
    score = 0;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
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
    if(MacUILib_hasChar())
    {
        input = MacUILib_getChar();
        if (input == 27)             
        { 
            setExitTrue();
        }
    }
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

int GameMechs::getScore()
{
    return score;
}

void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlagTrue()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

void GameMechs::incrementScore()
{
    score++;
}

// Provide definitions of more member functions as required
// See Project Manual

void GameMechs::generateFood(objPos blockOff)
{
    //Generate random x and y cords for food item.
    // and make sure they are not:
    //1. on the border
    //2. or clash with player position(blockOff)
    //check x and y against 0 and boardSizex/boardSizey

    //check against the player position
    //check against the player position
    //remember, in the objPos class you should have isPosEqual() method
    //
}