#ifndef MYRT_TEST_MYRT_TEST_EXCEPTION
#define MYRT_TEST_MYRT_TEST_EXCEPTION

#include <exception>

class myrt_test_exception : public std::exception
{
protected:
    std::string m_file;
    int m_line;
public:
    myrt_test_exception(std::string file, int line)
        : m_file(std::move(file)), m_line(line) {}

    const std::string& file() const { return m_file; }
    int line() const { return m_line; }
};

#endif

