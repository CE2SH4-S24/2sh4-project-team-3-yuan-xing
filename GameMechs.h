#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class GameMechs
{   
    // GameMechs is the Game Mechanism class
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        bool superFoodFlag = false;

        int boardSizeX;
        int boardSizeY;
        int score;


    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        
        bool getExitFlagStatus();
        bool getLoseFlagStatus();
        int getBoardSizeX();
        int getBoardSizeY();
        int getScore();
        char getInput();
        int getSuperFoodFlag();

        void setExitTrue();
        void setLoseFlagTrue();
        void setInput(char this_input);
        void setSuperFoodTrue();
        void setSuperFoodFalse();
        void clearInput();

        void incrementScore();
        void incrementSuperScore();
};

#endif