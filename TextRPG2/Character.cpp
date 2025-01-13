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

double Character::GetHealth()
{
    if (Health <= 0) Health = 0;
    return Health;
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

double Character::GetGold()
{
    return Gold;
}
