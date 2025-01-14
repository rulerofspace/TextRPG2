#include "Level.h"

Level::Level()
	: m_pGameManager{ GameManager::Get_Instance() }
{

}

void Level::Initialize()
{

}

void Level::Update()
{
}

void Level::gotoxy(int x, int y) {
	COORD coord;
	coord.X = SHORT(x);
	coord.Y = SHORT(y);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Level::Render()
{

}

void Level::Clear_Resources()
{

}

void Level::Free()
{
	system("cls");
	delete this;
}
