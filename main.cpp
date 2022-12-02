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
			printf("\n[要素の操作]\n1. 要素の表示\n2. 要素の挿入\n");
			if (list.GetSize() > 0)
			{
				printf("3. 要素の編集\n4. 要素の削除\n5. 要素の並び替え(オプション)\n");
			}
			printf("\n-------------------------------\n操作を選択してください\n");
			scanf_s("%d", &inputValue);
			selectedControl = inputValue;
			break;

		case 1:
			printf("\n[要素の表示]\n1. 要素の一覧表示\n2. 順番を指定して要素を表示\n9. 要素選択に戻る\n\n操作を選択してください\n");
			scanf_s("%d", &inputValue);
			switch (inputValue)
			{
			case 1:
				printf("\n[要素の一覧表示]\n要素一覧: {\n");
				list.Index();
				printf("}\n\n要素数: %d\n", list.GetSize());
				printf("-------------------------------\n1. 要素の表示に戻る\n2. 要素の操作に戻る\n");
				scanf_s("%d", &inputValue);
				if (inputValue == 2)
				{
					selectedControl = 0;
				}
				break;

			case 2:
				printf("\n[順番を指定して要素を表示]\n表示したい要素の順番を指定ください。\n");
				scanf_s("%d", &inputValue);

				if (list.GetSize() > inputValue && inputValue >= 0)
				{
					printf("\n%d: %s\n\n", inputValue, list.GetInsertCellAddress(inputValue + 1)->val);
				}
				else
				{
					printf("\n%d番目の要素が見つかりませんでした。\n", inputValue);
				}
				printf("-------------------------------\n1. 要素の表示に戻る\n2. 要素の操作に戻る\n");
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
			printf("\n[要素の挿入]\n要素を追加する場所を指定してください。最後尾に追加する場合は何も入力しないでください。\n");

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

			printf("\n追加する要素の値を入力してください。\n");
			scanf_s("%s", val, 64);

			List::create(list.GetInsertCellAddress(itr), val);
			printf("\n要素\"%s\"が%d番目に挿入されました。\n", val, itr);
		}
		selectedControl = 0;
		break;

		case 3:
			if (list.GetSize() > 0)
			{
				int itr;
				char val[64];

				printf("\n[要素の編集]\n編集したい要素の番号を指定してください。\n");
				scanf_s("%d", &itr);
				itr = max(0, itr);
				if (list.GetSize() > itr)
				{
					printf("\n%d番目の要素の変更する値を入力してください。\n", itr);
					scanf_s("%s", val, 64);

					List::replace(list.GetInsertCellAddress(itr + 1), val);
					printf("\n%d番目の要素の値が\"%s\"に変更されました。\n", itr, val);
				}
				else
				{
					printf("\n%d番目の要素が見つかりませんでした。\n", itr);
				}
			}
			selectedControl = 0;
			break;

		case 4:
			if (list.GetSize() > 0)
			{
				int itr;

				printf("\n[要素の削除]\n削除したい要素の番号を指定してください。\n");
				scanf_s("%d", &itr);
				itr = max(0, itr);
				if (list.GetSize() > itr)
				{
					List::erase(list.GetInsertCellAddress(itr + 1));
					printf("\n%d番目の要素を削除しました。\n", itr);
				}
				else
				{
					printf("\n%d番目の要素が見つかりませんでした。\n", itr);
				}
			}
			selectedControl = 0;
			break;

		case 5:
			if (list.GetSize() > 0)
			{
				int itr;
				int itr2;

				printf("\n[要素の並び替え]\n入れ替える一方の要素の番号を指定してください。\n");
				scanf_s("%d", &itr);
				itr = max(0, itr);
				if (list.GetSize() > itr)
				{
					printf("\n%d番目の要素と入れ替える要素の番号を指定してください。\n", itr);
					scanf_s("%d", &itr2);
					itr2 = max(0, itr2);
					if (list.GetSize() > itr2)
					{
						List::swap(list.GetInsertCellAddress(itr + 1), list.GetInsertCellAddress(itr2 + 1));
						printf("\n%d番目の要素と%d番目の要素を入れ替えました。\n", itr, itr2);
					}
					else
					{
						printf("\n%d番目の要素が見つかりませんでした。\n", itr2);
					}
				}
				else
				{
					printf("\n%d番目の要素が見つかりませんでした。\n", itr);
				}
			}
			selectedControl = 0;
			break;
		}
	}

	return 0;
}