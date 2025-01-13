#pragma once
#include "Character.h"
#include "Client_Defines.h"
using namespace std;

class GameManager
{
	DECLARE_SINGLETON(GameManager)
private:
	GameManager();
	virtual ~GameManager() = default;

public: /* For.Base */
	void Initialize();
	void Update();
	void Render();

public: /* For.Input_Manager */
	bool KeyPressedThisFrame();

	bool Key_Pressing(unsigned int _iKey);
	bool Key_Down(unsigned int _iKey);
	bool Key_Up(unsigned int _iKey);

public: /* For.Level_Manager */
	void Change_Level(class Level* pNewLevel);

public:
	//class IMonster* GenerateMonster(int level);

	bool battle(Character* player);

	void VisitShop(Character* player);

	void Exit();


private:
	class Level_Manager* m_pLevel_Manager{ nullptr };
	class Input_Manager* m_pInput_Manager{ nullptr };
public:
	static GameManager* Create();
	virtual void Free();
};