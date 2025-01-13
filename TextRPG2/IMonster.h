#pragma once
#include <string>

using namespace std;

class IMonster abstract
{
protected:
	IMonster();
	virtual ~IMonster() = default;

public:
	/**
	* 끝에 = 0을 붙인 순수가상함수라는 뜻이며 선언만 하는 것
	* 자식클래스는 = 0 이 붙은 함수를 무조건 구현해야됨	*/
	virtual void Initialize(string name, int health, int attack) = 0;
	virtual void Update() = 0;
	
	virtual string GetName() const { return mName; }

	virtual int GetHealth() const { return mHealth; }
	virtual int GetAttack() const { return mAttack; }

protected:
	string		mName{};
	int			mHealth{ 0 };
	int			mAttack{ 0 };
public:
	virtual void Free();
};