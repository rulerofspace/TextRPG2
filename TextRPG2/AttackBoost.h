#pragma once
#include <iostream>
#include <string>
#include "IItem.h"
using namespace std;

class AttackBoost : public IItem
{
private:
    string Name;
    int AttackIncrease;

public:
    AttackBoost();
    string getName();
    //void use(class Character::);
};