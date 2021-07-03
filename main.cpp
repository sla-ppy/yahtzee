#include <iostream>
#include <random>
#include <array>
#include <map>

int randGen(int max) {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1,
                                            max); // Here is where you can change the MIN and MAX values of the random dib.

    int randResult = distrib(gen);
    return randResult;
}

void scoreRolls() {
    // TODO: after watching this video: https://youtu.be/sQM7sN4NPz8 it became evident that my thinking was wrong here is how to continue with the program:
    // TODO: we dont segment upper and lower, they are a whole list.
    // TODO: we first check the lower section to see if we have any specific rolls on there, after each roll
    // TODO: then if we dont, we would either re-roll, or we move to the upper section and add scores there

    std::map<std::string, const int> scoreMap{{"Total of Aces(ones)", 1},
                                              {"Total Of Twos",       2},
                                              {"Total Of Threes",     3},
                                              {"Total Of Fours",      4},
                                              {"Total Of Fives",      5},
                                              {"Total Of Sixes",      6},
                                              {"3 Of A Kind",         7},
                                              {"4 Of A Kind",         8},
                                              {"Full House",          9},
                                              {"Small Straight",      10},
                                              {"Large Straight",      11},
                                              {"YAHTZEE",             12},
                                              {"Chance",              13}
    };

    for (auto it = scoreMap.begin(); it != scoreMap.end(); it++) {
        std::cout << it->first << '\n';
    }

}

int main() {

    const int dNumb{5};
    const int rollNumb{3};

    std::array<int, dNumb> dRolls{0};

    // 1. Roll dices x3
    for (int i = 0; i != rollNumb; ++i) {
        std::cout << "Rolls of turn " << i + 1 << ":" << '\n';

        // // 2. Display rolls
        for (auto it = dRolls.begin(); it != dRolls.end(); it++) {
            *it = randGen(6);
            std::cout << *it << " ";
        }

        std::cout << '\n';
        std::cout << "Ready for your scores? Y/N" << '\n';

        char usrInput{};
        std::cin >> usrInput;

        if (usrInput == 'y' || usrInput == 'Y') {
            scoreRolls();
        } else if (usrInput == 'n' || usrInput == 'N') {
            std::cout << "What about now?" << '\n';
        } else {
            std::cout << "Choose a correct option!" << '\n';
        }
    }

    return 0;
}