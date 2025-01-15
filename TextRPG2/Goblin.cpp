#include "Goblin.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // 난수 생성용
#include <ctime>   // 난수 초기화용

using namespace std;

// 고블린이 죽었을때 드롭될 아이템 목록
const vector<string> ITEM_POOL = { "Middle Grade Weapon", "AttackBoostItem", "Goblin Nail", "Gold" };

Goblin::Goblin()
	: IMonster{}
{
	srand(static_cast<unsigned>(time(0))); // 난수 초기화
}

/* 이렇게 이니셜라이즈에서 직접 초기화 해도 되고 위에서 생성자로 초기화 해도 됨*/

void Goblin::Initialize(string name, double health, double attack)
{
	mName = name;
	mHealth = health;
	mAttack = attack;
}

void Goblin::Update()
{
}

void Goblin::Interact() {

}

Goblin *Goblin::Create(string name, double health, double attack)
{
	Goblin *pGoblin = new Goblin();

	pGoblin->Initialize(name, health, attack);

	return pGoblin;
}

Goblin *Goblin::CreateBoss(string name, double health, double attack)
{
	Goblin *pGoblin = new Goblin();

	pGoblin->Initialize(name, health, attack);

	return pGoblin;
}

void Goblin::Free()
{
}

// 아이템 드롭 기능 추가
void Goblin::DropItem()
{
	int itemIndex = rand() % ITEM_POOL.size(); // 아이템 랜덤 선택
	cout << mName << "가 " << ITEM_POOL[itemIndex] << " 아이템을 드롭했습니다!" << endl;
}

// 고블린 죽음 처리
void Goblin::Die()
{
	cout << mName << "가 죽었습니다!" << endl;
	DropItem();
}
