#include "objPosArrayList.h" 

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()            // constructor
{
    aList  = new objPos[ARRAY_MAX_CAP];
    sizeList = 0;
    sizeArray = ARRAY_MAX_CAP;

}

objPosArrayList::~objPosArrayList()           // destructor
{
    delete[] aList;
}


//Getter method
int objPosArrayList::getSize()                // returns the size of list
{
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos)    
{
    for(int i=sizeList; i>0; i--)            // starts from tail(last element) and decrements to each element
    {
        aList[i].setObjPos(aList[i-1]);      // shift elements 1 index one over
    }
    aList[0].setObjPos(thisPos);             //  inserts the head at front of the arraylist 
    sizeList++;                              // increment list size to account for new element
}

void objPosArrayList::insertTail(objPos thisPos)
{
   aList[sizeList].setObjPos(thisPos);       // no need to shift list just insert Tail at last element
   sizeList++;                               // increment list size to account for new element
}

void objPosArrayList::removeHead()
{
    for (int i = 0; i < sizeList - 1; i++)   // loops through element in size list (-1 due to arrays are 0 indexed)
    {
        aList[i].setObjPos(aList[i + 1]);    // shifts elements to the left towards index 0 replacing each previous index
    }

    sizeList--;                              // decrement size list to account for element removed
}

void objPosArrayList::removeTail()
{
    sizeList--;                              // just decrement size list to remove tail
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);           // return element 0 which is the head
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[sizeList-1]);  // return last element which is the tail (sizeList-1  because arrays are 0 indexed)
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index]);       // returns the element at the index of the array
}

void objPosArrayList::emptyList()
{
    sizeList = 0;
}