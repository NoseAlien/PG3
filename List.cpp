#include "List.h"

List::List()
{
	head.prev = nullptr;
	head.next = nullptr;
}

void List::create(CELL* currentCell, char val[64])
{
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));

	strcpy_s(newCell->val, 64, val);
	newCell->prev = currentCell;
	newCell->next = currentCell->next;

	if (currentCell->next)
	{
		CELL* nextCell = currentCell->next;
		nextCell->prev = newCell;
	}

	currentCell->next = newCell;
}

void List::erase(CELL* currentCell)
{
	CELL* prevCell = currentCell->prev;
	prevCell->next = currentCell->next;

	if (currentCell->next)
	{
		CELL* nextCell = currentCell->next;
		nextCell->prev = currentCell->prev;
	}

	delete currentCell;
}

void List::replace(CELL* currentCell, char val[64])
{
	strcpy_s(currentCell->val, 64, val);
}

void List::swap(CELL* CellA, CELL* CellB)
{
	char swapVal[64];
	strcpy_s(swapVal, 64, CellA->val);
	strcpy_s(CellA->val, 64, CellB->val);
	strcpy_s(CellB->val, 64, swapVal);
}

CELL* List::GetInsertCellAddress(int iterator)
{
	CELL* endCELL = &head;

	for (int i = 0; i < iterator; i++)
	{
		if (endCELL->next)
		{
			endCELL = endCELL->next;
		}
		else
		{
			break;
		}
	}
	return endCELL;
}

void List::Index()
{
	CELL* endCELL = &head;
	int no = 0;
	while (endCELL->next != nullptr)
	{
		endCELL = endCELL->next;
		printf(" %d: %s\n", no, endCELL->val);
		no++;
	}
}

int List::GetSize()
{
	CELL* endCELL = &head;
	int no = 0;
	while (endCELL->next != nullptr)
	{
		endCELL = endCELL->next;
		no++;
	}

	return no;
}