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

        // for keeping scores
        int totalOfAcesPoints{}, totalOfTwosPoints{}, totalOfThreesPoints{}, totalOfFoursPoints{}, totalOfFivesPoints{}, totalOfSixesPoints{}, threeOfAKindPoints{}, fourOfAKindPoints{}, fullHousePoints{}, smallStraightPoints{}, largeStraightPoints{}, yahtzeePoints{}, chancePoints{};

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
            totalOfAcesPoints = totalOfAces(numOfAces);
            totalOfTwosPoints = totalOfTwos(numOfTwos);
            totalOfThreesPoints = totalOfThrees(numOfThrees);
            totalOfFoursPoints = totalOfFours(numOfFours);
            totalOfFivesPoints = totalOfFives(numOfFives);
            totalOfSixesPoints = totalOfSixes(numOfSixes);
            std::cout << "###################" << '\n';


            std::cout << '\n';
            std::cout << "LOWER SECTION:" << '\n';
            std::cout << "###################" << '\n';
            threeOfAKindPoints = threeOfAKind(numOfAces, numOfTwos, numOfThrees, numOfFours, numOfFives, numOfSixes);
            fourOfAKindPoints = fourOfAKind(numOfAces, numOfTwos, numOfThrees, numOfFours, numOfFives, numOfSixes);
            fullHousePoints = fullHouse(numOfAces, numOfTwos, numOfThrees, numOfFours, numOfFives, numOfSixes);
            smallStraightPoints = smallStraight(numOfAces, numOfTwos, numOfThrees, numOfFours, numOfFives, numOfSixes);
            largeStraightPoints = largeStraight(numOfAces, numOfTwos, numOfThrees, numOfFours, numOfFives, numOfSixes);
            // TODO: YAHTZEE!!! counter, first one is 50 points, second is 100 points, etc.
            yahtzeePoints = gotYahtzee(numOfAces, numOfTwos, numOfThrees, numOfFours, numOfFives, numOfSixes);
            chancePoints = gotChance(numOfAces, numOfTwos, numOfThrees, numOfFours, numOfFives, numOfSixes);
            std::cout << "###################" << '\n';
            std::cout << '\n';

            displayingRolls = false;
        }


        // TODO: player can only roll 3 times all together!
        // 5. re-roll if player wants to
        char reRollInput{};
        std::cout << "Do you want to re-roll any of the dices? (y/N)" << '\n';
        std::cin >> reRollInput;

        bool wantsReRoll{};

        if (reRollInput == 'y' || reRollInput == 'Y') {
            wantsReRoll = true;
        } else if (reRollInput == 'n' || reRollInput == 'N') {
            wantsReRoll = false;
        }

        while(wantsReRoll) {
            std::cout << "You choose to re-roll." << '\n';
            std::cout << '\n';

            // TODO: need to figure out a better way for multiple inputs with this method, not sure how to proceed currently.
            bool reRollFirst{false}, reRollSecond{false}, reRollThird{false}, reRollFourth{false}, reRollFifth{false};

            std::cout << "Which dice would you like to re-roll? (1-5)" << '\n';
            std::cin >> reRollFirst >> reRollSecond >> reRollThird >> reRollFourth >> reRollFifth;

            // reroll specific rolls based on usr input
            if (reRollFirst) {
                dRolls[0] = randGen(6);
            }
            if (reRollSecond) {
                dRolls[1] = randGen(6);
            }
            if (reRollThird) {
                dRolls[2] = randGen(6);
            }
            if (reRollFourth) {
                dRolls[3] = randGen(6);
            }
            if (reRollFifth) {
                dRolls[4] = randGen(6);
            } else {
                std::cout << "Pick from the available dices! (1-5)" << '\n';
            }

            std::cout << dRolls[0];

            // display new rolls after re-roll
            for (int i = 0; i < 5; ++i) {
                std::cout << '\n';
            }
            std::cout << "-------------------" << '\n';
            std::cout << "| New rolls of turn " << turnCounter + 1 << " |" << '\n';
            std::cout << "-------------------" << '\n';
            for (int &dRoll : dRolls) {
                std::cout << "| " << dRoll << " |";
            }

            wantsReRoll = false;
        }

        // 6. continue when player is done re-rolling, and we still have rounds left
        if (turnCounter < 3) {
            std::cout << '\n';
            std::cout << "Enter 'x' to end your turn." << '\n';

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
            std::cout << "The game is finished!" << '\n';
            std::cout << '\n';

            // 8. score the turn
            int roundScore = totalOfAcesPoints + totalOfTwosPoints + totalOfThreesPoints + totalOfFoursPoints +
                             totalOfFivesPoints + totalOfSixesPoints + threeOfAKindPoints + fourOfAKindPoints +
                             fullHousePoints + smallStraightPoints + largeStraightPoints + yahtzeePoints + chancePoints;
            std::cout << "-----------------------" << '\n';
            std::cout << "| This Round's Score: " << roundScore << "|" << '\n';
            std::cout << "-----------------------" << '\n';

            // TODO: score full game later on

            char usrInput{};
            std::cout << "Enter anything to quit the program." << '\n';
            std::cin >> usrInput;
        }
    }

    return 0;
}