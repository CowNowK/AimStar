#pragma once

#include <string>
#include <vector>

namespace StringH {

	std::string vkToString(int vk);
	std::string boolToStr(bool flag);
	std::vector<std::string> split(std::string s, std::string delimiter);
	bool equalsIgnoreCase(std::string a, std::string b);
	std::string strToBytes(std::string s);
	std::string bytesToStr(std::string s);
	std::string getFileNameFromPath(std::string s);
}