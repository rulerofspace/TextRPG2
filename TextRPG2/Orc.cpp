#include "Orc.h"

Orc::Orc()
	: IMonster{}
{
}

/* 이렇게 이니셜라이즈에서 직접 초기화 해도 되고 위에서 생성자로 초기화 해도 됨*/
void Orc::Initialize(string name, int health, int attack)
{
	mName = name;
	mHealth = health;
	mAttack = attack;
}

void Orc::Update()
{

}

Orc* Orc::Create(string name, int health, int attack)
{
	Orc* pOrc = new Orc();

	pOrc->Initialize(name, health, attack);

	return pOrc;
}

void Orc::Free()
{
}
