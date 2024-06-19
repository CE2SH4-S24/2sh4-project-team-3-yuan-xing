#include "Player.h"

 
Player::Player(GameMechs* thisGMRef, Food* thisFoodRef)
{
    mainGameMechsRef = thisGMRef;
    mainFoodRef = thisFoodRef;  
    myDir = STOP;
    
    // more actions to be included
    // initialize player to middle of x and y coord and gives player the char '*'
    
    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, 
                    mainGameMechsRef->getBoardSizeY()/2, '*');


    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);
   

}


Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos()
{
    // return the reference to the playerPos arrray list
    return playerPosList;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic    
    //uses getInput() referenced from gameMechs to get input.
    char input = mainGameMechsRef->getInput();

    switch(input)
    {
        case 'w':
            if(myDir != UP && myDir != DOWN)    //  If my direction is not up and down
                myDir = UP;     //  my direction is up
            break;

        case 'a':
            if(myDir != LEFT && myDir != RIGHT)     //  If my direction is not left and right
                myDir = LEFT;       //  my direction is left
            break;

        case 's':
            if(myDir != UP && myDir != DOWN)    //  If my direction is not left and right
                myDir = DOWN;       //  my direction is down
            break;

        case 'd':
            if(myDir != LEFT && myDir != RIGHT)     //  If my direction is not left and right
                myDir = RIGHT;      //  my direction is right
            break;

        default:        // default case for switch
            break;      
    }    
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic

    objPos currentHead;
    playerPosList->getHeadElement(currentHead);

    switch(myDir)
    {
        case UP:        
            if(currentHead.y==1)      // if position y of player is 1(top border)
                                                                     //(board size - 2 to account for the borders)
                currentHead.y=mainGameMechsRef->getBoardSizeY()-2;    // set player to boardsize of Y - 2(bottom border) 
            else
                currentHead.y--;  // player movement in y will decrement therefore moving the player up
            break;

        case LEFT:
            if(currentHead.x==1)      // if position x of player is 1(top border)
                currentHead.x=mainGameMechsRef->getBoardSizeX()-2;        // set player to boardsize of X - 2(right border) 
            else
                currentHead.x--;      // player movement in x will decrement therefore moving the player left
            break;

        case DOWN:
            if(currentHead.y==mainGameMechsRef->getBoardSizeY()-2)        // if position y of player is boardsize of Y - 2(bottom border)
                currentHead.y=1;      // set player to 1 in y (bottom border)
            else
                currentHead.y++;      // player movement in y will increment therefore moving the player down
            break;

        case RIGHT:
            if(currentHead.x==mainGameMechsRef->getBoardSizeX()-2)        // if position x of player is boardsize of X - 2(right border)
                currentHead.x=1;      // set player to 1 in x (left border)
            else
                currentHead.x++;      // player movement in x will increment therefore moving the player right
            break;

        default:
            break;
    }
    
    // current head is inserted and moved to the head of list
    playerPosList->insertHead(currentHead);

    objPos foodElement;
    objPosArrayList* foodBin;
    objPos playerElement;
        
    foodBin = mainFoodRef->getFoodPos();

    bool collide = false;
    bool foodCollide = false;
    int bodyIndex;
    // check if new head position collides with food
    for (int i = 0; i < foodBin->getSize(); i++)
    {
        foodBin->getElement(foodElement, i);
        if (currentHead.isPosEqual(&foodElement))
        {
            foodCollide = true;
            playerPosList->insertHead(currentHead); 
            break;
        }
    }
    
    // if yes, incrememnt score in GM, generate NEW FOOD and do not remove tail
    // otherwise, remove tail and carry on
    if (foodCollide)
    {
        mainGameMechsRef->incrementScore();
        mainFoodRef->generateFood(playerPosList);
    }
    else
    {
        // current player position list
        

        // self collision check
        for (int j = 1; j < playerPosList->getSize(); j++)
        {
            playerPosList->getElement(playerElement, j+1);
            if (currentHead.isPosEqual(&playerElement))
            {
                collide = true;
            }
        }
        // if self hit, set lose and exit flag to true using myGM
        if (collide == true)
        {
            mainGameMechsRef->setLoseFlagTrue();
            mainGameMechsRef->setExitTrue();

        }
    }
    

        
    // end game, need to differentiate, end game state
    // LOST -display lost msg
    // otherwise display endgame message only

    // tail is then removed
    playerPosList->removeTail();
    
}

