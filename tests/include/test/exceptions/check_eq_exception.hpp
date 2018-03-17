#ifndef MYRT_TEST_CHECK_EQ_EXCEPTION
#define MYRT_TEST_CHECK_EQ_EXCEPTION

#include <sstream>
#include "myrt_test_exception.hpp"

class check_eq_exception : public myrt_test_exception {
private:
    std::string m_what;
public:
    template<typename TLeft, typename TRight>
    check_eq_exception(TLeft left, TRight right, const char* file, int line)
        : myrt_test_exception(file, line)
    {
        std::stringstream out;
        out << "comparison error: " << left << " not equal " << right;
        m_what = std::move(out.str());
    }

    virtual const char* what() const noexcept {
        return m_what.c_str();
    }
};

#endif

