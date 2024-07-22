// Write a function, throw_dice(N, faces, total), that determines 
// how many ways it is possible to throw N dice with some number of faces 
// each to get a specific total.

// For example, throw_dice(3, 6, 7) should equal 15.


#include <iostream>

#include <vector>   // dynamic programming

#include <unordered_map> // recursion with memoization
#include <tuple>         // recursion with memoization


// input: numDice, faces, total
void inputArguments(int &numDice, int &faces, int &total) {
    // std::cout << "Enter the number of dice: ";      std::cin >> numDice;
    // std::cout << "Enter the number of faces: ";     std::cin >> faces;
    // std::cout << "Enter the total: ";               std::cin >> total;

    numDice = 3;
    faces = 6;
    total = 7;

    if(numDice < 1 || faces < 1 || total < 1) {
        std::cout << "Invalid input. Please enter a valid input." << std::endl;
        exit(1);
    }
}


// brute force enumeration
void countWaysBruteForce(int numDice, int faces, int total) {
    inputArguments(numDice, faces, total);

    if (numDice != 3) {
        std::cout << "This implementation only supports exactly 3 dice for the brute force method." << std::endl;
        return;
    }

    int validCombinationsCount = 0;
    for (int firstDice = 1; firstDice <= faces; ++firstDice) {
        for (int secondDice = 1; secondDice <= faces; ++secondDice) {
            for (int thirdDice = 1; thirdDice <= faces; ++thirdDice) {
                if (firstDice + secondDice + thirdDice == total) {
                    ++validCombinationsCount;
                }
            }
        }
    }
    std::cout << "The number of ways to get the total is: " << validCombinationsCount << std::endl;
    std::cout << std::endl;
}


#define LOOP_THROUGH_DICE_VALUES(diceVariable) for(int diceVariable = 1; diceVariable <= faces; diceVariable++)
#define CHECK_TOTAL(firstDice, secondDice, thirdDice, total) if(firstDice + secondDice + thirdDice == total) {++validCombinationsCount;}
// brute force enumeration with macro
void countWaysBruteForceMacro(int numDice, int faces, int total) {
    inputArguments(numDice, faces, total);
    int validCombinationsCount = 0;

    if(numDice == 1) {
        LOOP_THROUGH_DICE_VALUES(firstDice) {
            CHECK_TOTAL(firstDice, 0, 0, total);
        }
    } else if(numDice == 2) {
        LOOP_THROUGH_DICE_VALUES(firstDice) {
            LOOP_THROUGH_DICE_VALUES(secondDice) {
                CHECK_TOTAL(firstDice, secondDice, 0, total);
            }
        }
    } else if(numDice == 3) {
        LOOP_THROUGH_DICE_VALUES(firstDice) {
            LOOP_THROUGH_DICE_VALUES(secondDice) {
                LOOP_THROUGH_DICE_VALUES(thirdDice) {
                    CHECK_TOTAL(firstDice, secondDice, thirdDice, total);
                }
            }
        }
    }
    std::cout << "The number of ways to get the total is: " << validCombinationsCount << std::endl;
    std::cout << std::endl;
}


// dynamic programming
void countWaysDynamicProgramming(int numDice, int faces, int total) {
    inputArguments(numDice, faces, total);
    std::vector<std::vector<int>> waysToAchieveSum(numDice + 1, std::vector<int>(total + 1, 0));
    waysToAchieveSum[0][0] = 1;

    for (int dice = 1; dice <= numDice; ++dice) {
        for (int sum = 1; sum <= total; ++sum) {
            for (int face = 1; face <= faces && face <= sum; ++face) {
                if (sum - face >= 0)
                    waysToAchieveSum[dice][sum] += waysToAchieveSum[dice - 1][sum - face];
            }
        }
    }
    std::cout << "The number of ways to get the total is: " << waysToAchieveSum[numDice][total] << std::endl;
    std::cout << std::endl;
}


// recursion with memoization
using MemoizationMap = std::unordered_map<std::tuple<int, int>, int>;

struct MemoizationHash {
    std::size_t operator()(const std::tuple<int, int> &key) const {
        return std::hash<int>()(std::get<0>(key)) ^ std::hash<int>()(std::get<1>(key));
    }
};







// main function
int main() {
    int numDice, faces, total;
    
    countWaysBruteForce(numDice, faces, total);
    countWaysBruteForceMacro(numDice, faces, total);

    countWaysDynamicProgramming(numDice, faces, total);


    return 0;
}


