#ifndef RULES_H
#define RULES_H

// UPPER SECTION:
inline int totalOfAces(int &numOfAces) {
    int points = numOfAces * 1;
    return points;
}

inline int totalOfTwos(int &numOfTwos) {
    int points = numOfTwos * 2;
    return points;
}

inline int totalOfThrees(int &numOfThrees) {
    int points = numOfThrees * 3;
    return points;
}

inline int totalOfFours(int &numOfFours) {
    int points = numOfFours * 4;
    return points;
}

inline int totalOfFives(int &numOfFives) {
    int points = numOfFives * 5;
    return points;
}

inline int totalOfSixes(int &numOfSixes) {
    int points = numOfSixes * 6;
    return points;
}


// LOWER SECTION:
inline int threeOfAKind(int &numOfAces, int &numOfTwos, int &numOfThrees, int &numOfFours, int &numOfFives, int &numOfSixes) {
    if (numOfAces == 3 || numOfTwos == 3 || numOfThrees == 3 || numOfFours == 4 || numOfFives == 5 || numOfSixes == 6) {
        int points = ((numOfAces * 1) + (numOfTwos * 2) + (numOfThrees * 3) + (numOfFours * 4) + (numOfFives * 5) + (numOfSixes * 6));
        return points;
    }
}


//inline int fourOfAKind() {

//}

// HOW TO SOLVE: the way im gonna solve it is check if the conditions apply by the rules, then only render the scoring options which are eligable!
//
// LOWER SECTION:
// threeOfAKind  ->  if (any of the numOf values are 3 (2,2,2,1,5)) { multiply with the numOf value }
// fourOfAKind  ->  if (any of the numOf values are 4 (3,3,3,3,2)) { multiply with the numOf value }
// fullHouse  ->  if (one of numOf includes 3 and another numOf includes 2 of the same values (5,5,5,2,2)) {25 points}
//
// smallStraight  ->  if (4 of the dicerolls have a sequential pattern like: (1,2,3,4,#)
//                                                                           (2,3,4,5,#)
//                                                                           (3,4,5,6,#) where # is any value) {30 points}
//
// largeStraight  ->  if (5 of the dice rolls have a sequential pattern like: (1,2,3,4,5)
//                                                                            (2,3,4,5,6) { 40 }
//
// gotYahtzee  ->  if (all dice show the exact same number: (1,1,1,1,1) {first YAHTZEE is 50 points}
// gotChance  ->  if (you dont want to score anything else) {total of all the rolled dices}

#endif // RULES_H
