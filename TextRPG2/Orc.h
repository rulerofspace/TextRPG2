#pragma once

#include "IMonster.h"

class Orc : public IMonster
{
private:
	/*
	생성자를 private 으로 해버리면 동적할당이 막힌다. 개념숙지
	그래서 Create라는 함수를 만들어서 직접 생성하게 할 수 있다.	*/
	Orc();
	virtual ~Orc() = default;

public: /* IMonster 부모 클래스에서 받아온 함수들 */
	virtual void Initialize(string name, int health, int attack) override;
	virtual void Update() override;

public: /* 실제 동적할당을 대신해주는 함수 */
	static Orc* Create(string name = "", int health = 10, int attack = 5);
	virtual void Free() override;
};

/* 이렇게 public으로 생성자에 인자값을 넣어서 초기화가 기본
* 
class Orc : public IMonster
{
public:
		Orc(string name, int health, int attack);   <--------
		virtual ~Orc() = default;

public:
	virtual void Initialize(string name, int health, int attack) override;
	virtual void Update() override;

public:
	virtual void Free() override;
};
*/