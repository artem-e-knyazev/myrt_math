#include <gtest/gtest.h>
#include "myrt-math/vec4.hpp"
#include "common.hpp"

namespace {
    TEST(vec4, unary_plus) {
        ASSERT_EQ(+Vec4(1.f, 2.f, 3.f), Vec4(1.f, 2.f, 3.f));
        ASSERT_EQ(+Vec4(-1.f, -2.f, -3.f), Vec4(-1.f, -2.f, -3.f));
    }

    TEST(vec4, unary_minus) {
        ASSERT_EQ(-Vec4( 1.f,  2.f,  3.f), Vec4(-1.f, -2.f, -3.f));
        ASSERT_EQ(-Vec4( 1.f,  2.f, -3.f), Vec4(-1.f, -2.f,  3.f));
        ASSERT_EQ(-Vec4( 1.f, -2.f,  3.f), Vec4(-1.f,  2.f, -3.f));
        ASSERT_EQ(-Vec4( 1.f, -2.f, -3.f), Vec4(-1.f,  2.f,  3.f));
        ASSERT_EQ(-Vec4(-1.f,  2.f,  3.f), Vec4( 1.f, -2.f, -3.f));
        ASSERT_EQ(-Vec4(-1.f,  2.f, -3.f), Vec4( 1.f, -2.f,  3.f));
        ASSERT_EQ(-Vec4(-1.f, -2.f,  3.f), Vec4( 1.f,  2.f, -3.f));
        ASSERT_EQ(-Vec4(-1.f, -2.f, -3.f), Vec4( 1.f,  2.f,  3.f));
    }

    TEST(vec4, self_mul) {
        auto v1 = Vec4(2.f, 4.f, 6.f);
        v1 *= 2.f;
        auto v2 = Vec4(2.f, 4.f, 6.f);
        v2 *= 0.5f;
        ASSERT_EQ(v1, Vec4(4.f, 8.f, 12.f));
        ASSERT_EQ(v2, Vec4(1.f, 2.f, 3.f));
    }
    
    TEST(vec4, self_div) {
        auto v1 = Vec4(2.f, 4.f, 6.f);
        v1 /= 0.5f;
        auto v2 = Vec4(2.f, 4.f, 6.f);
        v2 /= 2;
        ASSERT_EQ(v1, Vec4(4.f, 8.f, 12.f));
        ASSERT_EQ(v2, Vec4(1.f, 2.f, 3.f));
    }

    TEST(vec4, binary_scalar_mul_rvalue) {
        ASSERT_EQ(Vec4(2.f, 4.f, 6.f) * 2.f, Vec4(4.f, 8.f, 12.f));
        ASSERT_EQ(Vec4(2.f, 4.f, 6.f) * 0.5f, Vec4(1.f, 2.f, 3.f));
        ASSERT_EQ(2.f * Vec4(2.f, 4.f, 6.f), Vec4(4.f, 8.f, 12.f));
        ASSERT_EQ(0.5f * Vec4(2.f, 4.f, 6.f), Vec4(1.f, 2.f, 3.f));
    }

    TEST(vec4, binary_scalar_div_rvalue) {
        ASSERT_EQ(Vec4(2.f, 4.f, 6.f) / 0.5f, Vec4(4.f, 8.f, 12.f));
        ASSERT_EQ(Vec4(2.f, 4.f, 6.f) / 2.f, Vec4(1.f, 2.f, 3.f));
    }

    TEST(vec4, binary_vector_add_rvalue) {
        ASSERT_EQ(Vec4(1.f, 2.f, 3.f) + Vec4(2.f, 3.f, 4.f),
                  Vec4(3.f, 5.f, 7.f));
    }

    TEST(vec4, binary_vector_add_lvalue) {
        auto op1_check = Vec4(3.f, 6.f, 9.f);
        auto op1 = op1_check;
        auto op2_check = Vec4(2.f, 4.f, 8.f);
        auto op2 = op2_check;
        auto res = Vec4(5.f, 10.f, 17.f);
        ASSERT_EQ(op1 + op2, res);
        ASSERT_EQ(op1, op1_check);
        ASSERT_EQ(op2, op2_check);
    }

    TEST(vec4, binary_vector_sub_rvalue) {
        ASSERT_EQ(Vec4(1.f, 2.f, 3.f) - Vec4(2.f, 3.f, 4.f),
                  Vec4(-1.f, -1.f, -1.f));
    }

    TEST(vec4, binary_vector_sub_lvalue) {
        auto op1_check = Vec4(3.f, 6.f, 9.f);
        auto op1 = op1_check;
        auto op2_check = Vec4(2.f, 4.f, 8.f);
        auto op2 = op2_check;
        auto res = Vec4(1.f, 2.f, 1.f);
        ASSERT_EQ(op1 - op2, res);
        ASSERT_EQ(op1, op1_check);
        ASSERT_EQ(op2, op2_check);
    }

    TEST(vec4, dot_basis) {
        auto vx = Vec4(1.f, 0.f, 0.f);
        auto vy = Vec4(0.f, 1.f, 0.f);
        auto vz = Vec4(0.f, 0.f, 1.f);
        auto zero = Vec4(0.f, 0.f, 0.f);

        ASSERT_EQ(Dot3(vx, vx), 1.f);
        ASSERT_EQ(Dot3(vx, vy), 0.f);
        ASSERT_EQ(Dot3(vx, vz), 0.f);
        ASSERT_EQ(Dot3(vx, zero), 0.f);

        ASSERT_EQ(Dot3(vy, vx), 0.f);
        ASSERT_EQ(Dot3(vy, vy), 1.f);
        ASSERT_EQ(Dot3(vy, vz), 0.f);
        ASSERT_EQ(Dot3(vy, zero), 0.f);

        ASSERT_EQ(Dot3(vz, vx), 0.f);
        ASSERT_EQ(Dot3(vz, vy), 0.f);
        ASSERT_EQ(Dot3(vz, vz), 1.f);
        ASSERT_EQ(Dot3(vz, zero), 0.f);
    }

    TEST(vec4, dot_arbitrary) {
        auto v1 = Vec4(1.f, 3.f, 5.f);
        auto v2 = Vec4(2.f, 4.f, 8.f);
        ASSERT_EQ(Dot3(v1, v2), 54.f);
        ASSERT_EQ(Dot3(v2, v1), 54.f);
    }

    TEST(vec4, cross_basis) {
        auto vx = Vec4(1.f, 0.f, 0.f);
        auto vy = Vec4(0.f, 1.f, 0.f);
        auto vz = Vec4(0.f, 0.f, 1.f);
        auto zero = Vec4(0.f, 0.f, 0.f);

        ASSERT_EQ(Cross(vx, vx), zero);
        ASSERT_EQ(Cross(vx, vy), vz);
        ASSERT_EQ(Cross(vx, vz), -vy);

        ASSERT_EQ(Cross(vy, vx), -vz);
        ASSERT_EQ(Cross(vy, vy), zero);
        ASSERT_EQ(Cross(vy, vz), vx);

        ASSERT_EQ(Cross(vz, vx), vy);
        ASSERT_EQ(Cross(vz, vy), -vx);
        ASSERT_EQ(Cross(vz, vz), zero);
    }

    TEST(vec4, length_basis) {
        auto vx = Vec4(1.f, 0.f, 0.f);
        auto vy = Vec4(0.f, 1.f, 0.f);
        auto vz = Vec4(0.f, 0.f, 1.f);
        auto zero = Vec4(0.f, 0.f, 0.f);

        ASSERT_EQ(Length(vx), 1.f);
        ASSERT_EQ(Length(-vx), 1.f);
        ASSERT_EQ(Length(vy), 1.f);
        ASSERT_EQ(Length(-vy), 1.f);
        ASSERT_EQ(Length(vz), 1.f);
        ASSERT_EQ(Length(-vz), 1.f);
        ASSERT_EQ(Length(zero), 0.f);
        ASSERT_EQ(Length(-zero), 0.f);
    }

    TEST(vec4, length_arbitrary) {
        ASSERT_EQ(Length(Vec4( 3.f,  4.f,  0.f)), 5.f);
        ASSERT_EQ(Length(Vec4(-3.f,  4.f,  0.f)), 5.f);
        ASSERT_EQ(Length(Vec4( 3.f, -4.f,  0.f)), 5.f);
        ASSERT_EQ(Length(Vec4(-3.f, -4.f,  0.f)), 5.f);
        ASSERT_EQ(Length(Vec4( 3.f,  0.f,  4.f)), 5.f);
        ASSERT_EQ(Length(Vec4(-3.f,  0.f,  4.f)), 5.f);
        ASSERT_EQ(Length(Vec4( 3.f, -4.f,  0.f)), 5.f);
        ASSERT_EQ(Length(Vec4(-3.f, -4.f,  0.f)), 5.f);
        ASSERT_EQ(Length(Vec4( 0.f,  3.f,  4.f)), 5.f);
        ASSERT_EQ(Length(Vec4( 0.f, -3.f,  4.f)), 5.f);
        ASSERT_EQ(Length(Vec4( 0.f,  3.f, -4.f)), 5.f);
        ASSERT_EQ(Length(Vec4( 0.f, -3.f, -4.f)), 5.f);
    }

    TEST(vec4, distance_arbitrary) {
        auto p0 = Vec4(0.f, 0.f, 0.f);
        auto p1 = Vec4(3.f, 4.f, 0.f);
        auto p2 = Vec4(-3.f, 4.f, 0.f);
        ASSERT_EQ(Distance(p0, p1), 5.0f);
        ASSERT_EQ(Distance(p1, p0), 5.0f);
        ASSERT_EQ(Distance(p0, p2), 5.0f);
        ASSERT_EQ(Distance(p2, p0), 5.0f);
    }

    TEST(vec4, normalize_basis) {
        auto vx = Vec4(1.f, 0.f, 0.f);
        auto vy = Vec4(0.f, 1.f, 0.f);
        auto vz = Vec4(0.f, 0.f, 1.f);
        ASSERT_EQ(Normalize(vx), vx);
        ASSERT_EQ(Normalize(vy), vy);
        ASSERT_EQ(Normalize(vz), vz);
    }

    TEST(vec4, normalize_arbitrary) {
        ASSERT_EQ(Normalize(Vec4( 3.f,  4.f,  0.f)), Vec4( .6f,  .8f,  0.f));
        ASSERT_EQ(Normalize(Vec4( 3.f, -4.f,  0.f)), Vec4( .6f, -.8f,  0.f));
        ASSERT_EQ(Normalize(Vec4( 3.f,  4.f,  0.f)), Vec4( .6f,  .8f,  0.f));
        ASSERT_EQ(Normalize(Vec4(-3.f, -4.f,  0.f)), Vec4(-.6f, -.8f,  0.f));
    }
}

