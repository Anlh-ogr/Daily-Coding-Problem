// Write a function, throw_dice(N, faces, total), that determines 
// how many ways it is possible to throw N dice with some number of faces 
// each to get a specific.

// For example, throw_dice(3, 6, 7) should equal 15.



// module imports
const prompt = require('prompt-sync')();
/*          example of prompt
    const name = prompt('What is your name?');
    console.log(`Hey there ${name}`);

    const age = prompt('What is your ages?');
    console.log(`Hey there ${name}`);
*/


// input: 3 parameters
function inputArguments() {
    const numDice = parseInt(prompt("Enter the number of dice: "),10);
    const faces = parseInt(prompt("Enter the number of faces: "),10);
    const total = parseInt(prompt("Enter the total: "),10);
    
    if (numDice < 1 || faces < 1 || total < 1) {
        console.log("Invalid input. Please enter positive integers.");
        return null;
    } else {
        return [numDice, faces, total];
    }
}


// brute force solution
function count_waysBruteForce(numDice, faces, total) {
    if (numDice != 3) {
        return "This implementation only supports exactly 3 dice for the brute force method.";
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
    return `The number of ways to get the total is: ${validCombinations}`;
}


// brute force method using macro
function count_waysBruteForceMacro(numDice, faces, total) {
    let validCombinations = 0;

    // macro to loop through the dice values
    function loopThroughDiceValue(faces) {
        return Array.from({ length: faces }, (_, i) => i + 1);
    }
 
    // macro to check the total
    function checkTotal(firstDice, secondDice, thirdDice) {
        if (firstDice + secondDice + thirdDice == total) {
            ++validCombinations;
        }
    }

    if (numDice == 1) {
        loopThroughDiceValue(faces).forEach(firstDice => {
            checkTotal(firstDice, 0, 0);
        });
    }
 
    if (numDice == 2) {
        loopThroughDiceValue(faces).forEach(firstDice => {
            loopThroughDiceValue(faces).forEach(secondDice => {
                checkTotal(firstDice, secondDice, 0);
            });
        });
    }
 
    if (numDice == 3) {
        loopThroughDiceValue(faces).forEach(firstDice => {
            loopThroughDiceValue(faces).forEach(secondDice => {
                loopThroughDiceValue(faces).forEach(thirdDice => {
                    checkTotal(firstDice, secondDice, thirdDice);
                });
            });
        });
    }
    return `The number of ways to get the total is: ${validCombinations}`;
}


// dynamic programming solution
function countWaysDynamicProgramming(numDice, faces, total) {
    const waysToAchieveSum = Array.from({ length : numDice + 1}, () => Array(total + 1).fill(0));
    waysToAchieveSum[0][0] = 1; // base case: there's one way to get a sum of 0 with 0 dice

    // loop through each dice count from 1 to numDice
    for (let diceCount = 1; diceCount <= numDice; diceCount++) {
        // loop through each possible sum from 1 to total
        for (let currentSum = 1; currentSum <= total; currentSum++) {
            // loop through each face value from 1 to faces
            for (let faceValue = 1; faceValue <= faces && faceValue <= currentSum; faceValue++) {
                waysToAchieveSum[diceCount][currentSum] += waysToAchieveSum[diceCount - 1][currentSum - faceValue];
            }
        }
    }
    return `The number of ways to get the total is: ${waysToAchieveSum[numDice][total]}`;
}


// recursion with memoization
function countWaysRecursionMemo(numDice, faces, total) {
    // create a memoization table initialized with null values
    const memo = Array.from({ length: numDice + 1 }, () => Array(total + 1).fill(null));
    
    // define the helper function to perform the recursion with memoization
    function countWaysRecursionMemoHelper(diceLeft, remainingTotal) {
        // base case: if there are no dice left, check if the total is 0
        if(diceLeft === 0 && remainingTotal === 0) return 1; // exact match
        if(diceLeft === 0 || remainingTotal < 0) return 0; // invalid combination

        // check if result is already computed and stored in the memo table
        if(memo[diceLeft][remainingTotal] !== null) return memo[diceLeft][remainingTotal];

        // calculate the number of ways
        let ways = 0;
        
        for(let faceValue = 1; faceValue <= faces; faceValue++) {
            ways += countWaysRecursionMemoHelper(diceLeft - 1, remainingTotal - faceValue);
        }

        // store the result in the memo table and return
        memo[diceLeft][remainingTotal] = ways;
        return ways;
    }

    // start the recursion with the initial numbers of dice and total
    const result = countWaysRecursionMemoHelper(numDice, total);
    return `The number of ways to get the total is: ${result}`; 
}


// main
function main() {

    let args = inputArguments();
    if(args) {
        let [numDice, faces, total] = args;
        console.log(`Brute force method: ${numDice} dice, ${faces} faces, ${total} total`);
        console.log(count_waysBruteForce(numDice, faces, total) + '\n');
    }

    args = inputArguments();
    if(args) {
        let [numDice, faces, total] = args;
        console.log(`Brute force method: ${numDice} dice, ${faces} faces, ${total} total`);
        console.log(count_waysBruteForceMacro(numDice, faces, total) + '\n');
    }

    args = inputArguments();
    if(args) {
        let [numDice, faces, total] = args;
        console.log(`Dynamic programming method: ${numDice} dice, ${faces} faces, ${total} total`);
        console.log(countWaysDynamicProgramming(numDice, faces, total) + '\n');
    }

    args = inputArguments();
    if(args) {
        let [numDice, faces, total] = args;
        console.log(`Recursion with memoization method: ${numDice} dice, ${faces} faces, ${total} total`);
        console.log(countWaysRecursionMemo(numDice, faces, total));
    }
}
main();
