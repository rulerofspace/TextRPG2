#include "Goblin.h"

Goblin::Goblin()
	: IMonster{}
{
}

/* �̷��� �̴ϼȶ������ ���� �ʱ�ȭ �ص� �ǰ� ������ �����ڷ� �ʱ�ȭ �ص� ��*/
void Goblin::Initialize(string name, int health, int attack)
{
	mName = name;
	mHealth = health;
	mAttack = attack;
}

void Goblin::Update()
{

}

Goblin* Goblin::Create(string name, int health, int attack)
{
	Goblin* pGoblin = new Goblin();

	pGoblin->Initialize(name, health, attack);

	return pGoblin;
}

Goblin* Goblin::CreateBoss(string name, int health, int attack)
{
	Goblin* pGoblin = new Goblin();

	pGoblin->Initialize(name, health, attack);

	return pGoblin;
}

void Goblin::Free()
{
}
