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

void create(CELL* begin, rentalInfo val);
void index(CELL* begin);
void indexBack(CELL* begin);

int main()
{
	CELL head;
	head.prev = nullptr;
	head.next = nullptr;

	create(&head, { "“m–Ø",20220222,20220223 });
	create(&head, { "ƒƒOƒŠ",20220406,20220407 });
	create(&head, { "‚Õ‚èƒOƒŠ",20220807,20220808 });
	create(&head, { "‚È‚Õ‚è",20220906,20220907 });

	index(&head);

	indexBack(&head);

	return 0;
}

void create(CELL* begin, rentalInfo val)
{
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));

	strcpy_s(newCell->val.name, 64, val.name);
	newCell->val = val;
	newCell->prev = nullptr;
	newCell->next = nullptr;

	CELL* targetCell = begin;

	while (targetCell->next != nullptr)
	{
		targetCell = targetCell->next;
	}

	targetCell->next = newCell;
	newCell->prev = targetCell;
}

void index(CELL* begin)
{
	CELL* targetCell = begin;

	while (targetCell->next != nullptr)
	{
		targetCell = targetCell->next;
		printf("%s\n%d\n%d\n\n",targetCell->val.name, targetCell->val.rentDate, targetCell->val.returnDate);
	}
}

void indexBack(CELL* begin)
{
	CELL* targetCell = begin;

	while (targetCell->next != nullptr)
	{
		targetCell = targetCell->next;
	}

	while (targetCell->prev != nullptr)
	{
		printf("%s\n%d\n%d\n\n", targetCell->val.name, targetCell->val.rentDate, targetCell->val.returnDate);
		targetCell = targetCell->prev;
	}
}