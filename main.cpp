#include <vector>
#include <iostream>
#include <string>
#include "Enemy.h"

using namespace std;

int main()
{
	vector<Enemy> enemies = 
	{ Enemy() };

	while (true)
	{
		for (int i = 0; i < enemies.size(); i++)
		{
			if (!enemies[i].GetDeleteFlag())
			{
				enemies[i].Update();
			}
		}

		printf("敵一覧\n{\n");
		for (int i = 0; i < enemies.size(); i++)
		{
			if (!enemies[i].GetDeleteFlag())
			{
				printf(" 敵%d\n", i);
			}
		}
		printf("}\n\n");

		string getSelect;
		printf("\n[ENTER] : 次のターン\n");

		cin.clear();
		getline(cin, getSelect);
	}

	return 0;
}