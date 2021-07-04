#include <iostream>
#include <random>
#include <array>
#include <map>

int randGen(int max) {
    std::random_device rd;  // will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1,
                                            max); // here is where you can change the MIN and MAX values of the random dib.

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

    for (auto &it : scoreMap) {
        std::cout << it.first << '\n';
    }
}

int main() {

    // INIT
    const int dNumb{5};
    const int rollNumb{3};

    std::array<int, dNumb> dRolls{0};

    int numOfAces{0}, numOfTwos{0}, numOfThrees{0}, numOfFours{0}, numOfFives{0}, numOfSixes{0};

    // 1. roll dices(3 turns)
    for (int i = 0; i != rollNumb; ++i) {
        std::cout << "-------------------" << '\n';
        std::cout << "| Rolls of turn " << i + 1 << " |" << '\n';
        std::cout << "-------------------" << '\n';

        // // 2. generate rolls
        for (int &dRoll : dRolls) {
            dRoll = randGen(6);

            // evaluate, and group up rolls by value
            if (dRoll == 1) {
                numOfAces++;
            } else if (dRoll == 2) {
                numOfTwos++;
            } else if (dRoll == 3) {
                numOfThrees++;
            } else if (dRoll == 4) {
                numOfFours++;
            } else if (dRoll == 5) {
                numOfFives++;
            } else if (dRoll == 6) {
                numOfSixes++;
            } else {
                std::cerr << "An error occurred while evaluating rolls into groups by value" << std::endl;
            }
        }

        // 3. display rolls
        std::cout << '\n';
        std::cout << "===================" << '\n';
        for (auto it = dRolls.begin(); it != dRolls.end(); it++) {
            if (numOfAces != 0) {
                std::cout << "Aces(1) * " << numOfAces << '\n';
            }
            if (numOfTwos != 0) {
                std::cout << "Twos(2) * " << numOfTwos << '\n';
            }
            if (numOfThrees != 0) {
                std::cout << "Threes(3) * " << numOfThrees << '\n';
            }
            if (numOfFours != 0) {
                std::cout << "Fours(4) * " << numOfFours << '\n';
            }
            if (numOfFives != 0) {
                std::cout << "Fives(5) * " << numOfFives << '\n';
            }
            if (numOfSixes != 0) {
                std::cout << "Sixes(6) * " << numOfSixes << '\n';
            }
            std::cout << "===================" << '\n';

            // 4. move on to scoring
            std::cout << '\n';
            std::cout << "Enter 'x' to continue!" << '\n';

            char usrInput{};
            std::cin >> usrInput;

            if (usrInput == 'x' || usrInput == 'X') {
                scoreRolls();
            } else {
                std::cout << "I said, enter 'x'! >:(" << '\n';
            }

            std::cout << '\n';
        }
    }

    // DEINIT
    return 0;
}