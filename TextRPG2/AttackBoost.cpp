#include "AttackBoost.h"

//AttackBoost::AttackBoost();

string AttackBoost::getName()
{
    string InputName;
    cout << "사용할 아이템이 무엇입니까?" << endl;
    cin.ignore();
    getline(cin, InputName);
    Name = InputName;
    return Name;
}

//void AttackBoost::use(character::Character *)
//{
//}