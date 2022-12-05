#pragma once
class Enemy
{
private:
	static bool staticDeleteFlag;

private:
	bool deleteFlag = false;

public:
	void Update();
	void Defeat();
	bool GetDeleteFlag();
};