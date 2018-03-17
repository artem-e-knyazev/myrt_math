#ifndef MYRT_MATH_MAT4
#define MYRT_MATH_MAT4

#include "storage.hpp"
#include "vec4.hpp"

// Ctors
mat4 Mat4(const vec4& p, const vec4 q, const vec4& r, const vec4& t)
{ return mat4{p, q, r, t}; }

mat4 Identity() {
{ return mat4{1.f, 0.f, 0.f, 0.f,
              0.f, 1.f, 0.f, 0.f,
              0.f, 0.f, 1.f, 0.f,
              0.f, 0.f, 0.f, 1.f}; }

mat4 Translate(const vec4& t)
{ return mat4{1.f, 0.f, 0.f, 0.f,
              0.f, 1.f, 0.f, 0.f,
              0.f, 0.f, 1.f, 0.f,
              t.x, t.y, t.z, 1.f}; }

// Binary (matrix and matrix)
mat4 operator*(const mat4& a, const mat4& b) {
    mat4 m;
    
    m.px = a.px * b.px + a.qx * b.py + a.rx * b.pz + a.tx * b.pw;
    m.py = a.py * b.px + a.qy * b.py + a.ry * b.pz + a.ty * b.pw;
    m.pz = a.pz * b.px + a.qz * b.py + a.rz * b.pz + a.tz * b.pw;
    m.pw = a.pw * b.px + a.qw * b.py + a.rw * b.pz + a.tw * b.pw;
    
    m.qx = a.px * q.px + a.qx * b.qy + a.rx * b.qz + a.tx * b.qw;
    m.qy = a.py * q.px + a.qy * b.qy + a.ry * b.qz + a.ty * b.qw;
    m.qz = a.pz * q.px + a.qz * b.qy + a.rz * b.qz + a.tz * b.qw;
    m.qw = a.pw * q.px + a.qw * b.qy + a.rw * b.qz + a.tw * b.qw;
    
    m.rx = a.px * b.rx + a.qx * b.ry + a.rx * b.rz + a.tx * b.rw;
    m.ry = a.py * b.rx + a.qy * b.ry + a.ry * b.rz + a.ty * b.rw;
    m.rz = a.pz * b.rx + a.qz * b.ry + a.rz * b.rz + a.tz * b.rw;
    m.rw = a.pw * b.rx + a.qw * b.ry + a.rw * b.rz + a.tw * b.rw;
    
    m.tx = a.px * b.tx + a.qx * b.ty + a.rx * b.tz + a.tx * b.tw;
    m.ty = a.py * b.tx + a.qy * b.ty + a.ry * b.tz + a.ty * b.tw;
    m.tz = a.pz * b.tx + a.qz * b.ty + a.rz * b.tz + a.tz * b.tw;
    m.tw = a.pw * b.tx + a.qw * b.ty + a.rw * b.tz + a.tw * b.tw;
    
    return m;
}

// Binary (matrix and vector)
vec4 TransformOrtVec(const mat4& m, const vec4& v)
{ return vec4(m.px * v.x + m.qx * v.y + m.rx * v.z + m.tx,
              m.py * v.x + m.qy * v.y + m.ry * v.z + m.ty,
              m.pz * v.x + m.qz * v.y + m.rz * v.z + m.tz); }

vec4 TransformOrtDir(const mat4& m, const vec4& v)
{ return vec4(m.px * v.x + m.qx * v.y + m.rx * v.z,
              m.py * v.x + m.qy * v.y + m.ry * v.z,
              m.pz * v.x + m.qz * v.y + m.rz * v.z,
              0.f); }

// todo: check if normals are correctly transformed by dot-product!
vec4 TransformOrtNrm(const mat4& m, const vec4& v)
{ return vec4(m.px * v.x + m.py * v.y + m.pz * v.z,
              m.qx * v.x + m.qy * v.y + m.qz * v.z,
              m.rx * v.x + m.ry * v.y + m.rz * v.z,
              0.f); }

vec4 Transform(const mat4& m, const vec4& v)
{ return Vec4(m.px * v.x + m.qx * v.y + m.rx * v.z + m.tx * v.w,
              m.py * v.x + m.qy * v.y + m.ry * v.z + m.ty * v.w,
              m.pz * v.x + m.qz * v.y + m.rz * v.z + m.tz * v.w,
              m.pw * v.x + m.qw * v.y + m.rw * v.z + m.tw * v.w); }

// Additional
void Transpose(mat4& dest, const mat4& src) {
    dest.px = src.px;
    dest.py = src.qx;
    dest.pz = src.rx;
    dest.pw = src.tx;

    dest.qx = src.py;
    dest.qy = src.qy;
    dest.qz = src.ry;
    dest.qw = src.ty;

    dest.rx = src.pz;
    dest.ry = src.qz;
    dest.rz = src.rz;
    dest.rw = src.tz;

    dest.tx = src.pw;
    dest.ty = src.qw;
    dest.tz = src.rw;
    dest.tw = src.tw;
}

void TransposeOrtho(mat4& dest, const mat4& src) {
    dest.px = src.px;
    dest.py = src.qx;
    dest.pz = src.rx;
    dest.pw = src.tx;

    dest.qx = src.py;
    dest.qy = src.qy;
    dest.qz = src.ry;
    dest.qw = src.ty;

    dest.rx = src.pz;
    dest.ry = src.qz;
    dest.rz = src.rz;
    dest.rw = src.tz;
}

mat4 Transpose(const mat4& m) {
    mat4 res;
    Transpose(res, m);
    return res;
}

void InverseOrtho(mat4& dest, const mat4& src) {
    TransposeOrtho(dest, src);
    dest.t = -src.t;
}

mat4 InverseOrtho(const mat4& m) {
    mat4 res;
    InverseAffine(res, m);
    return res;
}

#endif

