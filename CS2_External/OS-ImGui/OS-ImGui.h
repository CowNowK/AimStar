#pragma once
#include "OS-ImGui_External.h"

namespace OSImGui
{
#ifdef _CONSOLE
	class OSImGui : public OSImGui_External, public Singleton<OSImGui>
#else
	class OSImGui : public OSImGui_Internal, public Singleton<OSImGui>
#endif
	{
	public:
		bool LoadTextureFromFile(const char* filename, ID3D11ShaderResourceView** out_srv, int* out_width, int* out_height);
		bool LoadTextureFromMemory(unsigned char* Memory, UINT size, ID3D11ShaderResourceView** out_srv, int* out_width, int* out_height);

		void ShowRawImage(unsigned char* image, int width, int height);
		// 文本
		void Text(std::string Text, Vec2 Pos, ImColor Color, float FontSize = 15, bool KeepCenter = false);
		void MyText(std::string Text, bool isCenter);
		// 描边文本
		void StrokeText(std::string Text, Vec2 Pos, ImColor Color, float FontSize = 15, bool KeepCenter = false);
		// 矩形
		void Rectangle(Vec2 Pos, Vec2 Size, ImColor Color, float Thickness, float Rounding = 0);
		void RectangleFilled(Vec2 Pos, Vec2 Size, ImColor Color, float Rounding = 0, int Nums = 15);
		void RectangleFilledGraident(Vec2 Pos, Vec2 Size, ImColor BgColor, ImColor TopColor, ImColor BotColor, float Rounding, int Nums = 15);
		// 线
		void Line(Vec2 From, Vec2 To, ImColor Color, float Thickness);
		// 圆形
		void Circle(Vec2 Center, float Radius, ImColor Color,float Thickness, int Num = 50);
		void CircleFilled(Vec2 Center, float Radius, ImColor Color, int Num = 50);
		// 连接点
		void ConnectPoints(std::vector<Vec2> Points, ImColor Color, float Thickness);
		// 圆弧
		void Arc(ImVec2 Center, float Radius, ImColor Color, float Thickness, float Aangle_begin, float Angle_end, float Nums = 15);
		// 勾选框
		void MyCheckBox(const char* str_id, bool* v);
		void MyCheckBox2(const char* str_id, bool* v);
		void MyCheckBox3(const char* str_id, bool* v);
		void MyCheckBox4(const char* str_id, bool* v);
		// 阴影矩形
		void ShadowRectFilled(Vec2 Pos, Vec2 Size, ImColor RectColor, ImColor ShadowColor, float ShadowThickness, Vec2 ShadowOffset, float Rounding = 0);
		// 阴影圆形
		void ShadowCircle(Vec2 Pos, float Radius, ImColor CircleColor, ImColor ShadowColor, float ShadowThickness, Vec2 ShadowOffset, int Num = 30);
		// 圆头滑动条
		bool SliderScalarEx1(const char* label, ImGuiDataType data_type, void* p_data, const void* p_min, const void* p_max, const char* format, ImGuiSliderFlags flags);
		bool SliderScalarEx2(const char* label, ImGuiDataType data_type, void* p_data, const void* p_min, const void* p_max, const char* format, ImGuiSliderFlags flags);

		// Open webpage button
		void OpenWebpage(const char* url);
		void OpenWebpageButton(const char* label, const char* url);

		void MyProgressBar(float fraction, const ImVec2& Size, const char* overlay, ImVec4 Color);
		void SwitchButton(const char* str_id, bool* v);
	};
}

inline OSImGui::OSImGui& Gui = OSImGui::OSImGui::get();