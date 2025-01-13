#include "AttackBoost.h"

AttackBoost::AttackBoost():Name("AttackBoostItem"), AttackIncrease(20)
{
}

string AttackBoost::GetName()
{
    return Name;
}

void AttackBoost::Use(Character *character)
{
    character->SetAttack(character->GetAttack() + AttackIncrease);
    cout << "공격력이 " << AttackIncrease << "만큼 증가했습니다." << endl;
}