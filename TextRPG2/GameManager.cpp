#include "GameManager.h"
#include "Level_Manager.h"
#include "Input_Manager.h"
#include "IMonster.h"
#include "Goblin.h"
#include "Slime.h"
#include "Troll.h"
#include "Level.h"
#include "Orc.h"

IMPLEMENT_SINGLETON(GameManager)

GameManager::GameManager()
{

}

void GameManager::Initialize()
{
	HINSTANCE hInstance = GetModuleHandle(nullptr);
	HWND hWnd = GetConsoleWindow();

	m_pLevel_Manager = Level_Manager::Create();

	m_pInput_Manager = Input_Manager::Create(hInstance, hWnd);
}

//IMonster* GameManager::GenerateMonster(int level)
//{
//	switch (level % 4)
//	{
//	case 0: return Slime::Create(); break;
//	case 1: return Goblin::Create(); break;
//	case 2: return Orc::Create(); break;
//	case 3: return Troll::Create(); break;
//		// case : return new BossMonster(level); break;
//	}
//}

bool GameManager::battle(Character* player)
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
	return true;
}

void GameManager::VisitShop(Character* player)
{

}

void GameManager::Exit()
{


}

void GameManager::Update()
{
	m_pInput_Manager->Update();

	m_pLevel_Manager->Update();
}

void GameManager::Render()
{
	m_pLevel_Manager->Render();
}

bool GameManager::KeyPressedThisFrame()
{
	return m_pInput_Manager->KeyPressedThisFrame();
}

bool GameManager::Key_Pressing(unsigned int _iKey)
{
	return m_pInput_Manager->Key_Pressing(_iKey);
}

bool GameManager::Key_Down(unsigned int _iKey)
{
	return m_pInput_Manager->Key_Down(_iKey);
}

bool GameManager::Key_Up(unsigned int _iKey)
{
	return m_pInput_Manager->Key_Up(_iKey);
}

void GameManager::Change_Level(Level* pNewLevel)
{
	if (nullptr == m_pLevel_Manager)
		return;

	m_pLevel_Manager->Change_Level(pNewLevel);
}

GameManager* GameManager::Create()
{
	GameManager* pInstance = new GameManager();

	pInstance->Initialize();

	return pInstance;
}

void GameManager::Free()
{
}