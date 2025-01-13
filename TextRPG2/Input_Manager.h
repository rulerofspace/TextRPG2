#pragma once

#include "Client_Defines.h"

class Input_Manager
{
private:
    Input_Manager(void);
    virtual ~Input_Manager(void) = default;

public:
    int8_t Get_KeyState(BYTE byKeyID) { return m_byKeyState[byKeyID]; }

    bool Key_Pressing(unsigned int _iKey);
    bool Key_Down(unsigned int _iKey);
    bool Key_Up(unsigned int _iKey);

public:
    void Update(void);

private:
    int8_t m_byKeyState[256] = {}; // 키보드에 있는 모든 키값을 저장하기 위한 
    BYTE m_byPrevKeyState[256];   // 이전 키 상태변수
    bool m_bKeyState[256] = { false }; // 키의 현재 상태를 저장하기 위한 변수

public:
    static Input_Manager* Create(HINSTANCE hInst, HWND hWnd);
    virtual void Free(void);

};

