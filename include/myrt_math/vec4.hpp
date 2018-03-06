#ifndef MYRT_MATH_VEC4
#define MYRT_MATH_VEC4

#include "storage.hpp"

// Ctors

vec4 Vec4(float x, float y, float z, float w)
{ return vec4{x, y, z, w}; }

vec4 Vec4(float x, float y, float z)
{ return vec4{x, y, z, 1.f}; }

vec4 Vec4()
{ return vec4{0.f, 0.f, 0.f, 1.f}; }

// Unary ops

vec4 operator+(const vec4& v)
{ return v; }

vec4 operator-(const vec4& v)
{ return Vec4(-v.x, -v.y, -v.z); }

// Self-assigning

vec4& operator*=(vec4& lhs, float rhs)
{ lhs.x *= rhs; lhs.y *= rhs; lhs.z *= rhs; return lhs; }

vec4& operator/=(vec4& lhs, float rhs)
{ float inv = 1.f / rhs; lhs.x *= inv; lhs.y *= inv; lhs.z *= inv; return lhs; }

// Binary (vector and scalar)

vec4 operator*(float lhs, const vec4& rhs)
{ return Vec4(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z); }

vec4 operator*(const vec4& lhs, float rhs)
{ return rhs * lhs; }

vec4 operator/(const vec4& lhs, float rhs)
{ float inv = 1.f / rhs; return inv * lhs; }

// Binary (vector and vector)

vec4 operator+(const vec4& lhs, const vec4& rhs)
{ return Vec4(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z); }

vec4 operator-(const vec4& lhs, const vec4& rhs)
{ return Vec4(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z); }

float Dot3(const vec4& lhs, const vec4& rhs)
{ return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z; }

vec4 Cross(const vec4& lhs, const vec4& rhs)
{ return Vec4(lhs.y * rhs.z - lhs.z * rhs.y,
              lhs.z * rhs.x - lhs.x * rhs.z,
              lhs.x * rhs.y - lhs.y * rhs.x); }

// Additional

float Length(const vec4& v)
{ return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z); }

float Distance(const vec4& a, const vec4& b)
{ return Length(a-b); }

vec4 Normalize(const vec4& v)
{ float inv = 1.f / Length(v); return inv * v; }

#endif

