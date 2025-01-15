#pragma once

#include "IMonster.h"
#include <vector>
#include <string>

class Goblin : public IMonster
{
private:
	/*
	생성자를 private 으로 해버리면 동적할당이 막힌다. 개념숙지
	그래서 Create라는 함수를 만들어서 직접 생성하게 할 수 있다.	*/
	Goblin();
	virtual ~Goblin() = default;

	// 고블린이 죽었을때 드롭될 아이템 목록
	static const std::vector<std::string> ITEM_POOL;

public: 
	virtual void Initialize(string name, double health, double attack) override;
	virtual void Update() override;
	virtual void Interact() override;

public: /* 실제 동적할당을 대신해주는 함수 */
	static Goblin *Create(string name = "", double health = 10, double attack = 5);
	static Goblin* CreateBoss(string name, double health, double attack);
	virtual void Free() override;

	// 아이템 드롭 기능 추가
	void DropItem();

	// 고블린 죽음 처리
	void Die();
};
