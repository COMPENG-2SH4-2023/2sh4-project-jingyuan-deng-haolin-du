#include "objPosArrayList.h"

// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.

objPosArrayList::objPosArrayList()
{
    arrayCapactiy = ARRAY_MAX_CAP; // Set initial capacity to predefined max capacity
    list = new objPos[arrayCapactiy]; // Allocate memory for the array
    listSize = 0; 
}

// Destructor for objPosArrayList
objPosArrayList::~objPosArrayList()
{
    delete[] list; // Deallocate the memory used for the list
}

// Method to insert an element at the head of the list
void objPosArrayList::insertHead(objPos thisPos)
{
    // If list size exceeds current capacity, increase the capacity
    if (listSize >= arrayCapactiy) {
        arrayCapactiy += ARRAY_MAX_CAP;
        objPos* tmp = new objPos[arrayCapactiy];
        for (int i = 0; i < listSize; i++) {
            tmp[i] = list[i];
        }
        delete[] list;
        list = tmp;
    }

    // Shift all elements down and insert the new element at the head
    for (int i = listSize; i > 0; i--)
    {
        list[i] = list[i - 1];
    }
    list[0] = thisPos;
    listSize += 1; // Increment the size of the list
}

// Method to insert an element at the tail of the list
void objPosArrayList::insertTail(objPos thisPos)
{
    // If list size exceeds current capacity, increase the capacity
    if (listSize >= arrayCapactiy) {
        arrayCapactiy += ARRAY_MAX_CAP;
        objPos* tmp = new objPos[arrayCapactiy];
        for (int i = 0; i < listSize; i++) {
            tmp[i] = list[i];
        }
        delete[] list;
        list = tmp;
    }
    list[listSize++] = thisPos; // Add the new element at the tail and increment list size
}

// Method to remove an element from the head of the list
void objPosArrayList::removeHead()
{
    if (listSize < 1) {
        return; // Return if the list is empty
    }
    listSize -= 1; // Decrease the size of the list
    for (int i = 0; i < listSize; i++)
    {
        list[i] = list[i + 1]; // Shift all elements up
    }
}

// Method to remove an element from the tail of the list
void objPosArrayList::removeTail()
{
    if (listSize < 1) {
        return; // Return if the list is empty
    }
    listSize -= 1; // Simply decrease the size to remove the last element
}

// Method to get the size of the list
int objPosArrayList::getSize()
{
    return listSize; // Return the current size of the list
}

// Method to get the head element of the list
void objPosArrayList::getHeadElement(objPos& returnPos)
{
    if (listSize < 1) {
        return; // Return if the list is empty
    }
    returnPos = list[0]; // Set the head element to returnPos
}

// Method to get the tail element of the list
void objPosArrayList::getTailElement(objPos& returnPos)
{
    if (listSize < 1) {
        return; // Return if the list is empty
    }
    returnPos = list[listSize - 1]; // Set the tail element to returnPos
}

// Method to get an element at a specific index
void objPosArrayList::getElement(objPos& returnPos, int index)
{
    if (index < 0 || index >= listSize) {
        return; // Return if the index is out of bounds
    }
    returnPos = list[index]; // Set the element at the specified index to returnPos
}
