#include <iostream>

bool run_public_tests();
bool run_hidden_tests();

int main()
{
    int score = 0;

    if (run_public_tests())
        score += 50;

    if (run_hidden_tests())
        score += 50;

    std::cout << "Final Grade: " << score << std::endl;
    return 0;
}
