#include <vector>
#include "../grader/interface.h"

bool run_public_tests()
{
    if (sum_even({1,2,3,4}) != 6) return false;
    if (sum_even({}) != 0) return false;
    if (sum_even({1,3,5}) != 0) return false;

    return true;
}
