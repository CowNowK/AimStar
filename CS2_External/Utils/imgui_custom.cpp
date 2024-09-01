#include <Windows.h>
#include <string>
#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui_custom.hpp"
#include "Ext-String.hpp"
#include "Ext-Color.hpp"
#include "..\OS-ImGui\imgui\imgui.h"
#include "..\OS-ImGui\imgui\imgui_internal.h"


bool ImGui::Checkbox_(const char* label, bool* v) {
	if (STYLE == 0) return Checkbox2(label, v);
}
bool ImGui::SliderFloat_(const char* label, float* v, float v_min, float v_max, const char* format, ImGuiSliderFlags flags) {
	if (STYLE == 0) return SliderFloat_2(label, v, v_min, v_max, format, flags);
}
bool ImGui::SliderInt_(const char* label, int* v, int v_min, int v_max, const char* format, ImGuiSliderFlags flags) {
	if (STYLE == 0) return SliderInt_2(label, v, v_min, v_max, format, flags);
	//if (STYLE == 1) return SliderInt_2(label, v, v_min, v_max, format, flags);
}

bool ImGui::Checkbox2(const char* label, bool* v) {
	ImGuiWindow* window = GetCurrentWindow();
	if (window->SkipItems) return false;

	ImGuiContext& g = *GImGui;
	const ImGuiStyle& style = g.Style;
	const ImGuiID id = window->GetID(label);
	const ImVec2 label_size = CalcTextSize(label, NULL, true);

	const float square_sz = GetFrameHeight();
	const ImVec2 pos = window->DC.CursorPos;
	const ImRect total_bb(pos, pos + ImVec2(square_sz + (label_size.x > 0.0f ? style.ItemInnerSpacing.x + label_size.x : 0.0f), label_size.y + style.FramePadding.y * 2.0f));
	ItemSize(total_bb, style.FramePadding.y);
	if (!ItemAdd(total_bb, id))
	{
		IMGUI_TEST_ENGINE_ITEM_INFO(id, label, g.LastItemData.StatusFlags | ImGuiItemStatusFlags_Checkable | (*v ? ImGuiItemStatusFlags_Checked : 0));
		return false;
	}

	bool hovered, held;
	bool pressed = ButtonBehavior(total_bb, id, &hovered, &held);
	if (pressed)
	{
		*v = !(*v);
		MarkItemEdited(id);
	}

	const ImRect check_bb(pos, pos + ImVec2(square_sz, square_sz));
	RenderNavHighlight(total_bb, id);
	RenderFrame(check_bb.Min, check_bb.Max, GetColorU32((held && hovered) ? ImGuiCol_FrameBgActive : hovered ? ImGuiCol_FrameBgHovered : ImGuiCol_FrameBg), true, style.FrameRounding);
	ImU32 check_col = GetColorU32(ImGuiCol_CheckMark);
	bool mixed_value = (g.LastItemData.InFlags & ImGuiItemFlags_MixedValue) != 0;
	if (mixed_value)
	{
		// Undocumented tristate/mixed/indeterminate checkbox (#2644)
		// This may seem awkwardly designed because the aim is to make ImGuiItemFlags_MixedValue supported by all widgets (not just checkbox)
		ImVec2 pad(ImMax(1.0f, IM_FLOOR(square_sz / 3.6f)), ImMax(1.0f, IM_FLOOR(square_sz / 3.6f)));
		window->DrawList->AddRectFilled(check_bb.Min + pad, check_bb.Max - pad, check_col, style.FrameRounding);
	}
	else if (*v)
	{
		const float pad = ImMax(1.0f, IM_FLOOR(square_sz / 6.0f));
		RenderCheckMark(window->DrawList, check_bb.Min + ImVec2(pad, pad), check_col, square_sz - pad * 2.0f);
	}

	ImVec2 label_pos = ImVec2(check_bb.Max.x + style.ItemInnerSpacing.x, check_bb.Min.y + style.FramePadding.y);
	if (g.LogEnabled)
		LogRenderedText(&label_pos, mixed_value ? "[~]" : *v ? "[x]" : "[ ]");
	if (label_size.x > 0.0f)
		RenderText(label_pos, label);

	IMGUI_TEST_ENGINE_ITEM_INFO(id, label, g.LastItemData.StatusFlags | ImGuiItemStatusFlags_Checkable | (*v ? ImGuiItemStatusFlags_Checked : 0));
	return pressed;
}

bool ImGui::SliderFloat_2(const char* label, float* v, float v_min, float v_max, const char* format, ImGuiSliderFlags flags) {
	return SliderScalar(label, ImGuiDataType_Float, v, &v_min, &v_max, format, flags);
}
bool ImGui::SliderInt_2(const char* label, int* v, int v_min, int v_max, const char* format, ImGuiSliderFlags flags) {
	return SliderScalar(label, ImGuiDataType_S32, v, &v_min, &v_max, format, flags);
}

bool ImGuiTextFilter2::Draw2(const char* label, float width) {
	if (width != 0.0f)
		ImGui::SetNextItemWidth(width);

	std::string id = std::string("##Input_") += label;
	bool value_changed = ImGui::InputTextWithHint(id.c_str(), label, InputBuf, IM_ARRAYSIZE(InputBuf));
	if (value_changed)
		Build();
	return value_changed;
}

bool ImGui::Hotkey(const char* label, int& key, float samelineOffset, const ImVec2& size) {
	ImGuiWindow* window = GetCurrentWindow();
	if (window->SkipItems) return false;

	ImGuiContext& g = *GImGui;
	ImGuiIO& io = g.IO;
	const ImGuiStyle& style = g.Style;
	const ImGuiID id = window->GetID(label);
	const ImVec2 label_size = CalcTextSize(label, NULL, true);

	TextUnformatted(label);
	SameLine(samelineOffset);

	Button(key == 0 ? "..." : StringH::vkToString(key).c_str(), size);
	if (IsItemHovered()) {
		for (auto i = VK_MBUTTON; i <= VK_PACKET; i++) {
			//if (io.KeysDown[i]) {
			if (i == VK_ESCAPE) continue;
			if (GetAsyncKeyState(i) & 0x8000) { // 0x8000 Flag checks if Key is currently being hold
				key = i;
			}
		}
	}

	return true;
}

void ImGui::chromaText(std::string text, float sat, float value, float alpha, float offset, float speed, float range) {
	for (int i = 0; i < text.length(); i++) {
		char c = text.c_str()[i];
		std::string s(1, text.at(i));
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(-0.5, 4)); // not the best way, calculating string width will be slightly inaccurate
		float r, g, b;
		ColorH::HSVtoRGB(ColorH::getTimeHue(i * range, speed, offset), sat, value, r, g, b);
		ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(r, g, b, alpha));
		Text(s.c_str());
		ImGui::PopStyleColor();

		if (i != text.length() - 1) ImGui::SameLine();
		ImGui::PopStyleVar();
	}
}