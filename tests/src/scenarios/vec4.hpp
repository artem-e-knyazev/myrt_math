#include "myrt-math/vec4.hpp"

void add_vec4_scenarios() {
    TESTER->add_test("vector.unary.plus", []{
        assert_eq(+Vec4(1.f, 2.f, 3.f), Vec4(1.f, 2.f, 3.f));
        assert_eq(+Vec4(-1.f, -2.f, -3.f), Vec4(-1.f, -2.f, -3.f));
    });
    
    TESTER->add_test("vector.unary.minus", []{
        assert_eq(-Vec4( 1.f,  2.f,  3.f), Vec4(-1.f, -2.f, -3.f));
        assert_eq(-Vec4( 1.f,  2.f, -3.f), Vec4(-1.f, -2.f,  3.f));
        assert_eq(-Vec4( 1.f, -2.f,  3.f), Vec4(-1.f,  2.f, -3.f));
        assert_eq(-Vec4( 1.f, -2.f, -3.f), Vec4(-1.f,  2.f,  3.f));
        assert_eq(-Vec4(-1.f,  2.f,  3.f), Vec4( 1.f, -2.f, -3.f));
        assert_eq(-Vec4(-1.f,  2.f, -3.f), Vec4( 1.f, -2.f,  3.f));
        assert_eq(-Vec4(-1.f, -2.f,  3.f), Vec4( 1.f,  2.f, -3.f));
        assert_eq(-Vec4(-1.f, -2.f, -3.f), Vec4( 1.f,  2.f,  3.f));
    });

    TESTER->add_test("vector.self.mul", []{
        auto v1 = Vec4(2.f, 4.f, 6.f);
        v1 *= 2.f;
        auto v2 = Vec4(2.f, 4.f, 6.f);
        v2 *= 0.5f;
        assert_eq(v1, Vec4(4.f, 8.f, 12.f));
        assert_eq(v2, Vec4(1.f, 2.f, 3.f));
    });
    
    TESTER->add_test("vector.self.div", []{
        auto v1 = Vec4(2.f, 4.f, 6.f);
        v1 /= 0.5f;
        auto v2 = Vec4(2.f, 4.f, 6.f);
        v2 /= 2;
        assert_eq(v1, Vec4(4.f, 8.f, 12.f));
        assert_eq(v2, Vec4(1.f, 2.f, 3.f));
    });

    TESTER->add_test("vector.binary.scalar.mul.rvalue", []{
        assert_eq(Vec4(2.f, 4.f, 6.f) * 2.f, Vec4(4.f, 8.f, 12.f));
        assert_eq(Vec4(2.f, 4.f, 6.f) * 0.5f, Vec4(1.f, 2.f, 3.f));
        assert_eq(2.f * Vec4(2.f, 4.f, 6.f), Vec4(4.f, 8.f, 12.f));
        assert_eq(0.5f * Vec4(2.f, 4.f, 6.f), Vec4(1.f, 2.f, 3.f));
    });

    TESTER->add_test("vector.binary.scalar.div.rvalue", []{
        assert_eq(Vec4(2.f, 4.f, 6.f) / 0.5f, Vec4(4.f, 8.f, 12.f));
        assert_eq(Vec4(2.f, 4.f, 6.f) / 2.f, Vec4(1.f, 2.f, 3.f));
    });

    TESTER->add_test("vector.binary.vector.add.rvalue", []{
        assert_eq(Vec4(1.f, 2.f, 3.f) + Vec4(2.f, 3.f, 4.f),
                  Vec4(3.f, 5.f, 7.f));
    });

    TESTER->add_test("vector.binary.vector.add.lvalue", []{
        auto op1_check = Vec4(3.f, 6.f, 9.f);
        auto op1 = op1_check;
        auto op2_check = Vec4(2.f, 4.f, 8.f);
        auto op2 = op2_check;
        auto res = Vec4(5.f, 10.f, 17.f);
        assert_eq(op1 + op2, res);
        assert_eq(op1, op1_check);
        assert_eq(op2, op2_check);
    });

    TESTER->add_test("vector.binary.vector.sub.rvalue", []{
        assert_eq(Vec4(1.f, 2.f, 3.f) - Vec4(2.f, 3.f, 4.f),
                  Vec4(-1.f, -1.f, -1.f));
    });

    TESTER->add_test("vector.binary.vector.sub.lvalue", []{
        auto op1_check = Vec4(3.f, 6.f, 9.f);
        auto op1 = op1_check;
        auto op2_check = Vec4(2.f, 4.f, 8.f);
        auto op2 = op2_check;
        auto res = Vec4(1.f, 2.f, 1.f);
        assert_eq(op1 - op2, res);
        assert_eq(op1, op1_check);
        assert_eq(op2, op2_check);
    });

    TESTER->add_test("vector.dot.basis", []{
        auto vx = Vec4(1.f, 0.f, 0.f);
        auto vy = Vec4(0.f, 1.f, 0.f);
        auto vz = Vec4(0.f, 0.f, 1.f);
        auto zero = Vec4(0.f, 0.f, 0.f);

        assert_eq(Dot3(vx, vx), 1.f);
        assert_eq(Dot3(vx, vy), 0.f);
        assert_eq(Dot3(vx, vz), 0.f);
        assert_eq(Dot3(vx, zero), 0.f);

        assert_eq(Dot3(vy, vx), 0.f);
        assert_eq(Dot3(vy, vy), 1.f);
        assert_eq(Dot3(vy, vz), 0.f);
        assert_eq(Dot3(vy, zero), 0.f);

        assert_eq(Dot3(vz, vx), 0.f);
        assert_eq(Dot3(vz, vy), 0.f);
        assert_eq(Dot3(vz, vz), 1.f);
        assert_eq(Dot3(vz, zero), 0.f);
    });

    TESTER->add_test("vector.dot.arbitrary", []{
        auto v1 = Vec4(1.f, 3.f, 5.f);
        auto v2 = Vec4(2.f, 4.f, 8.f);
        assert_eq(Dot3(v1, v2), 54.f);
        assert_eq(Dot3(v2, v1), 54.f);
    });

    TESTER->add_test("vector.cross.basis", []{
        auto vx = Vec4(1.f, 0.f, 0.f);
        auto vy = Vec4(0.f, 1.f, 0.f);
        auto vz = Vec4(0.f, 0.f, 1.f);
        auto zero = Vec4(0.f, 0.f, 0.f);

        assert_eq(Cross(vx, vx), zero);
        assert_eq(Cross(vx, vy), vz);
        assert_eq(Cross(vx, vz), -vy);

        assert_eq(Cross(vy, vx), -vz);
        assert_eq(Cross(vy, vy), zero);
        assert_eq(Cross(vy, vz), vx);

        assert_eq(Cross(vz, vx), vy);
        assert_eq(Cross(vz, vy), -vx);
        assert_eq(Cross(vz, vz), zero);
    });

    TESTER->add_test("vector.length.basis", []{
        auto vx = Vec4(1.f, 0.f, 0.f);
        auto vy = Vec4(0.f, 1.f, 0.f);
        auto vz = Vec4(0.f, 0.f, 1.f);
        auto zero = Vec4(0.f, 0.f, 0.f);

        assert_eq(Length(vx), 1.f);
        assert_eq(Length(-vx), 1.f);
        assert_eq(Length(vy), 1.f);
        assert_eq(Length(-vy), 1.f);
        assert_eq(Length(vz), 1.f);
        assert_eq(Length(-vz), 1.f);
        assert_eq(Length(zero), 0.f);
        assert_eq(Length(-zero), 0.f);
    });

    TESTER->add_test("vector.length.arbitrary", []{
        assert_eq(Length(Vec4( 3.f,  4.f,  0.f)), 5.f);
        assert_eq(Length(Vec4(-3.f,  4.f,  0.f)), 5.f);
        assert_eq(Length(Vec4( 3.f, -4.f,  0.f)), 5.f);
        assert_eq(Length(Vec4(-3.f, -4.f,  0.f)), 5.f);
        assert_eq(Length(Vec4( 3.f,  0.f,  4.f)), 5.f);
        assert_eq(Length(Vec4(-3.f,  0.f,  4.f)), 5.f);
        assert_eq(Length(Vec4( 3.f, -4.f,  0.f)), 5.f);
        assert_eq(Length(Vec4(-3.f, -4.f,  0.f)), 5.f);
        assert_eq(Length(Vec4( 0.f,  3.f,  4.f)), 5.f);
        assert_eq(Length(Vec4( 0.f, -3.f,  4.f)), 5.f);
        assert_eq(Length(Vec4( 0.f,  3.f, -4.f)), 5.f);
        assert_eq(Length(Vec4( 0.f, -3.f, -4.f)), 5.f);
    });

    TESTER->add_test("vector.distance.arbitrary", []{
        auto p0 = Vec4(0.f, 0.f, 0.f);
        auto p1 = Vec4(3.f, 4.f, 0.f);
        auto p2 = Vec4(-3.f, 4.f, 0.f);
        assert_eq(Distance(p0, p1), 5.0f);
        assert_eq(Distance(p1, p0), 5.0f);
        assert_eq(Distance(p0, p2), 5.0f);
        assert_eq(Distance(p2, p0), 5.0f);
    });

    TESTER->add_test("vector.normalize.basis", []{
        auto vx = Vec4(1.f, 0.f, 0.f);
        auto vy = Vec4(0.f, 1.f, 0.f);
        auto vz = Vec4(0.f, 0.f, 1.f);
        assert_eq(Normalize(vx), vx);
        assert_eq(Normalize(vy), vy);
        assert_eq(Normalize(vz), vz);
    });

    TESTER->add_test("vector.length.arbitrary", []{
        assert_eq(Normalize(Vec4( 3.f,  4.f,  0.f)), Vec4( .6f,  .8f,  0.f));
        assert_eq(Normalize(Vec4( 3.f, -4.f,  0.f)), Vec4( .6f, -.8f,  0.f));
        assert_eq(Normalize(Vec4( 3.f,  4.f,  0.f)), Vec4( .6f,  .8f,  0.f));
        assert_eq(Normalize(Vec4(-3.f, -4.f,  0.f)), Vec4(-.6f, -.8f,  0.f));
    });
}

