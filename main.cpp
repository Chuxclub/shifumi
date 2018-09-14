#include <iostream>
#include "std_lib_facilities.h"

char ai_choice();

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

char ai_choice()
{
    vector<char> possible_outcomes = {'p', 'f', 'c'};
    possible_outcomes = {'p', 'f', 'c'};

    srand((unsigned int) time(nullptr));
    constexpr int NUMBER_POSSIBLE_OUTCOMES = 3;
    int x = rand()%NUMBER_POSSIBLE_OUTCOMES;

}