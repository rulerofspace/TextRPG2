#pragma once

#include "Client_Defines.h"
#include "Level.h"

class Level_Main final : public Level
{
private:
	Level_Main();
	virtual ~Level_Main() = default;

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;

private:
	char m_Map[MAP_HEIGHT][MAP_WIDTH];
	string buffer{};

	int* m_pPlayerPosX{ nullptr };
	int* m_pPlayerPosY{ nullptr };

	bool m_bStatusView{ false };
public:
	static Level_Main* Create();
	virtual void Free() override;
};
