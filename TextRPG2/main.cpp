#include "GameManager.h"
#include "MainApp.h"

void DisableEcho();
void DisableCursorBlinking();
bool IsAnyKeyPressed();


int main()
{
	DisableEcho();
	DisableCursorBlinking();

	MainApp* pMainApp = MainApp::Create();

	GameManager* pGameManager = GameManager::Get_Instance();

	bool bIsInit = false;
	while (true)
	{
			system("pause");
		pMainApp->Update();
		pMainApp->Render();

//		if (pGameManager->KeyPressedThisFrame())
		
		if (bIsInit == false)
		{
			system("pause");
			bIsInit = true;
		}

	}
}

void DisableEcho() {
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hInput, &mode);            // 현재 콘솔 입력 모드 가져오기
	mode &= ~ENABLE_ECHO_INPUT;              // ENABLE_ECHO_INPUT 플래그 제거
	SetConsoleMode(hInput, mode);            // 수정된 모드 설정
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