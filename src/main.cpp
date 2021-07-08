#include <iostream>
#include <random>
#include <array>

#include "rules.h"

int randGen(int max) {
    std::random_device rd;  // will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1,
                                            max); // here is where you can change the MIN and MAX values of the random dib.

    int randResult = distrib(gen);
    return randResult;
}

int main() {

    // INIT
    const int dNumb{5};

    std::array<int, dNumb> dRolls{0};

    int numOfAces{0}, numOfTwos{0}, numOfThrees{0}, numOfFours{0}, numOfFives{0}, numOfSixes{0};

    int turnCounter{0};

    bool gameIsRunning{true};

    // 1. we roll dices / take turns 3 times
    while (gameIsRunning) {

        std::cout << "-------------------" << '\n';
        std::cout << "| Rolls of turn " << turnCounter + 1 << " |" << '\n';
        std::cout << "-------------------" << '\n';
        turnCounter++;

        bool generatingRolls{true};

        // 2. generate rolls
        while (generatingRolls) {
            std::cout << "| ";
            for (int &dRoll : dRolls) {
                dRoll = randGen(6);

                std::cout << " " << dRoll << " ";
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
            std::cout << " |";
            std::cout << '\n';
            std::cout << "-------------------" << '\n';

            generatingRolls = false;
        }

        // 3. display rolls
        bool displayingRolls{true};

        while (displayingRolls) {
            std::cout << '\n';
            std::cout << "===================" << '\n';
            std::cout << "      " << "Totals:" << '\n';
            std::cout << "===================" << '\n';

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

            // 4. use rules on roles
            std::cout << '\n';
            std::cout << "UPPER SECTION:" << '\n';
            std::cout << "###################" << '\n';
            totalOfAces(numOfAces);
            totalOfTwos(numOfTwos);
            totalOfThrees(numOfThrees);
            totalOfFours(numOfFours);
            totalOfFives(numOfFives);
            totalOfSixes(numOfSixes);
            std::cout << "###################" << '\n';


            std::cout << '\n';
            std::cout << "LOWER SECTION:" << '\n';
            std::cout << "###################" << '\n';
            threeOfAKind(numOfAces, numOfTwos, numOfThrees, numOfFours, numOfFives, numOfSixes);
            fourOfAKind(numOfAces, numOfTwos, numOfThrees, numOfFours, numOfFives, numOfSixes);
            fullHouse(numOfAces, numOfTwos, numOfThrees, numOfFours, numOfFives, numOfSixes);
            smallStraight(numOfAces, numOfTwos, numOfThrees, numOfFours, numOfFives, numOfSixes);
            largeStraight(numOfAces, numOfTwos, numOfThrees, numOfFours, numOfFives, numOfSixes);
            // TODO: YAHTZEE!!! counter, first one is 50 points, second is 100 points, etc.
            gotYahtzee(numOfAces, numOfTwos, numOfThrees, numOfFours, numOfFives, numOfSixes);
            gotChance(numOfAces, numOfTwos, numOfThrees, numOfFours, numOfFives, numOfSixes);
            std::cout << "###################" << '\n';
            std::cout << '\n';

            // TODO: re-rolling individual dices!!!

            displayingRolls = false;
        }

        // 5. continue when player is done re-rolling, and we still have rounds left
        if (turnCounter < 3) {
            std::cout << '\n';
            std::cout << "Enter 'x' to continue!" << '\n';

            char usrInput{};
            std::cin >> usrInput;

            if (usrInput == 'x' || usrInput == 'X') {
                // 6. reset for next round
                numOfAces = 0;
                numOfTwos = 0;
                numOfThrees = 0;
                numOfFours = 0;
                numOfFives = 0;
                numOfSixes = 0;

                for (int i = 0; i < 5; ++i) {
                    std::cout << '\n';
                }

            } else {
                std::cout << "I said, enter 'x'! >:(" << '\n';
            }
        } else if (turnCounter == 3) {
            // 7. terminate after 3rd round
            // TODO: total all the scores, store round scores somehow probably into just integers
            gameIsRunning = false;

            for (int i = 0; i < 5; ++i) {
                std::cout << '\n';
            }
            std::cout << "The game is finished!";
        }
    }

    return 0;
}