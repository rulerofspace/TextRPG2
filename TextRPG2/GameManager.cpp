#include "GameManager.h"
#include "IMonster.h"

IMonster *GenerateMonster(int level)
{
    switch (level % 4)
    {
    case 0:
        return new Troll(level);
        break;
    case 1:
        return new Slime(level);
        break;
    case 2:
        return new Goblin(level);
        break;
    case 3:
        return new Orc(level);
        break;
        // case : return new BossMonster(level); break;
    }
}

bool battle(Character *player)
{
    if (player->GetLevel() == 10)
    {
        // 보스 몬스터 조우
    }
    else
    {
        // 일반 몬스터 조우
        // 전투 진행
    }
}

void VisitShop(Character *player)
{
}

void Exit()
{
}