#include "Enemy.h"
#include <stdio.h>

bool Enemy::staticDeleteFlag = false;

void Enemy::Update()
{
	if (staticDeleteFlag)
	{
		deleteFlag = true;
	}

	(this->*actionTable[static_cast<size_t>(phase)])();
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

void(Enemy::* Enemy::actionTable[])()
{
	&Enemy::Combat,
	&Enemy::Shoot,
	&Enemy::Escape
};

void Enemy::Combat()
{
	printf("�G���ߐڍU�������ė����I\n");
}

void Enemy::Shoot()
{
	printf("�G���e���������I\n");
}

void Enemy::Escape()
{
	printf("�G���������I\n");
}