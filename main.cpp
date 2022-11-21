#include <Windows.h>
#include <stdio.h>
#include "SceneManager.h"

int main()
{
	while (true)
	{
		Sleep(1000);
		SceneManager::GetInstance()->ChangeScene((SceneManager::GetInstance()->GetScene() + 1) % 4);
		printf("SceneNo: %d\n", SceneManager::GetInstance()->GetScene());
	}

	return 0;
}