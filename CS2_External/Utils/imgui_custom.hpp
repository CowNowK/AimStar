#pragma once
#include <string>
#include "..\OS-ImGui\imgui\imgui.h"

static int STYLE = 0;

namespace ImGui {

	IMGUI_API bool		Hotkey(const char* label, int& key, float samelineOffset = 0.0f, const ImVec2& size = { 100.0f, 0.0f });
	IMGUI_API bool      Checkbox2(const char* label, bool* v);
	IMGUI_API bool      Checkbox_(const char* label, bool* v);

	IMGUI_API bool      SliderInt_2(const char* label, int* v, int v_min, int v_max, const char* format = "%d", ImGuiSliderFlags flags = 0);
	IMGUI_API bool		SliderInt_(const char* label, int* v, int v_min, int v_max, const char* format = "%d", ImGuiSliderFlags flags = 0);

	IMGUI_API bool      SliderFloat_2(const char* label, float* v, float v_min, float v_max, const char* format = "%.3f", ImGuiSliderFlags flags = 0);
	IMGUI_API bool      SliderFloat_(const char* label, float* v, float v_min, float v_max, const char* format = "%.3f", ImGuiSliderFlags flags = 0);

	IMGUI_API void     chromaText(std::string text, float sat, float value, float alpha, float speed, float offset, float range);
}

struct ImGuiTextFilter2 : public ImGuiTextFilter {
	IMGUI_API bool      Draw2(const char* label = "Filter (inc,-exc)", float width = 0.0f);  // filter.Draw | Helper calling InputText+Build
};