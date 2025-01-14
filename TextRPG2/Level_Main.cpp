#include "Level_Main.h"
#include "Character.h"
#include "GameManager.h"

Level_Main::Level_Main()
	: Level{}
{
}

void Level_Main::Initialize()
{
	m_iLevelIndex = LEVEL_MAIN;

	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			m_Map[i][j] = '.';
		}
	}

	m_pPlayerPosX = m_pGameManager->GetPlayerPosX();
	m_pPlayerPosY = m_pGameManager->GetPlayerPosY();

	*m_pPlayerPosX = MAP_WIDTH / 2;
	*m_pPlayerPosY = MAP_HEIGHT / 2;
	m_Map[*m_pPlayerPosY][*m_pPlayerPosX] = 'A';
}

void Level_Main::Update()
{
	m_Map[*m_pPlayerPosY][*m_pPlayerPosX] = '.';

	if (m_pGameManager->Key_Down(VK_LEFT))
	{
		if ((*m_pPlayerPosX) > 0)
			(*m_pPlayerPosX)--;
	}

	if (m_pGameManager->Key_Down(VK_UP))
	{
		if ((*m_pPlayerPosY) > 0)
			(*m_pPlayerPosY)--;
	}

	if (m_pGameManager->Key_Down(VK_DOWN))
	{
		if ((*m_pPlayerPosY) < MAP_HEIGHT - 1)
			(*m_pPlayerPosY)++;
	}

	if (m_pGameManager->Key_Down(VK_RIGHT))
	{
		if ((*m_pPlayerPosX) < MAP_WIDTH - 1)
			(*m_pPlayerPosX)++;
	}

	if (m_pGameManager->Key_Down(VK_TAB))
	{
		m_bStatusView = !m_bStatusView;
	}

	m_Map[*m_pPlayerPosY][*m_pPlayerPosX] = 'A';
}

void Level_Main::Render()
{

	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++) {
			buffer.push_back(m_Map[i][j]);
			buffer.push_back(' ');
		}
		buffer.push_back('\n');
	}

	gotoxy(0, 0);
	cout << buffer;
	buffer.clear();
}

Level_Main* Level_Main::Create()
{
	Level_Main* pInstance = new Level_Main();

	pInstance->Initialize();

	return pInstance;
}

void Level_Main::Free()
{
	__super::Free();
}
