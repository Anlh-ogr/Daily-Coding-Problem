// Write a function, throw_dice(N, faces, total), that determines 
// how many ways it is possible to throw N dice with some number of faces 
// each to get a specific.

// For example, throw_dice(3, 6, 7) should equal 15.


// input: 3 parameters
function inputArguments() {
    const numDice = parent(prompt("Enter the number of dice: "));
    const faces = parent(prompt("Enter the number of faces: "));
    const total = parent(prompt("Enter the total: "));

    if(numDice < 1 || faces < 1 || total < 1) {
        console.log("Invalid input");
        return null;
    }

    return {numDice, faces, total};
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