#include "AttackBoost.h"
#include "Character.h"

AttackBoost::AttackBoost():Name("AttackBoostItem"), AttackIncrease(20)
{
}

string AttackBoost::GetName()
{
    string InputName;
    cout << "사용할 아이템이 무엇입니까?" << endl;
    cin.ignore();
    getline(cin, InputName);
    Name = InputName;
    return Name;
}

void AttackBoost::Use(Character *character)
{
    character->SetAttack(character->GetAttack() + AttackIncrease);
    cout << "공격력이 " << AttackIncrease << "만큼 증가했습니다." << endl;
}