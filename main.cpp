#include <vector>
#include <stdio.h>
#include "Enemy.h"

using namespace std;

int main()
{
	vector<Enemy> enemies = 
	{ Enemy(),Enemy(),Enemy(),Enemy(),Enemy() };

	while (true)
	{
		for (int i = 0; i < enemies.size(); i++)
		{
			enemies[i].Update();
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

		printf("倒したい敵の番号を入力してください\n");

		int target = 0;
		scanf_s("%d", &target);

		if (target >= 0 && target < enemies.size())
		{
			enemies[target].Defeat();
			printf("\n敵%dを倒しました\n\n", target);
		}
		else
		{
			printf("\n敵%dが見つかりませんでした\n\n", target);
		}
	}

	return 0;
}