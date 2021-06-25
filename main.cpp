#include <iostream>
#include <random>
#include <array>
#include <sstream>

int randGen(int max)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1, max); // Here is where you can change the MIN and MAX values of the random dib.

    int randResult = distrib(gen);
    return randResult;
}

void lowerSection() {
    std::cout << '\n';
    std::cout << "Lower section, WIP" << '\n';
}

void upperSection() {
    // TODO: after watching this video: https://youtu.be/sQM7sN4NPz8 it became evident that my thinking was wrong here is how to continue with the program:
    // TODO: we dont segment upper and lower, they are a whole list.
    // TODO: we first check the lower section to see if we have any specific rolls on there, after each roll
    // TODO: then if we dont, we would either re-roll, or we move to the upper section and add scores there
    std::stringstream ss{};

    ss << '\n';
    ss << "Categories:" << '\n';
    ss << "'1.' Total of Aces(Ones) only" << '\n';
    ss << "'2.' Total of Two's only" << '\n';
    ss << "'3.' Total of Threes only" << '\n';
    ss << "'4.' Total of Fours only" << '\n';
    ss << "'5.' Total of Fives only" << '\n';
    ss << "'6.' Total of Sixes only" << '\n';
    std::cout << ss.str() << '\n';

    char usrInput{};
    std::cin >> usrInput;

    if (usrInput == '1') {
        ss << "1" << '\n';
    } else if(usrInput == '2') {
        ss << "2" << '\n';
    } else if(usrInput == '3') {
        ss << "3" << '\n';
    } else if(usrInput == '4') {
        ss << "4" << '\n';
    } else if(usrInput == '5') {
        ss << "5" << '\n';
    } else if(usrInput == '6') {
        ss << "6" << '\n';
    } else {
        std::cout << "Choose a correct option!" << '\n';
    }
}

int main() {

    const int dNumb{5};
    const int rollNumb{3};

    std::array<int, dNumb> dRolls {0};

    // 1. Roll dices x3
    for (int i = 0; i != rollNumb; ++i) {
        std::cout << "Rolls of turn " << i +1 << ":" << '\n';

        // // 2. Display rolls
        for (auto it = dRolls.begin(); it != dRolls.end(); it++) {
            *it = randGen(6);
            std::cout << *it << '\n';
        }

        std::stringstream ss{};

        bool pickCategory{true};

        ss << '\n';
        ss << "Choose if you'd like to score by the:" << '\n';
        ss << "'1.' Upper Section" << '\n';
        ss << "'2.' Lower Section" << '\n';
        std::cout << ss.str();

        while (pickCategory)  {
            char usrInput{};
            std::cin >> usrInput;

            if(usrInput == '1') {
                upperSection();
                pickCategory = false;
            } else if(usrInput == '2') {
                lowerSection();
                pickCategory = false;
            } else {
                std::cout << "Choose a correct option!" << '\n';
            }
        }
    }

    return 0;
}