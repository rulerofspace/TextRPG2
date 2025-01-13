#pragma once

//#include "Character.h"
#include <iostream>
#include <string>

using namespace std;

class IItem
{
public:
	~IItem() = default;
	virtual string GetName() = 0;
	virtual void Use(class Character *character) = 0;
};