#ifndef FOOD_H
#define FOOD_H
#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"
#include "MacUILib.h"

#define FOOD 1

class Food
{
    private:

        objPosArrayList* foodBin;
        GameMechs* mainGameMechsRef;

    public:

        // constructor
        Food(GameMechs* thisGMRef);

        // deconstructor
        ~Food();


        void generateFood(objPosArrayList* blockOff);
        objPosArrayList* getFoodPos();
        
        
};



#endif