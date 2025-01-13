#include "Slime.h"

Slime::Slime()
	: IMonster{}
{
}

/* 이렇게 이니셜라이즈에서 직접 초기화 해도 되고 위에서 생성자로 초기화 해도 됨*/
void Slime::Initialize(string name, int health, int attack)
{
	mName = name;
	mHealth = health;
	mAttack = attack;
}

void Slime::Update()
{

}

Slime* Slime::Create(string name, int health, int attack)
{
	Slime* pSlime = new Slime();

	pSlime->Initialize(name, health, attack);

	return pSlime;
}

void Slime::Free()
{
}
