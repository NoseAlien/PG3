#include "SceneManager.h"

SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{

}


SceneManager* SceneManager::GetInstance()
{
	static SceneManager instance;
	return &instance;
}

void SceneManager::ChangeScene(int sceneNo)
{
	this->sceneNo = sceneNo;
}

int SceneManager::GetScene()
{
	return sceneNo;

}