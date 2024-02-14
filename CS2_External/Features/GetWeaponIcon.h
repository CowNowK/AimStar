#pragma once
#include <string>
#include <map>

// https://www.unknowncheats.me/forum/counter-strike-2-a/608799-weapon-icon-esp.html
const char* GunIcon(const std::string weapon)
{
	std::map<std::string, const char*> gunIcons = {
		{"nova", "T"},
		{"ak47", "A"},
		{"awp", "C"},
		{"m4a4", "M"},
		{"deagle", "F"},
		{"mp9", "R"},
		{"famas", "H"},
		{"ump45", "b"},
		{"glock", "g"},
		// Добавьте остальные оружия и их соответствующие строки здесь
	};

	// Добавляем оружия и их значки в соответствии с вашим списком
	gunIcons["ct_knife"] = "]";
	gunIcons["t_knife"] = "[";
	gunIcons["deagle"] = "A";
	gunIcons["elite"] = "B";
	gunIcons["fiveseven"] = "C";
	gunIcons["glock"] = "D";//
	gunIcons["revolver"] = "J";//
	gunIcons["hkp2000"] = "E";//
	gunIcons["p250"] = "F";//
	gunIcons["usp_silencer"] = "G";//
	gunIcons["tec9"] = "H";//
	gunIcons["cz75a"] = "I";//
	gunIcons["mac10"] = "K";//
	gunIcons["ump45"] = "L";
	gunIcons["bizon"] = "M";//
	gunIcons["mp7"] = "N";//
	gunIcons["mp9"] = "R";
	gunIcons["p90"] = "O";
	gunIcons["galilar"] = "Q";
	gunIcons["famas"] = "R";
	gunIcons["m4a1_silencer"] = "T";//
	gunIcons["m4a1"] = "S";//
	gunIcons["aug"] = "U";
	gunIcons["sg556"] = "V";
	gunIcons["ak47"] = "W";
	gunIcons["g3sg1"] = "X";
	gunIcons["scar20"] = "Y";//
	gunIcons["awp"] = "Z";
	gunIcons["ssg08"] = "a";//
	gunIcons["xm1014"] = "b";
	gunIcons["sawedoff"] = "c";
	gunIcons["mag7"] = "d";
	gunIcons["nova"] = "e";
	gunIcons["negev"] = "f";
	gunIcons["m249"] = "g";
	gunIcons["taser"] = "h";
	gunIcons["flashbang"] = "i";
	gunIcons["hegrenade"] = "j";
	gunIcons["smokegrenade"] = "k";
	gunIcons["molotov"] = "l";//
	gunIcons["decoy"] = "m";
	gunIcons["incgrenade"] = "n";
	gunIcons["c4"] = "o";

	auto it = gunIcons.find(weapon);
	if (it != gunIcons.end()) {
		return it->second;
	}

	return "";
}