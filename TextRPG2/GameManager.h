#pragma once
#include "Character.h"
#include "IMonster.h"
#include <string>
#include <vector>

using namespace std;

class GameManager
{
private:
	static GameManager* Instance;

public:
	static GameManager* GetInstance();

	IMonster* GenerateMonster(int level);

	void StartGame();

	void Battle(Character* player);

	void VisitShop(Character* player);

	void Exit();
};