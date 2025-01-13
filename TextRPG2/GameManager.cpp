#include <iostream>
#include "GameManager.h"
#include "Character.h"
#include "IMonster.h"
#include "HealthPotion.h"
#include "Troll.h"
#include "Slime.h"
#include "Goblin.h"
#include "Orc.h"

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
		case 0:
			Troll* troll = Troll::CreateBoss("보스 트롤", 30, 10);
			return troll;
			break;
		case 10:
			Slime* slime = Slime::CreateBoss("보스 슬라임", 30, 10);
			return slime;
			break;
		case 20:
			Goblin* goblin = Goblin::CreateBoss("보스 고블린", 30, 10);
			return goblin;
			break;
		case 30:
			Orc* orc = Orc::CreateBoss("보스 오크", 30, 10);
			return orc;
	}
	else
	{
		cout << "일반 몬스터를 조우했습니다.\n";
		switch (level % 4)
		{
		case 0:
			Troll* troll = Troll::Create("일반 트롤", 30, 10);
			return troll;
			break;
		case 1:
			Slime* slime = Slime::Create("일반 슬라임", 30, 10);
			return slime;
			break;
		case 2: 
			Goblin* goblin = Goblin::Create("일반 고블린", 30, 10);
			return goblin;
			break;
		case 3:
			Orc* orc = Orc::Create("일반 오크", 30, 10); 
			return orc;
			break;
		}
	}*/
	Orc* orc = Orc::Create("일반오크", 30, 10);
	return orc;
}

void GameManager::StartGame()
{
	string name;
	cout << "캐릭터를 생성하기 위해 이름을 입력해주세요.\n";
	getline(cin, name);
	Character* Player = Character::GetInstance(name);
	cout << "\n메뉴\n1. 스탯 창 보기     2. 전투 지역으로 이동\n";
	string choice;
	getline(cin, choice);
	switch (stoi(choice))
	{
		case 1:
			Player->DisplayStatus();
			break;
		case 2:
			Battle(Player);
			break;
		default:
			cout << "잘못된 입력입니다. 다시 시도해주세요.\n";
	}
}

void GameManager::Battle(Character* player)
{
	int level = player->GetLevel();
	IMonster* Monster = GameManager::GenerateMonster(level);
	HealthPotion* hp = new HealthPotion();
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
			player->Inventory.push_back(pair<IItem*, int>(hp, 1));
			player->Inventory.push_back(pair<IItem*, int>(hp, 1));
			player->DisplayInventory();
			int index;
			cin >> index;
			player->UseItem(index);

			break;
		case 3:
			cout << "\n전투가 시작되었습니다.\n이번에 싸울 몬스터는 " << Monster->GetName()
				<< " (체력: " << Monster->GetHealth() << ", 공격력: " << Monster->GetAttack() << ")\n";
			
			double originalAttack = player->GetAttack();  // 전투 시작 전 공격력 저장
			double increasedAttack = 0; // 공격력 증가 부분을 추적할 변수

			// 전투 진행
			while (player->GetHealth() > 0 && Monster->GetHealth() > 0) {
				cout << "\n메뉴\n1. 스탯 창 보기     2. 아이템 사용     3. 전투하기     4.도망가기\n";
				int choice;
				cin >> choice;

				switch (choice)
				{
				case 1:
					player->DisplayStatus();
					break;
				case 2:
					// 아이템 사용
					break;
				case 3:break;

				case 4:break;
				}

				// 전투 결과 처리
				if (player->GetHealth() <= 0) {
					cout << "\n전투에서 패배했습니다.\n게임 오버!\n";
					exit(0);
				}
				else {
					// 전투 승리 처리
					player->AddExperience(50);
					int gold = 10 + rand() % 10;
					player->AddGold(gold);
					cout << "\n전투에서 승리했습니다.\n50의 경험치와 " << gold << " 골드를 획득!\n";

					Item* DroppedItem = Monster->dropItem();
					if (DroppedItem) {
						player->AddItem(DroppedItem); // 플레이어의 인벤토리에 아이템 추가
						cout << "몬스터가 " << DroppedItem->getName() << "을 떨어뜨렸습니다.\n";
					}

					player->LevelUp();
					player->DisplayStatus();
				}
				delete Monster;
			}
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