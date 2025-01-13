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
		
		if (pGameManager->Key_Down('A'))
		{
			cout << "A keyDown Test" << endl;
			//system("pause");
		}

		if (pGameManager->Key_Pressing('S'))
		{
			cout << "S keyPressing Test" << endl;
			//system("pause");
		}

		if (pGameManager->Key_Up('D'))
		{
			cout << "D keyUp Test" << endl;
			//system("pause");
		}

		if (pGameManager->KeyPressedThisFrame())
		{
			system("pause");
		}
			
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