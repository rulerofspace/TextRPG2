#include <iostream>
#include "Character.h"

Character* Character::Instance = nullptr;

Character::Character(string name)
    : Name(name), Level(1), MaxLevel(10), Health(200),
    MaxHealth(200), Attack(30), Experience(0), Gold(0)
{
}

Character* Character::GetInstance(string name)
{
    if (!Instance && !name.empty()) {
        Instance = new Character(name);
    }
    return Instance;
}

string Character::GetName()
{
    return Name;
}

int Character::GetLevel()
{
    return Level;
}

int Character::SetLevel(int level)
{
    Level = level;
    return Level;
}

int Character::GetMaxLevel()
{
    return MaxLevel;
}

double Character::GetHealth()
{
    return Health;
}

void Character::SetHealth(double health)
{
    if (health >= MaxHealth)
    {
        Health = MaxHealth;
    }
    else if (health > 0 && health < MaxHealth)
    {
        Health = health;
    }
    else if (Health <= 0)
    {
        Health = 0;
    }
}

double Character::GetAttack()
{
    return Attack;
}

void Character::SetAttack(double attack)
{
    Attack = attack;
}

void Character::TakeDamage(double damage)
{
    Health -= damage;
    if (Health < 0) Health = 0;
}

double Character::GetExperience()
{
    return Experience;
}

double Character::GetMaxExperience()
{
    return MaxExperience;
}

double Character::GetGold()
{
    return Gold;
}
