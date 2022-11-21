#pragma once

class SceneManager final
{
private:
	int sceneNo = 0;

private:
	SceneManager();
	~SceneManager();

public:
	SceneManager(const SceneManager& obj) = delete;
	SceneManager& operator=(const SceneManager& obj) = delete;

public:
	static SceneManager* GetInstance();

public:
	void ChangeScene(int sceneNo);
	int GetScene();
};