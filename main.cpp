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
			printf("[�v�f�̑���]\n1. �v�f�̕\��\n2. �v�f�̑}��\n");
			if (GetSize(&head) > 0)
			{
				printf("3. �v�f�̕ҏW\n4. �v�f�̍폜\n5. �v�f�̕��ёւ�(�I�v�V����)\n");
			}
			printf("\n-------------------------------\n�����I�����Ă�������\n");
			scanf_s("%d", &inputValue);
			selectedControl = inputValue;
			break;

		case 1:
			printf("[�v�f�̕\��]\n1. �v�f�̈ꗗ�\��\n2. ���Ԃ��w�肵�ėv�f��\��\n9. �v�f�I���ɖ߂�\n\n�����I�����Ă�������\n");
			scanf_s("%d", &inputValue);
			switch (inputValue)
			{
			case 1:
				printf("[�v�f�̈ꗗ�\��]\n�v�f�ꗗ: {\n");
				index(&head);
				printf("}\n\n�v�f��: %d\n", GetSize(&head));
				StatingMenu();
				scanf_s("%d", &inputValue);
				if (inputValue == 2)
				{
					selectedControl = 0;
				}
				break;

			case 2:
				printf("[���Ԃ��w�肵�ėv�f��\��]\n�\���������v�f�̏��Ԃ��w�肭�������B\n");
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

			printf("[�v�f�̑}��]\n�v�f��ǉ�����ꏊ���w�肵�Ă��������B\n");
			scanf_s("%d", &itr);
			itr = std::max(0, itr);

			printf("�ǉ�����v�f�̒l����͂��Ă��������B\n");
			scanf_s("%s", val, 64);

			create(getInsertCellAddress(&head, itr), val);
			printf("�v�f\"%s\"��%d�Ԗڂɑ}������܂����B\n", val, itr);
		}
		selectedControl = 0;
		break;

		case 3:
			if (GetSize(&head) > 0)
			{
				int itr;
				char val[64];

				printf("[�v�f�̕ҏW]\n�ҏW�������v�f�̔ԍ����w�肵�Ă��������B\n");
				scanf_s("%d", &itr);
				itr = std::max(0, itr);
				if (GetSize(&head) > itr)
				{
					printf("%d�Ԗڂ̗v�f�̕ύX����l����͂��Ă��������B\n", itr);
					scanf_s("%s", val, 64);

					replace(getInsertCellAddress(&head, itr + 1), val);
					printf("%d�Ԗڂ̗v�f�̒l��\"%s\"�ɕύX����܂����B\n", itr, val);
				}
				else
				{
					printf("%d�Ԗڂ̗v�f��������܂���ł����B\n", itr);
				}
			}
			selectedControl = 0;
			break;

		case 4:
			if (GetSize(&head) > 0)
			{
				int itr;

				printf("[�v�f�̍폜]\n�폜�������v�f�̔ԍ����w�肵�Ă��������B\n");
				scanf_s("%d", &itr);
				itr = std::max(0, itr);
				if (GetSize(&head) > itr)
				{
					erase(getInsertCellAddress(&head, itr + 1));
					printf("%d�Ԗڂ̗v�f���폜���܂����B\n", itr);
				}
				else
				{
					printf("%d�Ԗڂ̗v�f��������܂���ł����B\n", itr);
				}
			}
			selectedControl = 0;
			break;

		case 5:
			if (GetSize(&head) > 0)
			{
				int itr;
				int itr2;

				printf("[�v�f�̕��ёւ�]\n����ւ������̗v�f�̔ԍ����w�肵�Ă��������B\n");
				scanf_s("%d", &itr);
				itr = std::max(0, itr);
				if (GetSize(&head) > itr)
				{
					printf("%d�Ԗڂ̗v�f�Ɠ���ւ���v�f�̔ԍ����w�肵�Ă��������B\n", itr);
					scanf_s("%d", &itr2);
					itr2 = std::max(0, itr2);
					if (GetSize(&head) > itr2)
					{
						swap(getInsertCellAddress(&head, itr + 1), getInsertCellAddress(&head, itr2 + 1));
						printf("%d�Ԗڂ̗v�f��%d�Ԗڂ̗v�f�����ւ��܂����B\n", itr, itr2);
					}
					else
					{
						printf("%d�Ԗڂ̗v�f��������܂���ł����B\n", itr2);
					}
				}
				else
				{
					printf("%d�Ԗڂ̗v�f��������܂���ł����B\n", itr);
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
	printf("-------------------------------\n1. �v�f�̕\���ɖ߂�\n2. �v�f�̑���ɖ߂�\n");
}