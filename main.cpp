#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct rentalInfo
{
	char name[64];
	int rentDate;
	int returnDate;
};

typedef struct cell
{
	rentalInfo val;
	struct cell* prev;
	struct cell* next;
}CELL;

CELL* getInsertCellAddress(CELL* endCELL, int iterator);
void create(CELL* begin, rentalInfo val);
void index(CELL* begin);

int main()
{
	CELL head;
	head.prev = nullptr;
	head.next = nullptr;

	create(&head, { "杜木",20220222,20220223 });
	create(&head, { "メグリ",20220406,20220407 });
	create(&head, { "ぷりグリ",20220807,20220808 });
	create(&head, { "なぷり",20220906,20220907 });

	index(&head);

	return 0;
}

CELL* getInsertCellAddress(CELL* endCELL, int iterator)
{
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

void create(CELL* currentCell, rentalInfo val)
{
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));

	strcpy_s(newCell->val.name, 64, val.name);
	newCell->val = val;
	newCell->prev = currentCell;
	newCell->next = currentCell->next;

	if (currentCell->next)
	{
		CELL* nextCell = currentCell->next;
		nextCell->prev = newCell;
	}

	currentCell->next = newCell;
}

void index(CELL* endCell)
{
	int no = 1;
	while (endCell->next != nullptr)
	{
		endCell = endCell->next;
		printf("%s\n%d\n%d\n\n", endCell->val.name, endCell->val.rentDate, endCell->val.returnDate);
		no++;
	}
}