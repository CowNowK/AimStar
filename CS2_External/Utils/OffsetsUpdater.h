#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <Windows.h>
#include "cpp-httplib/httplib.h"
#include "json/json.hpp"

using json = nlohmann::json;

namespace Updater
{
	static std::map<std::string, DWORD64> offsets;

	
}