#include <iostream>
#include <vector>
#include <climits>
#include "../grader/interface.h"

int reference_sum(const std::vector<int>& v);

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

struct TestCase {
    std::vector<int> input;
    std::string reason;
};

int run_hidden_tests()
{
    std::vector<TestCase> tests = {
        {{100,200,300}, "Large positive numbers"},
        {{-2,-4,-6}, "Negative even numbers"},
        {{}, "Empty vector"},
        {{1}, "Single odd element"},
        {{INT_MAX,2}, "Edge case with INT_MAX"}
    };

    int passed = 0;
    int test_number = 1;

#ifdef REVIEW_MODE
    std::cout << "\n===== PRIVATE TESTS =====\n";
#endif

    for (const auto& t : tests)
    {
        int expected = reference_sum(t.input);
        int actual = sum_even(t.input);

        if (actual == expected)
        {
#ifdef REVIEW_MODE
            std::cout << GREEN
                      << "Private Test " << test_number << " PASSED"
                      << RESET << "\n";
#endif
            passed++;
        }
        else
        {
#ifdef REVIEW_MODE
            std::cout << RED
                      << "Private Test " << test_number << " FAILED\n"
                      << "  Reason:   " << t.reason << "\n"
                      << "  Expected: " << expected << "\n"
                      << "  Actual:   " << actual
                      << RESET << "\n";
#endif
        }

        test_number++;
    }

    return passed;
}
