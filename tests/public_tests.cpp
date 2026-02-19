#include <iostream>
#include <vector>
#include "../grader/interface.h"

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

struct TestCase {
    std::vector<int> input;
    int expected;
};

int run_public_tests()
{
    std::vector<TestCase> tests = {
        {{1,2,3,4}, 6},
        {{}, 0},
        {{1,3,5}, 0},
        {{2,2,2}, 6}
    };

    int passed = 0;
    int test_number = 1;

    std::cout << "\n===== PUBLIC TESTS =====\n";

    for (const auto& t : tests)
    {
        int actual = sum_even(t.input);

        if (actual == t.expected)
        {
            std::cout << GREEN
                      << "Test " << test_number << " PASSED"
                      << RESET << "\n";
            passed++;
        }
        else
        {
            std::cout << RED
                      << "Test " << test_number << " FAILED\n"
                      << "  Expected: " << t.expected << "\n"
                      << "  Actual:   " << actual
                      << RESET << "\n";
        }

        test_number++;
    }

    std::cout << "Public Passed: "
              << passed << "/" << tests.size() << "\n";

    return passed;
}
