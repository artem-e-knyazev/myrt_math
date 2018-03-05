#ifndef MYRT_TEST_ASSERT
#define MYRT_TEST_ASSERT

#include "exceptions/check_eq_exception.hpp"
#include "check.hpp"

template<typename TLeft, typename TRight>
void assert_eq_impl(TLeft lhs, TRight rhs, const char* file, int line) {
    if (!check_eq(lhs, rhs))
        throw check_eq_exception(lhs, rhs, file, line);
}

#define assert_eq(lhs, rhs) assert_eq_impl((lhs), (rhs), __FILE__, __LINE__);

#endif

