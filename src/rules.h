#ifndef RULES_H
#define RULES_H

// UPPER SECTION:
inline int totalOfAces(int &numOfAces) {
    int points{};
    if (numOfAces != 0) {
        points = numOfAces * 1;
        std::cout << "Total Of Aces: " << points << '\n';
    }
    return points;
}

inline int totalOfTwos(int &numOfTwos) {
    int points{};
    if (numOfTwos != 0) {
        points = numOfTwos * 2;
        std::cout << "Total Of Twos: " << points << '\n';
    }
    return points;
}

inline int totalOfThrees(int &numOfThrees) {
    int points{};
    if (numOfThrees != 0) {
        points = numOfThrees * 3;
        std::cout << "Total Of Threes: " << points << '\n';
    }
    return points;
}

inline int totalOfFours(int &numOfFours) {
    int points{};
    if (numOfFours != 0) {
        points = numOfFours * 4;
        std::cout << "Total Of Fours: " << points << '\n';
    }
    return points;
}

inline int totalOfFives(int &numOfFives) {
    int points{};
    if (numOfFives != 0) {
        points = numOfFives * 5;
        std::cout << "Total Of Fives: " << points << '\n';
    }
    return points;
}

inline int totalOfSixes(int &numOfSixes) {
    int points{};
    if (numOfSixes != 0) {
        points = numOfSixes * 6;
        std::cout << "Total Of Sixes: " << points << '\n';
    }
    return points;
}


// LOWER SECTION:
inline int
threeOfAKind(int &numOfAces, int &numOfTwos, int &numOfThrees, int &numOfFours, int &numOfFives, int &numOfSixes) {
    int points{};
    if (numOfAces == 3 || numOfTwos == 3 || numOfThrees == 3 || numOfFours == 3 || numOfFives == 3 || numOfSixes == 3) {
        points = ((numOfAces * 1)
                  + (numOfTwos * 2)
                  + (numOfThrees * 3)
                  + (numOfFours * 4)
                  + (numOfFives * 5)
                  + (numOfSixes * 6));
        std::cout << "Three Of A Kind: " << points << '\n';
    }
    return points;
}

inline int
fourOfAKind(int &numOfAces, int &numOfTwos, int &numOfThrees, int &numOfFours, int &numOfFives, int &numOfSixes) {
    int points{};
    if (numOfAces == 4 || numOfTwos == 4 || numOfThrees == 4 || numOfFours == 4 || numOfFives == 4 || numOfSixes == 4) {
        points = ((numOfAces * 1)
                      + (numOfTwos * 2)
                      + (numOfThrees * 3)
                      + (numOfFours * 4)
                      + (numOfFives * 5)
                      + (numOfSixes * 6));
        std::cout << "Four Of A Kind: " << points << '\n';
    }
    return points;
}

inline int
fullHouse(int &numOfAces, int &numOfTwos, int &numOfThrees, int &numOfFours, int &numOfFives, int &numOfSixes) {
    int points{25};
    if (numOfAces == 3) {
        if (numOfTwos == 2 || numOfThrees == 2 || numOfFours == 3 || numOfFives == 2 || numOfSixes == 2) {
            std::cout << "Full House: " << points << '\n';
        }
    } else if (numOfTwos == 3) {
        if (numOfAces == 2 || numOfThrees == 2 || numOfFours == 3 || numOfFives == 2 || numOfSixes == 2) {
            std::cout << "Full House: " << points << '\n';
        }
    } else if (numOfThrees == 3) {
        if (numOfAces == 2 || numOfTwos == 2 || numOfFours == 3 || numOfFives == 2 || numOfSixes == 2) {
            std::cout << "Full House: " << points << '\n';
        }
    } else if (numOfFours == 3) {
        if (numOfAces == 2 || numOfTwos == 2 || numOfThrees == 3 || numOfFives == 2 || numOfSixes == 2) {
            std::cout << "Full House: " << points << '\n';
        }
    } else if (numOfFives == 3) {
        if (numOfAces == 2 || numOfTwos == 2 || numOfThrees == 3 || numOfFours == 2 || numOfSixes == 2) {
            std::cout << "Full House: " << points << '\n';
        }
    } else if (numOfSixes == 3) {
        if (numOfAces == 2 || numOfTwos == 2 || numOfThrees == 3 || numOfFours == 2 || numOfFives == 2) {
            std::cout << "Full House: " << points << '\n';
        }
    }
    return points;
}

inline int
smallStraight(int &numOfAces, int &numOfTwos, int &numOfThrees, int &numOfFours, int &numOfFives, int &numOfSixes) {
    int points{};
    if (
            (numOfAces == 1 && numOfTwos == 1 && numOfThrees == 1 && numOfFours == 1)
            || (numOfTwos == 1 && numOfThrees == 1 && numOfFours == 1 && numOfFives == 1)
            || (numOfThrees == 1 && numOfFours == 1 && numOfFives == 1 && numOfSixes == 1)
            ) {
        points = 30;
        std::cout << "Small Straight: " << points << '\n';
    }
    return points;
}

inline int
largeStraight(int &numOfAces, int &numOfTwos, int &numOfThrees, int &numOfFours, int &numOfFives, int &numOfSixes) {
    int points{};
    if (
            (numOfAces == 1 && numOfTwos == 1 && numOfThrees == 1 && numOfFours == 1 && numOfFives == 1)
            || (numOfTwos == 1 && numOfThrees == 1 && numOfFours == 1 && numOfFives == 1 && numOfSixes == 1)
            ) {
        points = 50;
        std::cout << "Large Straight: " << points << '\n';
    }
    return points;
}

inline int
gotYahtzee(int &numOfAces, int &numOfTwos, int &numOfThrees, int &numOfFours, int &numOfFives, int &numOfSixes) {
    int points{};
    if (numOfAces == 5 || numOfTwos == 5 || numOfThrees == 5 || numOfFours == 5 || numOfFives == 5 || numOfSixes == 5) {
        int yahtzeeCounter{0};
        yahtzeeCounter++;

        if (yahtzeeCounter == 1) {
            points = 50;
            std::cout << "YAHTZEE!!!: " << points << '\n';
        } else if (yahtzeeCounter == 2) {

        } else if (yahtzeeCounter == 3) {

        } else {

        }
    }
    return points;
}

inline int
gotChance(int &numOfAces, int &numOfTwos, int &numOfThrees, int &numOfFours, int &numOfFives, int &numOfSixes) {
    int points = ((numOfAces * 1)
                  + (numOfTwos * 2)
                  + (numOfThrees * 3)
                  + (numOfFours * 4)
                  + (numOfFives * 5)
                  + (numOfSixes * 6));
    std::cout << "Chance: " << points << '\n';
    return points;
}

#endif // RULES_H