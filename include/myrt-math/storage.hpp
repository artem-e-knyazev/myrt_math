#ifndef MYRT_MATH_STORAGE
#define MYRT_MATH_STORAGE

#include <iostream>

struct vec4 {
    float x, y, z, w;
};

union mat4 {
    struct {
        float px, py, pz, pw, 
              qx, qy, qz, qw, 
              rx, ry, rz, rw, 
              tx, ty, tz, tw;
    };
    struct { vec4 p, q, r, t; };
};

struct ray4 {
    vec4 m_orig;
    vec4 m_dir;
};

struct color {
    float r, g, b, a;
};

struct rgb_color {
    unsigned char r, g, b, a;
};


std::ostream& operator<<(std::ostream& out, const vec4& v)
{ return out << "vec4(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")"; }

std::ostream& operator<<(std::ostream& out, const mat4& m)
{ return out << "mat4(p=" << m.p << ", q=" << m.q << ", r=" << m.r << ", t=" << m.t << ")"; }

std::ostream& operator<<(std::ostream& out, const ray4& r)
{ return out << "ray4(m_orig=" << r.m_orig << ", m_dir=" << r.m_dir << ")"; }

std::ostream& operator<<(std::ostream& out, const color& c)
{ return out << "color(" << c.r << ", " << c.g << ", " << c.b << ", " << c.a << ")"; }

std::ostream& operator<<(std::ostream& out, const rgb_color& c)
{ return out << "rgb_color(" << int(c.r) << ", " << int(c.g) << ", " << int(c.b) << ", " << int(c.a) << ")"; }

#endif

