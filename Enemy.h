#pragma once
class Enemy
{
	enum phaseSet
	{
		combat,
		shoot,
		escape,
	};
private:
	static bool staticDeleteFlag;

private:
	bool deleteFlag = false;
	phaseSet phase;

public:
	void Update();
	void Defeat();
	bool GetDeleteFlag();
	void Combat();
	void Shoot();
	void Escape();

	static void(Enemy::* actionTable[])();
};