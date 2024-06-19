#include "Food.h"

Food::Food(GameMechs* thisGMRef)  //constructor for the food class.
{
    
    mainGameMechsRef = thisGMRef;  // initialize the food postion outside the game board.
    foodBucket = new objPosArrayList();// Create a new object position array list for the food bucket

}

Food::~Food()
{
    delete foodBucket; //Destructor for the Food class
    //and clean up the allocated memory for the food buck.
}

void Food::generateFood(objPosArrayList* blockOff)// Method to generate food positions on the game board
{
    srand(time(NULL));// Seed the random number generator with the current time

    int xCandidate = 0; // Candidate x-coordinate for food position             
    int yCandidate = 0;// Candidate y-coordinate for food position
    int foodCount = 0; // Counter for the number of food items generated                   
    bool isPos;       //To check the condition that if coordinates is generated or no.
    objPos playerBody; // Object to hold the snake's body position
    objPos tempFood;// Temporary object to hold the generated food position

    foodBucket->emptyList(); //"Empty the List" so the foodBucket can overwrite the old food objs with new food objs

    while(foodCount < NUM_FOOD) //Keep generating coordinates until each food item has a unique coordinate
    {
        isPos = false;
        while(isPos == false)      // Check if the randomly generated coordinates are valid (not the same as snake body                                          
        {
            xCandidate = rand() % (mainGameMechsRef->getBoardSizeX() - 2) + 1;  // Generate random coordinates within the game board boundaries
            yCandidate = rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1;
            
            if(foodCount == (NUM_FOOD - 1))      // Make the last food object a Super Food
            {
                tempFood.setObjPos(xCandidate, yCandidate, '@');}  // Set Super Food position
            else
            {
                tempFood.setObjPos(xCandidate, yCandidate, 'o');// set the normal food postion .
            }

            for(int i = 0; i < blockOff->getSize(); i++)  //// Check if the generated coordinates overlap with the snake's body                       
            {
                blockOff->getElement(playerBody, i);
                if(tempFood.isPosEqual(&playerBody) == true) // If coordinates overlap with the snake's body
                {
                    isPos = false;    // Generate new set of coordinates                                           
                    break;
                }
                isPos = true;
            }

            if(isPos == true && (isExist(tempFood) == false))  // If coordinates are valid and do not overlap with other food objects
            {
                add(tempFood);     // Add the food object to the bucket                                              
                foodCount++;
            }
        }
    }

}

objPosArrayList* Food::getFoodPos() // Method to get the positions of the food objects
{
    return foodBucket;// Return the food bucket
}

//Adds food object to the bucket
void Food::add(objPos thisObj)
{
    foodBucket->insertTail(thisObj);// Insert the food object at the tail of the list
}

//Check if a food object is already inside the bucket
bool Food::isExist(objPos thisObj)
{
    objPos foodElement;
    for(int i = 0; i < getSize(); i++)  // Iterate through each food object in the bucket
    {
        foodBucket->getElement(foodElement, i);        
        if(thisObj.isPosEqual(&foodElement)) // Compare coordinates with the newly created food object
        {
            return true;
        }
    }
    return false;
}

//Getting size of the bucket
int Food::getSize()
{
    return foodBucket->getSize();
}
