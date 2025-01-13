#pragma once
#include "Character.h"
#include "IMonster.h"
#include <string>
#include <vector>

using namespace std;

class GameManager
{
public:
	IMonster* GenerateMonster(int level);

	void battle(Character* player);

	void VisitShop(Character* player);

	void Exit();
};