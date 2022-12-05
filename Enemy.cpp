#include "Enemy.h"

bool Enemy::staticDeleteFlag = false;

void Enemy::Update()
{
	if (staticDeleteFlag)
	{
		deleteFlag = true;
	}
}

void Enemy::Defeat()
{
	deleteFlag = true;
	staticDeleteFlag = true;
}

bool Enemy::GetDeleteFlag()
{
	return deleteFlag;
}