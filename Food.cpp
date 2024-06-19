#include "Food.h"

Food::Food(GameMechs *thisGMRef) // constructor for the food class.
{
    mainGameMechsRef = thisGMRef;
    foodBin = new objPosArrayList(); // objPosArrayList for the food bucket on the heap
}

Food::~Food()
{
    delete foodBin;
}

void Food::generateFood(objPosArrayList *blockOff)
{
    srand(time(NULL)); // Seed rng with time

    int randX = 0;     // x position of food
    int randY = 0;     // y position of food
    int countFood = 0; // food counter

    bool valid; // checks if position is valid

    objPos playerBody; // holds snake's body inside obj
    objPos tempFood;   // holds food pos inside obj

    foodBin->emptyList();

    while (countFood < FOOD) // Loop until wanted food size is generated
    {
        bool valid = false;
        while (valid == false)
        {
            randX = rand() % (mainGameMechsRef->getBoardSizeX() - 2) + 1; // Generate random coordinates within the game board boundaries
            randY = rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1;

            if (countFood == (FOOD - 1))
            {
                tempFood.setObjPos(randX, randY, '@');
            }
            else
            {
                tempFood.setObjPos(randX, randY, 'o');
            }
            // Check if the generated coordinates overlap with the snake's body
            for (int i = 0; i < blockOff->getSize(); i++)
            {
                objPos playerBody;
                blockOff->getElement(playerBody, i);
                if (tempFood.isPosEqual(&playerBody))
                {
                    valid = false; // If coordinates overlap with the snake's body, generate new set of coordinates
                    break;
                }
                valid = true;
            }

            // Check if the generated coordinates overlap with existing food positions
            if (valid)
            {
                for (int i = 0; i < foodBin->getSize(); i++)
                {
                    objPos foodElement;
                    foodBin->getElement(foodElement, i);
                    if (tempFood.isPosEqual(&foodElement))
                    {
                        valid = false; // If coordinates overlap with existing food, generate new set of coordinates
                        break;
                    }
                }
            }

            // If coordinates are valid and do not overlap with other objects
            if (valid)
            {
                foodBin->insertTail(tempFood); // Add the food object to the bucket
                countFood++;
            }
        }
    }
}

objPosArrayList *Food::getFoodPos()
{
    return foodBin;
}
