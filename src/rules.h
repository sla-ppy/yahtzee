#ifndef RULES_H
#define RULES_H

// UPPER SECTION:
inline void totalOfAces(int &numOfAces) {
    if (numOfAces != 0) {
        int points = numOfAces * 1;
        std::cout << "Total Of Aces: " << points << '\n';
    }
}

inline void totalOfTwos(int &numOfTwos) {
    if (numOfTwos != 0) {
        int points = numOfTwos * 2;
        std::cout << "Total Of Twos: " << points << '\n';
    }
}

inline void totalOfThrees(int &numOfThrees) {
    if (numOfThrees != 0) {
        int points = numOfThrees * 3;
        std::cout << "Total Of Threes: " << points << '\n';
    }
}

inline void totalOfFours(int &numOfFours) {
    if (numOfFours != 0) {
        int points = numOfFours * 4;
        std::cout << "Total Of Fours: " << points << '\n';
    }
}

inline void totalOfFives(int &numOfFives) {
    if (numOfFives != 0) {
        int points = numOfFives * 5;
        std::cout << "Total Of Fives: " << points << '\n';
    }
}

inline void totalOfSixes(int &numOfSixes) {
    if (numOfSixes != 0) {
        int points = numOfSixes * 6;
        std::cout << "Total Of Sixes: " << points << '\n';
    }
}


// LOWER SECTION:
inline void
threeOfAKind(int &numOfAces, int &numOfTwos, int &numOfThrees, int &numOfFours, int &numOfFives, int &numOfSixes) {
    if (numOfAces == 3 || numOfTwos == 3 || numOfThrees == 3 || numOfFours == 3 || numOfFives == 3 || numOfSixes == 3) {
        int points = ((numOfAces * 1)
                      + (numOfTwos * 2)
                      + (numOfThrees * 3)
                      + (numOfFours * 4)
                      + (numOfFives * 5)
                      + (numOfSixes * 6));
        std::cout << "Three Of A Kind: " << points << '\n';
    }
}

inline void
fourOfAKind(int &numOfAces, int &numOfTwos, int &numOfThrees, int &numOfFours, int &numOfFives, int &numOfSixes) {
    if (numOfAces == 4 || numOfTwos == 4 || numOfThrees == 4 || numOfFours == 4 || numOfFives == 4 || numOfSixes == 4) {
        int points = ((numOfAces * 1)
                      + (numOfTwos * 2)
                      + (numOfThrees * 3)
                      + (numOfFours * 4)
                      + (numOfFives * 5)
                      + (numOfSixes * 6));
        std::cout << "Four Of A Kind: " << points << '\n';
    }
}

inline void
fullHouse(int &numOfAces, int &numOfTwos, int &numOfThrees, int &numOfFours, int &numOfFives, int &numOfSixes) {
    if (// 1 - #
            (numOfAces == 3 && numOfTwos == 2)
            || (numOfAces == 3 && numOfThrees == 2)
            || (numOfAces == 3 && numOfFours == 2)
            || (numOfAces == 3 && numOfFives == 2)
            || (numOfAces == 3 && numOfSixes == 2)

            // 2 - #
            || (numOfTwos == 3 && numOfAces == 2)
            || (numOfTwos == 3 && numOfThrees == 2)
            || (numOfTwos == 3 && numOfFours == 2)
            || (numOfTwos == 3 && numOfFives == 2)
            || (numOfTwos == 3 && numOfSixes == 2)

            // 3 - #
            || (numOfThrees == 3 && numOfAces == 2)
            || (numOfThrees == 3 && numOfTwos == 2)
            || (numOfThrees == 3 && numOfFours == 2)
            || (numOfThrees == 3 && numOfFives == 2)
            || (numOfThrees == 3 && numOfSixes == 2)

            // 4 - #
            || (numOfFours == 3 && numOfAces == 2)
            || (numOfFours == 3 && numOfTwos == 2)
            || (numOfFours == 3 && numOfThrees == 2)
            || (numOfFours == 3 && numOfFives == 2)
            || (numOfFours == 3 && numOfSixes == 2)

            // 5 - #
            || (numOfFives == 3 && numOfAces == 2)
            || (numOfFives == 3 && numOfTwos == 2)
            || (numOfFives == 3 && numOfThrees == 2)
            || (numOfFives == 3 && numOfFours == 2)
            || (numOfFives == 3 && numOfSixes == 2)

            // 6 - #
            || (numOfSixes == 3 && numOfAces == 2)
            || (numOfSixes == 3 && numOfTwos == 2)
            || (numOfSixes == 3 && numOfThrees == 2)
            || (numOfSixes == 3 && numOfFours == 2)
            || (numOfSixes == 3 && numOfFives == 2)
            ) {
        int points{25};
        std::cout << "Full House: " << points << '\n';
    }
}

inline void
smallStraight(int &numOfAces, int &numOfTwos, int &numOfThrees, int &numOfFours, int &numOfFives, int &numOfSixes) {
    if (
            (numOfAces == 1 && numOfTwos == 1 && numOfThrees == 1 && numOfFours == 1)
            || (numOfTwos == 1 && numOfThrees == 1 && numOfFours == 1 && numOfFives == 1)
            || (numOfThrees == 1 && numOfFours == 1 && numOfFives == 1 && numOfSixes == 1)
            ) {
        int points{30};
        std::cout << "Small Straight: " << points << '\n';
    }
}

inline void
largeStraight(int &numOfAces, int &numOfTwos, int &numOfThrees, int &numOfFours, int &numOfFives, int &numOfSixes) {
    if (
            (numOfAces == 1 && numOfTwos == 1 && numOfThrees == 1 && numOfFours == 1 && numOfFives == 1)
            || (numOfTwos == 1 && numOfThrees == 1 && numOfFours == 1 && numOfFives == 1 && numOfSixes == 1)
            ) {
        int points{50};
        std::cout << "Large Straight: " << points << '\n';
    }
}

inline void
gotYahtzee(int &numOfAces, int &numOfTwos, int &numOfThrees, int &numOfFours, int &numOfFives, int &numOfSixes) {
    if (numOfAces == 5 || numOfTwos == 5 || numOfThrees == 5 || numOfFours == 5 || numOfFives == 5 || numOfSixes == 5) {
        int points{50};
        std::cout << "YAHTZEE!!!: " << points << '\n';
    }
}

inline void
gotChance(int &numOfAces, int &numOfTwos, int &numOfThrees, int &numOfFours, int &numOfFives, int &numOfSixes) {
    int points = ((numOfAces * 1)
                  + (numOfTwos * 2)
                  + (numOfThrees * 3)
                  + (numOfFours * 4)
                  + (numOfFives * 5)
                  + (numOfSixes * 6));
    std::cout << "Chance: " << points << '\n';
}

// HOW TO SOLVE: the way im gonna solve it is check if the conditions apply by the rules, then only render the scoring options which are eligible!
//
// gotYahtzee  ->  if (all dice show the exact same number: (1,1,1,1,1) {first YAHTZEE is 50 points}
// gotChance  ->  if (you dont want to score anything else) {total of all the rolled dices}

#endif // RULES_H