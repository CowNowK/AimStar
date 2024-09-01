#pragma once
#include "Misc.h"


namespace HUD
{
	inline void CheatList()
	{
		if (!MiscCFG::CheatList)
			return;

		ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar;
		ImGui::SetNextWindowBgAlpha(0.3f);
		ImGui::SetNextWindowSize(ImVec2(250, 0));
		ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 100));
		ImGui::Begin(XorStr("Cheats List"), nullptr, windowFlags);
		ImGui::PopStyleColor();

		if (MenuConfig::AimBot && (MenuConfig::AimAlways || GetAsyncKeyState(AimControl::HotKey)))
			ImGui::TextColored(ImColor(255, 255, 255, 200), XorStr("Aimbot [Toggle]"));
		Misc::CheatText(XorStr("External Radar"), RadarCFG::ShowRadar);
		if (MiscCFG::FlashImmunity != 0)
			ImGui::TextColored(ImColor(255, 255, 255, 200), XorStr("Flash Immunity"));
		Misc::CheatText(XorStr("Headshot Line"), MenuConfig::ShowHeadShootLine);
		Misc::CheatText(XorStr("Money Service"), MiscCFG::MoneyService);
		Misc::CheatText(XorStr("Anti Record"), MenuConfig::BypassOBS);
		if (MiscCFG::Fov != 90)
			ImGui::TextColored(ImColor(255, 255, 255, 200), XorStr("Fov Changer"));
		Misc::CheatText(XorStr("Force Scope"), MiscCFG::ForceScope);
		Misc::CheatText(XorStr("Smoke Color"), MiscCFG::SmokeColored);
		Misc::CheatText(XorStr("Bomb Timer"), MiscCFG::bmbTimer);
		Misc::CheatText(XorStr("Radar Hack"), MiscCFG::RadarHack);
		Misc::CheatText(XorStr("Jump Throw"), MiscCFG::jumpthrow);
		Misc::CheatText(XorStr("Night Mode"), MiscCFG::NightMode);
		Misc::CheatText(XorStr("TriggerBot"), MenuConfig::TriggerBot);
		Misc::CheatText(XorStr("Crosshair"), CrosshairsCFG::ShowCrossHair);
		Misc::CheatText(XorStr("Fake Duck"), MiscCFG::Jitter);
		Misc::CheatText(XorStr("Fast Stop"), MiscCFG::FastStop);
		Misc::CheatText(XorStr("HitMarker"), MiscCFG::HitMarker);
		Misc::CheatText(XorStr("Spec List"), MiscCFG::SpecList);
		Misc::CheatText(XorStr("HitSound"), MiscCFG::HitSound);
		Misc::CheatText(XorStr("No Smoke"), MiscCFG::NoSmoke);
		Misc::CheatText(XorStr("Bhop"), MiscCFG::BunnyHop);
		Misc::CheatText(XorStr("Glow"), MiscCFG::EnemySensor);
		Misc::CheatText(XorStr("ESP"), ESPConfig::ESPenabled);
		Misc::CheatText(XorStr("RCS"), MenuConfig::RCS);

		ImGui::End();
	}

}