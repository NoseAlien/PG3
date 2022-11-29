#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

typedef struct cell
{
	char val[64];
	struct cell* prev;
	struct cell* next;
}CELL;

CELL* getInsertCellAddress(CELL* endCELL, int iterator);
void create(CELL* begin, char val[64]);
void erase(CELL* currentCell);
void replace(CELL* currentCell, char val[64]);
void swap(CELL* CellA, CELL* CellB);
void index(CELL* begin);
int GetSize(CELL* endCell);
void StatingMenu();

int main()
{
	int inputValue;

	int selectedControl = 0;

	CELL head;
	head.prev = nullptr;
	head.next = nullptr;

	while (true)
	{
		switch (selectedControl)
		{
		default:
			printf("[要素の操作]\n1. 要素の表示\n2. 要素の挿入\n");
			if (GetSize(&head) > 0)
			{
				printf("3. 要素の編集\n4. 要素の削除\n5. 要素の並び替え(オプション)\n");
			}
			printf("\n-------------------------------\n操作を選択してください\n");
			scanf_s("%d", &inputValue);
			selectedControl = inputValue;
			break;

		case 1:
			printf("[要素の表示]\n1. 要素の一覧表示\n2. 順番を指定して要素を表示\n9. 要素選択に戻る\n\n操作を選択してください\n");
			scanf_s("%d", &inputValue);
			switch (inputValue)
			{
			case 1:
				printf("[要素の一覧表示]\n要素一覧: {\n");
				index(&head);
				printf("}\n\n要素数: %d\n", GetSize(&head));
				StatingMenu();
				scanf_s("%d", &inputValue);
				if (inputValue == 2)
				{
					selectedControl = 0;
				}
				break;

			case 2:
				printf("[順番を指定して要素を表示]\n表示したい要素の順番を指定ください。\n");
				scanf_s("%d", &inputValue);

				inputValue = std::max(std::min(inputValue, GetSize(&head) - 1), 0);
				printf("%d: %s\n\n", inputValue, getInsertCellAddress(&head, inputValue + 1)->val);
				StatingMenu();
				scanf_s("%d", &inputValue);
				if (inputValue == 2)
				{
					selectedControl = 0;
				}
				break;

			case 9:
				selectedControl = 0;
			}
			break;

		case 2:
		{
			int itr;
			char val[64];

			printf("[要素の挿入]\n要素を追加する場所を指定してください。\n");
			scanf_s("%d", &itr);
			itr = std::max(0, itr);

			printf("追加する要素の値を入力してください。\n");
			scanf_s("%s", val, 64);

			create(getInsertCellAddress(&head, itr), val);
			printf("要素\"%s\"が%d番目に挿入されました。\n", val, itr);
		}
		selectedControl = 0;
		break;

		case 3:
			if (GetSize(&head) > 0)
			{
				int itr;
				char val[64];

				printf("[要素の編集]\n編集したい要素の番号を指定してください。\n");
				scanf_s("%d", &itr);
				itr = std::max(0, itr);
				if (GetSize(&head) > itr)
				{
					printf("%d番目の要素の変更する値を入力してください。\n", itr);
					scanf_s("%s", val, 64);

					replace(getInsertCellAddress(&head, itr + 1), val);
					printf("%d番目の要素の値が\"%s\"に変更されました。\n", itr, val);
				}
				else
				{
					printf("%d番目の要素が見つかりませんでした。\n", itr);
				}
			}
			selectedControl = 0;
			break;

		case 4:
			if (GetSize(&head) > 0)
			{
				int itr;

				printf("[要素の削除]\n削除したい要素の番号を指定してください。\n");
				scanf_s("%d", &itr);
				itr = std::max(0, itr);
				if (GetSize(&head) > itr)
				{
					erase(getInsertCellAddress(&head, itr + 1));
					printf("%d番目の要素を削除しました。\n", itr);
				}
				else
				{
					printf("%d番目の要素が見つかりませんでした。\n", itr);
				}
			}
			selectedControl = 0;
			break;

		case 5:
			if (GetSize(&head) > 0)
			{
				int itr;
				int itr2;

				printf("[要素の並び替え]\n入れ替える一方の要素の番号を指定してください。\n");
				scanf_s("%d", &itr);
				itr = std::max(0, itr);
				if (GetSize(&head) > itr)
				{
					printf("%d番目の要素と入れ替える要素の番号を指定してください。\n", itr);
					scanf_s("%d", &itr2);
					itr2 = std::max(0, itr2);
					if (GetSize(&head) > itr2)
					{
						swap(getInsertCellAddress(&head, itr + 1), getInsertCellAddress(&head, itr2 + 1));
						printf("%d番目の要素と%d番目の要素を入れ替えました。\n", itr, itr2);
					}
					else
					{
						printf("%d番目の要素が見つかりませんでした。\n", itr2);
					}
				}
				else
				{
					printf("%d番目の要素が見つかりませんでした。\n", itr);
				}
			}
			selectedControl = 0;
			break;
		}
	}

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

void create(CELL* currentCell, char val[64])
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

void erase(CELL* currentCell)
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

void replace(CELL* currentCell, char val[64])
{
	strcpy_s(currentCell->val, 64, val);
}

void swap(CELL* CellA, CELL* CellB)
{
	char swapVal[64];
	strcpy_s(swapVal, 64, CellA->val);
	strcpy_s(CellA->val, 64, CellB->val);
	strcpy_s(CellB->val, 64, swapVal);
}

void index(CELL* endCell)
{
	int no = 0;
	while (endCell->next != nullptr)
	{
		endCell = endCell->next;
		printf(" %d: %s\n",no , endCell->val);
		no++;
	}
}

int GetSize(CELL* endCell)
{
	int no = 0;
	while (endCell->next != nullptr)
	{
		endCell = endCell->next;
		no++;
	}

	return no;
}

void StatingMenu()
{
	printf("-------------------------------\n1. 要素の表示に戻る\n2. 要素の操作に戻る\n");
}