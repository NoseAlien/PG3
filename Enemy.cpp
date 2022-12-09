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
	printf("“G‚ª‹ßÚUŒ‚‚ğ‚µ‚Ä—ˆ‚½I\n");
}

void Enemy::Shoot()
{
	printf("“G‚ªe‚ğŒ‚‚Á‚½I\n");
}

void Enemy::Escape()
{
	printf("“G‚ª“¦‚°‚½I\n");
}