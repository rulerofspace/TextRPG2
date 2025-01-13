#include <iostream>
#include <string>
#include "Character.h"
#include "GameManager.h"

using namespace std;

int main()
{
    GameManager* GM = GameManager::GetInstance();
    GM->StartGame();
}