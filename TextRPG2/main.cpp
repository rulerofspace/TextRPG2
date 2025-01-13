#include "GameManager.h"
#include "MainApp.h"

void DisableCursorBlinking();
bool IsAnyKeyPressed();

int main()
{
	DisableCursorBlinking();

	MainApp* pMainApp = MainApp::Create();

	GameManager* pGameManager = GameManager::Get_Instance();

	bool bIsInit = false;
	while (true)
	{
		pMainApp->Update();
		pMainApp->Render();
		
		///* 눌렀을 때 */
		if (pGameManager->Key_Down('A'))
			cout << "A keyDown Test" << endl;

		///* 누르고 있으면 */
		//if (pGameManager->Key_Pressing('S'))
		//	cout << "S keyPressing Test" << endl;

		///* 업은 안먹는다 */
		//if (pGameManager->Key_Up('D'))
		//	cout << "D keyUp Test" << endl;

		if (pGameManager->KeyPressedThisFrame())
		{
			system("pause");
		}
		
		if (bIsInit == false)
		{
			system("pause");
			bIsInit = true;
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