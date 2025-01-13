#pragma once
#include <iostream>
#include <string>

using namespace std;

class AttackBoost : IItem
{
private:
    string Name;
    int AttackIncrease;

public:
    AttackBoost();
    string getName();
    void use(character : Character *);
};