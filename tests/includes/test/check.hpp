#ifndef MYRT_TEST_CHECK
#define MYRT_TEST_CHECK

#include <cmath>
#include "math/storage.hpp"

bool check_eq(unsigned char lhs, unsigned char rhs) {
    return lhs == rhs;
}

bool check_eq(float lhs, float rhs, float eps = 10e-6) {
    return std::abs(rhs-lhs) < eps;
}

bool check_eq(const vec4& lhs, const vec4& rhs) {
    return check_eq(lhs.x, rhs.x) &&
           check_eq(lhs.y, rhs.y) &&
           check_eq(lhs.z, rhs.z) &&
           check_eq(lhs.w, rhs.w);
}

bool check_eq(const color& lhs, const color& rhs) {
    return check_eq(lhs.r, rhs.r) &&
           check_eq(lhs.g, rhs.g) &&
           check_eq(lhs.b, rhs.b) &&
           check_eq(lhs.a, rhs.a);
}

bool check_eq(const rgb_color& lhs, const rgb_color& rhs) {
    return check_eq(lhs.r, rhs.r) &&
           check_eq(lhs.g, rhs.g) &&
           check_eq(lhs.b, rhs.b) &&
           check_eq(lhs.a, rhs.a);
}

bool check_eq(const ray4& lhs, const ray4& rhs) {
    return check_eq(lhs.m_orig, rhs.m_orig) &&
           check_eq(lhs.m_dir, rhs.m_dir);
}

#endif

