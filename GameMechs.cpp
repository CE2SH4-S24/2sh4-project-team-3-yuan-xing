#include "GameMechs.h"
#include "MacUILib.h"



GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    superFoodFlag = false;
    boardSizeX = 20;
    boardSizeY = 10;
    score = 0;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    superFoodFlag = false;
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

int GameMechs::getSuperFoodFlag()
{
    return superFoodFlag;
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

void GameMechs::setSuperFoodTrue()
{
    superFoodFlag = true;
}

void GameMechs::setSuperFoodFalse()
{
    superFoodFlag = false;
}

void GameMechs::incrementScore()
{
    score++;
}

void GameMechs::incrementSuperScore()
{
    score+=10;
}
// Provide definitions of more member functions as required
// See Project Manual

