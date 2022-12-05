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

		printf("�G�ꗗ\n{\n");
		for (int i = 0; i < enemies.size(); i++)
		{
			if (!enemies[i].GetDeleteFlag())
			{
				printf(" �G%d\n", i);
			}
		}
		printf("}\n\n");

		printf("�|�������G�̔ԍ�����͂��Ă�������\n");

		int target = 0;
		scanf_s("%d", &target);

		if (target >= 0 && target < enemies.size())
		{
			enemies[target].Defeat();
			printf("\n�G%d��|���܂���\n\n", target);
		}
		else
		{
			printf("\n�G%d��������܂���ł���\n\n", target);
		}
	}

	return 0;
}