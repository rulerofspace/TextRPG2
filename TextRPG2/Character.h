#pragma once

#include <string>
#include <vector>

using namespace std;

class Character
{
private:
    static Character *Instance;
    string Name;
    int Level;
    int MaxLevel;
    double Health;        // 체력
    double MaxHealth;     // 최대 체력
    double Attack;        // 공격력
    double Experience;    // 경험치
    double MaxExperience; // 최대 경험치
    double Gold;          // 돈

    Character(string name);

public:
    static Character *GetInstance(string name = "");
    string GetName();
    int GetLevel();
    double GetHealth();
    double GetAttack();
    void SetHealth(double health);
    void SetAttack(double attack);
    void TakeDamage(double damage);
    double GetExperience();
    double GetMaxExperience();
    double GetGold();
};