#pragma once

#include <stdint.h>
#include <Windows.h>
#include <iostream>
#include <dinput.h>
#include <string>
#include <vector>

#include "Client_Macro.h"

namespace Client
{
	enum LEVELID { LEVEL_LOGO, LEVEL_MAIN, LEVEL_END };

	const int MAP_WIDTH = 20;  // ¸Ê °¡·Î Å©±â
	const int MAP_HEIGHT = 20; // ¸Ê ¼¼·Î Å©±â
}

using namespace std;
using namespace Client;