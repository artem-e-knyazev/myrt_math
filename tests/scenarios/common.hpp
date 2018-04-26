static const float EPSILON = 10e-6;

bool check_eq(float lhs, float rhs) {
    return std::abs(lhs-rhs) < EPSILON;
}

bool operator==(const vec4& lhs, const vec4& rhs) {
    return check_eq(lhs.x, rhs.x) && check_eq(lhs.y, rhs.y) &&
        check_eq(lhs.z, rhs.z) && check_eq(lhs.w, rhs.w);
}

