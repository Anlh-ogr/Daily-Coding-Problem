// Write a function, throw_dice(N, faces, total), that determines 
// how many ways it is possible to throw N dice with some number of faces 
// each to get a specific total.

// For example, throw_dice(3, 6, 7) should equal 15.


#include <iostream>

// input: numDice, faces, total
void inputArguments(int &numDice, int &faces, int &total) {
    std::cout << "Enter the number of dice: ";      std::cin >> numDice;
    std::cout << "Enter the number of faces: ";     std::cin >> faces;
    std::cout << "Enter the total: ";               std::cin >> total;

    if(numDice < 1 || faces < 1 || total < 1) {
        std::cout << "Invalid input. Please enter a valid input." << std::endl;
        exit(1);
    }
}


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
}

// main function
int main() {
    int numDice, faces, total;
    countWaysBruteForce(numDice, faces, total);

    return 0;
}

// macro
// #define LOOP_THROUGH_DICE_VALUES(diceVariable) for(int diceVariable = 1; diceVariable <= faces; diceVariable++)
// #define CHECK_TOTAL(firstDice, secondDice, thirdDice, total) if(firstDice + secondDice + thirdDice == total) {++validCombinationsCount;}



// /*  brute force enumeration
  
// int countWaysBruteForce(int numDice, int faces, int total) {
//     int validCombinationsCount = 0;
    
//     for (int firstDice = 1; firstDice <= faces; firstDice++) {
//         for (int secondDice = 1; secondDice <= faces; secondDice++) {
//             for (int thirdDice = 1; thirdDice <= faces; thirdDice++) {
//                 if(firstDice + secondDice + thirdDice == total) {
//                     validCombinationsCount++;
//                 }
//             }
//         }
//     }
//     return validCombinationsCount;
// } */


// // brute force enumeration with macro
// // int countWaysBruteForceMacro(int numDice, int faces, int total) {
// //     int validCombinationsCount = 0;
// //     if(numDice == 1) {
// //         LOOP_THROUGH_DICE_VALUES(firstDice) {
// //             CHECK_TOTAL(firstDice, 0, 0, total);
// //         }
// //     } else if(numDice == 2) {
// //         LOOP_THROUGH_DICE_VALUES(firstDice) {
// //             LOOP_THROUGH_DICE_VALUES(secondDice) {
// //                 CHECK_TOTAL(firstDice, secondDice, 0, total);
// //             }
// //         }
// //     } else if(numDice == 3) {
// //         LOOP_THROUGH_DICE_VALUES(firstDice) {
// //             LOOP_THROUGH_DICE_VALUES(secondDice) {
// //                 LOOP_THROUGH_DICE_VALUES(thirdDice) {
// //                     CHECK_TOTAL(firstDice, secondDice, thirdDice, total);
// //                 }
// //             }
// //         }
// //     }
// //     return validCombinationsCount;
// // }


// // int countWaysBruteForce(int numDice, int faces, int total) {
// //     int count = 0;
    
// //     for(int index = 1; index <= faces; index++) {
// //         if(numDice == 1) {
// //             if(index == total) {
// //                 count++;
// //             }
// //         } else {
// //             count += countWaysBruteForce(numDice - 1, faces, total - index);
// //         }
// //     }
// //     return count;
// // }


