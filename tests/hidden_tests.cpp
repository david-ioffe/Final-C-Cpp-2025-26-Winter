#include <vector>
#include <climits>
#include "../grader/interface.h"

int reference_sum(const std::vector<int>& v);

bool run_hidden_tests()
{
    std::vector<std::vector<int>> tests = {
        {100,200,300},
        {-2,-4,-6},
        {1},
        {},
        {INT_MAX,2}
    };

    for (auto& t : tests)
    {
        if (sum_even(t) != reference_sum(t))
            return false;
    }

    return true;
}
