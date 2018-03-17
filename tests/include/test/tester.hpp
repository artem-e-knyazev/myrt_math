#ifndef MYRT_TEST_TESTER
#define MYRT_TEST_TESTER

#include <string>
#include <list>
#include <iostream>
#include <functional>
#include <memory>

#include "exceptions/myrt_test_exception.hpp"

class Tester {
public:
    typedef std::function<void()> test_fn;
private:
    static std::unique_ptr<Tester> p_tester;
    Tester() {}

    struct test_record {
        std::string name;
        test_fn fn;

        test_record(std::string name, test_fn fn)
            : name(std::move(name)), fn(std::move(fn)) {}
    };
    std::list<test_record> m_tests;
public:
    Tester(const Tester&) = delete;
    Tester& operator=(const Tester&) = delete;

    static Tester* get_instance() {
        if (!p_tester)
            p_tester.reset(new Tester);
        return p_tester.get();
    }

    void add_test(std::string name, test_fn fn) {
        m_tests.emplace_back(std::move(name), std::move(fn));
    }

    unsigned int run() {
        unsigned int success = 0;
        unsigned int failed = 0;
        for (const auto& test: m_tests) {
            try {
                test.fn();
                std::cerr << "+ " << test.name << " success" << std::endl;
                ++success;
            } catch (myrt_test_exception& ex) {
                std::cerr << "- " << test.name << " (" << ex.file() << ":" << ex.line() << ") " << ex.what() << std::endl;
                ++failed;
            } catch (std::exception& ex) {
                std::cerr << "? " << test.name << " exited with exception: " << ex.what() << std::endl;
                ++failed;
            }
        }
        std::cout << m_tests.size() << " tests executed, " << failed << " failed, " << success << " succeeded" << std::endl;
        return failed;
    }
};

std::unique_ptr<Tester> Tester::p_tester = nullptr;

#define TESTER Tester::get_instance()

#endif

