#include <iostream>
#include <string>
#include "Character.h"
#include "GameManager.h"

using namespace std;

int main()
{
    string name;
    cout << "캐릭터를 생성하기 위해 이름을 입력해주세요.\n";
    getline(cin, name);
    Character* Player = Character::GetInstance(name);

    GameManager* GM = GameManager::GetInstance();
    GM->Battle(Player);
}