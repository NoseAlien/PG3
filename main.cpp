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

		printf("“Gˆê——\n{\n");
		for (int i = 0; i < enemies.size(); i++)
		{
			if (!enemies[i].GetDeleteFlag())
			{
				printf(" “G%d\n", i);
			}
		}
		printf("}\n\n");

		printf("“|‚µ‚½‚¢“G‚Ì”Ô†‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");

		int target = 0;
		scanf_s("%d", &target);

		if (target >= 0 && target < enemies.size())
		{
			enemies[target].Defeat();
			printf("\n“G%d‚ð“|‚µ‚Ü‚µ‚½\n\n", target);
		}
		else
		{
			printf("\n“G%d‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½\n\n", target);
		}
	}

	return 0;
}