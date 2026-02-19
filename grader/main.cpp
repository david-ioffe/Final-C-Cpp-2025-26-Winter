#include <iostream>

int run_public_tests();
int run_hidden_tests();

int main()
{
    int public_passed = run_public_tests();
    int hidden_passed = run_hidden_tests();

    int total_public = 4;
    int total_hidden = 5;

    int score = 0;

    score += (public_passed * 50) / total_public;
    score += (hidden_passed * 50) / total_hidden;

    std::cout << "\nFinal Grade: " << score << "\n";

    return 0;
}
