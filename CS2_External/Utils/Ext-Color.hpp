#pragma once

/*
struct RGB {
	unsigned char r, g, b; // values go from 0-255
	RGB() : r(0), g(0), b(0) { }
	RGB(unsigned char _r, unsigned char _g, unsigned char _b) : r(_r), g(_g), b(_b) { }
};
*/


struct RGBA {
	unsigned char r, g, b, a; // values go from 0-255
	RGBA() : r(0), g(0), b(0), a(0) { }
	RGBA(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a) : r(_r), g(_g), b(_b), a(_a) { }
};

struct HSV {
	unsigned char h, s, v; // values go from 0-255
	HSV() : h(0), s(0), v(0) { }
	HSV(unsigned char _h, unsigned char _s, unsigned char _v) : h(_h), s(_s), v(_v) { }
};

struct HSVA {
	unsigned char h, s, v, a; // values go from 0-255
	HSVA() : h(0), s(0), v(0), a(0) { }
	HSVA(unsigned char _h, unsigned char _s, unsigned char _v, unsigned char _a) : h(_h), s(_s), v(_v), a(_a) { }
};

namespace ColorH {
	// Convert rgb floats ([0-1],[0-1],[0-1]) to hsv floats ([0-1],[0-1],[0-1]), from Foley & van Dam p593
	void RGBtoHSV(float r, float g, float b, float& out_h, float& out_s, float& out_v);
	// Convert hsv floats ([0-1],[0-1],[0-1]) to rgb floats ([0-1],[0-1],[0-1]), from Foley & van Dam p593
	void HSVtoRGB(float h, float s, float v, float& out_r, float& out_g, float& out_b);

	float getTimeHue(float moveSpeed, float speed, float offset = 0);
};