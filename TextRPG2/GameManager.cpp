#include <iostream>
#include "GameManager.h"
#include "Character.h"
#include "IMonster.h"

GameManager* GameManager::Instance = nullptr;

GameManager* GameManager::GetInstance()
{
	if (Instance == nullptr)
	{
		Instance = new GameManager();
	}
	return Instance;
}

IMonster* GameManager::GenerateMonster(int level)
{
	/*if (level % 10 == 0)
	{
		cout << "보스 몬스터를 조우했습니다.\n";
		switch (level % 40)
		{
		case 0: return new BossMonster(level, Troll); break;
		case 10: return new BossMonster(level, Slime); break;
		case 20: return new BossMonster(level, Goblin); break;
		case 30: return new BossMonster(level, Orc); break;
		}
	}
	else
	{
		cout << "일반 몬스터를 조우했습니다.\n";
		switch (level % 4)
		{
		case 0: return new Troll(level); break;
		case 1: return new Slime(level); break;
		case 2: return new Goblin(level); break;
		case 3: return new Orc(level); break;
		}
	}*/
}

void GameManager::Battle(Character* player)
{
	int level = player->GetLevel();
	GameManager::GenerateMonster(level);
	while (true)
	{
		cout << "\n메뉴\n1. 스탯 창 보기     2. 아이템 사용     3. 전투하기     4.도망가기\n";
		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
			player->DisplayStatus();
			break;
		case 2:
			player->DisplayInventory();
			int index;
			cin >> index;
			player->UseItem(index);

			break;
		case 3:

			break;
		case 4:

			break;
		default:
			cout << "잘못된 입력입니다. 다시 시도해주세요.\n";
		}
	}

}

void GameManager::VisitShop(Character* player)
{

}

void GameManager::Exit()
{

}