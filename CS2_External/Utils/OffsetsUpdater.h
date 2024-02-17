#pragma once
#include "cpp-httplib/httplib.h"
#include "json/json.hpp"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using json = nlohmann::json;

namespace Updater
{
	static std::map<std::string, uintptr_t> offsets;

	
}