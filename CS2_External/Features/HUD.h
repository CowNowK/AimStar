#pragma once
#include "Misc.h"


namespace HUD
{
	inline void CheatList()
	{
		if (!MiscCFG::CheatList)
			return;

		ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar;
		//ImGui::SetNextWindowBgAlpha(0.3f);
		ImGui::SetNextWindowSize(ImVec2(250, 0));
		ImVec4 default_bg_color = ImGui::GetStyleColorVec4(ImGuiCol_WindowBg);
		default_bg_color.w = 0.5f;
		ImGui::PushStyleColor(ImGuiCol_WindowBg, default_bg_color);
		ImGui::Begin(XorStr("Cheats List"), nullptr, windowFlags);
		ImGui::PopStyleColor();

		Misc::CheatText(XorStr("Aimbot [Hold]"), MenuConfig::AimBot && GetAsyncKeyState(AimControl::HotKey) && !MenuConfig::AimToggleMode);
		Misc::CheatText(XorStr("Aimbot [Toggle]"), MenuConfig::AimBot && MenuConfig::AimAlways);
		Misc::CheatText(XorStr("TriggerBot [Hold]"), MenuConfig::TriggerBot && GetAsyncKeyState(TriggerBot::HotKey) && !MenuConfig::TriggerAlways);
		Misc::CheatText(XorStr("TriggerBot [Always]"), MenuConfig::TriggerBot && MenuConfig::TriggerAlways);
		Misc::CheatText(XorStr("External Radar"), RadarCFG::ShowRadar);
		Misc::CheatText(XorStr("Flash Immunity"), MiscCFG::FlashImmunity);
		Misc::CheatText(XorStr("Headshot Line"), MenuConfig::ShowHeadShootLine);
		Misc::CheatText(XorStr("Money Service"), MiscCFG::MoneyService);
		Misc::CheatText(XorStr("Anti Record"), MenuConfig::BypassOBS);
		Misc::CheatText(XorStr("Anti Record"), MenuConfig::BypassOBS);
		Misc::CheatText(XorStr("Fov Changer"), MiscCFG::Fov != 90);
		Misc::CheatText(XorStr("Force Scope"), MiscCFG::ForceScope);
		Misc::CheatText(XorStr("Smoke Color"), MiscCFG::SmokeColored);
		Misc::CheatText(XorStr("Bomb Timer"), MiscCFG::bmbTimer);
		Misc::CheatText(XorStr("Radar Hack"), MiscCFG::RadarHack);
		Misc::CheatText(XorStr("Jump Throw"), MiscCFG::jumpthrow);
		Misc::CheatText(XorStr("Night Mode"), MiscCFG::NightMode);
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