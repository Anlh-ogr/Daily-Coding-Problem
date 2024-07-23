# Write a function, throw_dice(N, faces, total), that determines 
# how many ways it is possible to throw N dice with some number of faces 
# each to get a specific total

# For example, throw_dice(3, 6, 7) should equal 15.


''' input: number of dice, number of faces, total '''
def inputArguments():
    numDice = int(input("Enter the number of dice: "))
    faces = int(input("Enter the number of faces: "))
    total = int(input("Enter the total: "))
    
    if (numDice < 1 or faces < 1 or total < 1):
        print("Invalid input. Please enter a valid input.")
        exit(1)
    
    return numDice, faces, total
    
    
# brute force method
def countWaysBruteForce(numDice, faces, total):
    validCombinations = 0
    
    if (numDice != 3):
        print("This implementation only supports exactly 3 dice for the brute force method.")
        
    for i in range(1, faces+1):
        for j in range(1, faces+1):
            for k in range(1, faces+1):
                if (i+j+k == total):
                    validCombinations += 1
    
    print("Number of ways to get the total: ", validCombinations)
    

# dynamic programming
# def countWaysDynamicProgramming(numDice, faces, total):
    
# Main
numDice, faces, total = inputArguments()
countWaysBruteForce(numDice, faces, total)
