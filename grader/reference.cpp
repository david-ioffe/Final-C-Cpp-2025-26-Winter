#include <vector>

int reference_sum(const std::vector<int>& v)
{
    int sum = 0;
    for (int x : v)
        if (x % 2 == 0)
            sum += x;
    return sum;
}
