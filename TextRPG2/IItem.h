#pragma once
#include <iostream>
#include <string>

using namespace std;

class Character;

class IItem
{
public:
	~IItem() = default;
	virtual string GetName() = 0;
	virtual void Use(Character *character) = 0;
};