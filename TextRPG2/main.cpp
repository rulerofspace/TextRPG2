#include "GameManager.h"
#include "MainApp.h"
#include <locale>

void DisableCursorBlinking();
bool IsAnyKeyPressed();

int main()
{
	DisableCursorBlinking();

	MainApp *pMainApp = MainApp::Create();

	GameManager *pGameManager = GameManager::Get_Instance();
	pGameManager->DisableEcho();

	bool bIsInit = false;
	while (true)
	{
		pMainApp->Update();
		pMainApp->Render();

		if (pGameManager->KeyPressedThisFrame())
			system("pause");

		if (bIsInit == false)
		{
			system("pause");
			bIsInit = true;
		}
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