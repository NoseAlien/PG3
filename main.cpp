#include <stdio.h>
#include <iostream>
#include <string>
#include "List.h"

using namespace std;

int main()
{
	int inputValue;

	int selectedControl = 0;

	List list = {};

	while (true)
	{
		switch (selectedControl)
		{
		default:
			printf("\n[�v�f�̑���]\n1. �v�f�̕\��\n2. �v�f�̑}��\n");
			if (list.GetSize() > 0)
			{
				printf("3. �v�f�̕ҏW\n4. �v�f�̍폜\n5. �v�f�̕��ёւ�(�I�v�V����)\n");
			}
			printf("\n-------------------------------\n�����I�����Ă�������\n");
			scanf_s("%d", &inputValue);
			selectedControl = inputValue;
			break;

		case 1:
			printf("\n[�v�f�̕\��]\n1. �v�f�̈ꗗ�\��\n2. ���Ԃ��w�肵�ėv�f��\��\n9. �v�f�I���ɖ߂�\n\n�����I�����Ă�������\n");
			scanf_s("%d", &inputValue);
			switch (inputValue)
			{
			case 1:
				printf("\n[�v�f�̈ꗗ�\��]\n�v�f�ꗗ: {\n");
				list.Index();
				printf("}\n\n�v�f��: %d\n", list.GetSize());
				printf("-------------------------------\n1. �v�f�̕\���ɖ߂�\n2. �v�f�̑���ɖ߂�\n");
				scanf_s("%d", &inputValue);
				if (inputValue == 2)
				{
					selectedControl = 0;
				}
				break;

			case 2:
				printf("\n[���Ԃ��w�肵�ėv�f��\��]\n�\���������v�f�̏��Ԃ��w�肭�������B\n");
				scanf_s("%d", &inputValue);

				if (list.GetSize() > inputValue && inputValue >= 0)
				{
					printf("\n%d: %s\n\n", inputValue, list.GetInsertCellAddress(inputValue + 1)->val);
				}
				else
				{
					printf("\n%d�Ԗڂ̗v�f��������܂���ł����B\n", inputValue);
				}
				printf("-------------------------------\n1. �v�f�̕\���ɖ߂�\n2. �v�f�̑���ɖ߂�\n");
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

			string getSelect;
			printf("\n[�v�f�̑}��]\n�v�f��ǉ�����ꏊ���w�肵�Ă��������B�Ō���ɒǉ�����ꍇ�͉������͂��Ȃ��ł��������B\n");

			cin.clear();
			cin.ignore(1024, '\n');
			getline(cin, getSelect);

			if (getSelect == "")
			{
				itr = list.GetSize();
			}
			else
			{
				itr = stoi(getSelect);
			}

			itr = max(min(itr, list.GetSize()), 0);

			printf("\n�ǉ�����v�f�̒l����͂��Ă��������B\n");
			scanf_s("%s", val, 64);

			List::create(list.GetInsertCellAddress(itr), val);
			printf("\n�v�f\"%s\"��%d�Ԗڂɑ}������܂����B\n", val, itr);
		}
		selectedControl = 0;
		break;

		case 3:
			if (list.GetSize() > 0)
			{
				int itr;
				char val[64];

				printf("\n[�v�f�̕ҏW]\n�ҏW�������v�f�̔ԍ����w�肵�Ă��������B\n");
				scanf_s("%d", &itr);
				itr = max(0, itr);
				if (list.GetSize() > itr)
				{
					printf("\n%d�Ԗڂ̗v�f�̕ύX����l����͂��Ă��������B\n", itr);
					scanf_s("%s", val, 64);

					List::replace(list.GetInsertCellAddress(itr + 1), val);
					printf("\n%d�Ԗڂ̗v�f�̒l��\"%s\"�ɕύX����܂����B\n", itr, val);
				}
				else
				{
					printf("\n%d�Ԗڂ̗v�f��������܂���ł����B\n", itr);
				}
			}
			selectedControl = 0;
			break;

		case 4:
			if (list.GetSize() > 0)
			{
				int itr;

				printf("\n[�v�f�̍폜]\n�폜�������v�f�̔ԍ����w�肵�Ă��������B\n");
				scanf_s("%d", &itr);
				itr = max(0, itr);
				if (list.GetSize() > itr)
				{
					List::erase(list.GetInsertCellAddress(itr + 1));
					printf("\n%d�Ԗڂ̗v�f���폜���܂����B\n", itr);
				}
				else
				{
					printf("\n%d�Ԗڂ̗v�f��������܂���ł����B\n", itr);
				}
			}
			selectedControl = 0;
			break;

		case 5:
			if (list.GetSize() > 0)
			{
				int itr;
				int itr2;

				printf("\n[�v�f�̕��ёւ�]\n����ւ������̗v�f�̔ԍ����w�肵�Ă��������B\n");
				scanf_s("%d", &itr);
				itr = max(0, itr);
				if (list.GetSize() > itr)
				{
					printf("\n%d�Ԗڂ̗v�f�Ɠ���ւ���v�f�̔ԍ����w�肵�Ă��������B\n", itr);
					scanf_s("%d", &itr2);
					itr2 = max(0, itr2);
					if (list.GetSize() > itr2)
					{
						List::swap(list.GetInsertCellAddress(itr + 1), list.GetInsertCellAddress(itr2 + 1));
						printf("\n%d�Ԗڂ̗v�f��%d�Ԗڂ̗v�f�����ւ��܂����B\n", itr, itr2);
					}
					else
					{
						printf("\n%d�Ԗڂ̗v�f��������܂���ł����B\n", itr2);
					}
				}
				else
				{
					printf("\n%d�Ԗڂ̗v�f��������܂���ł����B\n", itr);
				}
			}
			selectedControl = 0;
			break;
		}
	}

	return 0;
}