// Write a function, throw_dice(N, faces, total), that determines 
// how many ways it is possible to throw N dice with some number of faces 
// each to get a specific.

// For example, throw_dice(3, 6, 7) should equal 15.


// readline module for reading input from the console
const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});


// input: 3 parameters
function inputArguments(callback) {
    readline.question("Enter the number of dice: ", (numDiceStr) => {
        const numDice = parseInt(numDiceStr, 10);
        readline.question("Enter the number of faces: ", (facesStr) => {
            const faces = parseInt(facesStr, 10);
            readline.question("Enter the total: ", (totalStr) => {
                const total = parseInt(totalStr, 10);

                if(numDice < 1 || faces < 1 || total < 1) {
                    console.log("Invalid input. Please enter a valid input.");
                    readline.close();
                    return;
                }
                
                readline.close();
                callback(numDice, faces, total);
            });
        });
    });
}


// brute force solution
function count_waysBruteForce(numDice, faces, total) {
    if (numDice != 3) {
        console.log("This implementation only supports exactly 3 dice for the brute force method.")
        return;
    }

    let validCombinations = 0;

    for (let firstDice = 1; firstDice <= faces; firstDice++) {
        for (let secondDice = 1; secondDice <= faces; secondDice++) {
            for (let thirdDice = 1; thirdDice <= faces; thirdDice++) {
                if (firstDice + secondDice + thirdDice == total) {
                    ++validCombinations;
                }
            }
        }
    }
    console.log("The number of ways to get the total is: ", validCombinations);
}


// brute force method using macro

// dynamic programming solution

// recursion with memoization


// main
function main() {
    inputArguments((numDice, faces, total) => {
        count_waysBruteForce(numDice, faces, total)
    });
}

main();