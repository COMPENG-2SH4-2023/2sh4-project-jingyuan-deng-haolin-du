#include "objPosArrayList.h"

// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.

objPosArrayList::objPosArrayList()
{
	arrayCapactiy = ARRAY_MAX_CAP;
	list = new objPos[arrayCapactiy];
	listSize = 0;
}

objPosArrayList::~objPosArrayList()
{
	delete[] list;
}

void objPosArrayList::insertHead(objPos thisPos)
{
	if (listSize >= arrayCapactiy) {
		arrayCapactiy += ARRAY_MAX_CAP;
		objPos* tmp = new objPos[arrayCapactiy];
		for (int i = 0; i < listSize; i++) {
			tmp[i] = list[i];
		}
		delete[] list;
		list = tmp;
	}

	for (int i = listSize; i > 0; i--)
	{
		list[i] = list[i - 1];
	}
	list[0] = thisPos;
	listSize += 1;
}

void objPosArrayList::insertTail(objPos thisPos)
{
	if (listSize >= arrayCapactiy) {
		arrayCapactiy += ARRAY_MAX_CAP;
		objPos* tmp = new objPos[arrayCapactiy];
		for (int i = 0; i < listSize; i++) {
			tmp[i] = list[i];
		}
		delete[] list;
		list = tmp;
	}
	list[listSize++] = thisPos;
}

void objPosArrayList::removeHead()
{
	if (listSize < 1) {
		return;
	}
	listSize -= 1;
	for (int i = 0; i < listSize; i++)
	{
		list[i] = list[i + 1];
	}
}

void objPosArrayList::removeTail()
{
	if (listSize < 1) {
		return;
	}
	listSize -= 1;
}

int objPosArrayList::getSize()
{
	return listSize;
}

void objPosArrayList::getHeadElement(objPos& returnPos)
{
	if (listSize < 1) {
		return;
	}
	returnPos = list[0];
}

void objPosArrayList::getTailElement(objPos& returnPos)
{
	if (listSize < 1) {
		return;
	}
	returnPos = list[listSize - 1];
}

void objPosArrayList::getElement(objPos& returnPos, int index)
{
	if (index < 0 || index >= listSize) {
		return;
	}
	returnPos = list[index];
}
