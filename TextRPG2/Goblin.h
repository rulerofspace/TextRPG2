#pragma once

#include "IMonster.h"

class Goblin : public IMonster
{
private:
	/*
	�����ڸ� private ���� �ع����� �����Ҵ��� ������. �������
	�׷��� Create��� �Լ��� ���� ���� �����ϰ� �� �� �ִ�.	*/
	Goblin();
	virtual ~Goblin() = default;

public: /* IMonster �θ� Ŭ�������� �޾ƿ� �Լ��� */
	virtual void Initialize(string name, int health, int attack) override;
	virtual void Update() override;

public: /* ���� �����Ҵ��� ������ִ� �Լ� */
	static Goblin* Create(string name, int health, int attack);
	static Goblin* CreateBoss(string name, int health, int attack);
	virtual void Free() override;
};