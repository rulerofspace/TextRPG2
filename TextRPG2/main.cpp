#include "GameManager.h"
#include "MainApp.h"

void DisableCursorBlinking();
bool IsAnyKeyPressed();

int main()
{
	DisableCursorBlinking();

	MainApp* pMainApp = MainApp::Create();

	GameManager* pGameManager = GameManager::Get_Instance();

	while (true)
	{
		pMainApp->Update();
		pMainApp->Render();
		
		if (pGameManager->Key_Down('A')) {
			cout << "A key Test" << endl;
			system("pause");
		}

		while (!IsAnyKeyPressed())
			Sleep(10);
		
		system("cls");
	}
}

bool IsAnyKeyPressed() 
{
	for (int key = 0; key < 256; ++key) 
	{
		if (GetAsyncKeyState(key) & 0x8000)
			return true;
	}
	return false;
}

void DisableCursorBlinking()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(hConsole, &cursorInfo);

	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hConsole, &cursorInfo);
}