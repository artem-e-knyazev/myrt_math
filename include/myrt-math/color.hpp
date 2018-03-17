#ifndef MYRT_MATH_COLOR
#define MYRT_MATH_COLOR

#include <cmath>
#include "storage.hpp"

// `color` type ctor-functions and operations
color Color(float c)
{ return color{c, c, c, 1.0}; }

color Color(float r, float g, float b)
{ return color{r, g, b, 1.0}; }

color Color(float r, float g, float b, float a)
{ return color{r, g, b, a}; }

color& operator+=(color& lhs, const color& rhs)
{ lhs.r += rhs.r; lhs.g += rhs.g; lhs.b += rhs.b; return lhs; }

color& operator*=(color& lhs, const color& rhs)
{ lhs.r *= rhs.r; lhs.g *= rhs.g; lhs.b *= rhs.b; return lhs; }

color& operator*=(color& lhs, float rhs)
{ lhs.r *= rhs; lhs.g *= rhs; lhs.b *= rhs; return lhs; }

color& operator/=(color& lhs, float rhs)
{ float inv = 1.f / rhs; return lhs *= inv; }

color operator+(const color& lhs, const color& rhs)
{ return Color(lhs.r + rhs.r, lhs.g + rhs.g, lhs.b + rhs.b); }

color operator*(const color& lhs, const color& rhs)
{ return Color(lhs.r * rhs.r, lhs.g * rhs.g, lhs.b * rhs.b); }

color operator*(const color& lhs, float rhs)
{ return Color(lhs.r * rhs, lhs.g * rhs, lhs.b * rhs); }

color operator*(float lhs, const color& rhs)
{ return Color(lhs * rhs.r, lhs * rhs.g, lhs * rhs.b); }

color operator/(const color& lhs, float rhs)
{ return Color(lhs.r / rhs, lhs.g / rhs, lhs.b / rhs); }

color Gamma(const color& c, float g) {
    float inv = 1.f / g;
    return Color(std::pow(c.r, inv), std::pow(c.g, inv), std::pow(c.b, inv));
}

// `rgb_color` type ctor-functions

rgb_color RGBColor(unsigned char a)
{ return rgb_color{a, a, a, 255}; }

rgb_color RGBColor(unsigned char r, unsigned char g, unsigned char b)
{ return rgb_color{r, g, b, 255}; }

rgb_color RGBColor(const color& c) {
    return RGBColor(
        std::clamp(int(255.99f * c.r), 0, 255),
        std::clamp(int(255.99f * c.g), 0, 255),
        std::clamp(int(255.99f * c.b), 0, 255)
    );
}

// Constants
static const color black   = Color(0.f, 0.f, 0.f);
static const color white   = Color(1.f, 1.f, 1.f);
static const color red     = Color(1.f, 0.f, 0.f);
static const color green   = Color(0.f, 1.f, 0.f);
static const color blue    = Color(0.f, 0.f, 1.f);
static const color magenta = red + blue;
static const color yellow  = red + green;
static const color cyan    = green + blue;

#endif

