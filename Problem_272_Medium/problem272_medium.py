# Write a function, throw_dice(N, faces, total), that determines 
# how many ways it is possible to throw N dice with some number of faces 
# each to get a specific total

# For example, throw_dice(3, 6, 7) should equal 15.


# input: 3 parameters
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
        
    for firstDice in range(1, faces + 1):
        for secondDice in range(1, faces + 1):
            for thirdDice in range(1, faces + 1):
                if (firstDice + secondDice + thirdDice == total):
                    validCombinations += 1
    
    print("Number of ways to get the total: ", validCombinations)
    print("\n")
    

# brute force method using macro
def count_ways_brute_force_macro(num_dice, faces, total):
    valid_combinations_count = 0
    
    def loop_through_dice_values(dice_variable_range):
        return range(1, dice_variable_range + 1)
    
    def check_total(first_dice, second_dice, third_dice, total):
        nonlocal valid_combinations_count
        if first_dice + second_dice + third_dice == total:
            valid_combinations_count += 1
    
    if num_dice == 1:
        for first_dice in loop_through_dice_values(faces):
            check_total(first_dice, 0, 0, total)
    
    elif num_dice == 2:
        for first_dice in loop_through_dice_values(faces):
            for second_dice in loop_through_dice_values(faces):
                check_total(first_dice, second_dice, 0, total)
    
    elif num_dice == 3:
        for first_dice in loop_through_dice_values(faces):
            for second_dice in loop_through_dice_values(faces):
                for third_dice in loop_through_dice_values(faces):
                    check_total(first_dice, second_dice, third_dice, total)
    
    print(f"The number of ways to get the total is: {valid_combinations_count}")
    print("\n")


# dynamic programming
def countWaysDynamicProgramming(numDice, faces, total):
    
    ways_to_achieve_sum = [[0 for i in range(total + 1)] for j in range(numDice + 1)]
    ways_to_achieve_sum[0][0] = 1
    
    for dice in range(1, numDice + 1):
        for sumValue in range(1, total + 1):
            for face in range(1, faces + 1):
                if sumValue - face >= 0:
                    ways_to_achieve_sum[dice][sumValue] += ways_to_achieve_sum[dice - 1][sumValue - face]
                    
    print(f"The number of ways to get the total is: {ways_to_achieve_sum[numDice][total]}")
    print("\n")


# recursion with memoization
def countWaysMemoization(num_RemainingDice, faces, total, memo):
    if (num_RemainingDice, total) in memo:
        return memo[(num_RemainingDice, total)]

    if num_RemainingDice == 0 and total == 0:
        return 1
    
    if num_RemainingDice == 0 or total == 0:
        return 0
    
    ways = 0
    for face in range(1, faces + 1):
        if total - face >= 0:
            ways += countWaysMemoization(num_RemainingDice - 1, faces, total - face, memo)
            
    memo[(num_RemainingDice, total)] = ways
    return ways

def countWaysRecursionWithMemoization(numDice, faces, total):
    memo ={}
    result = countWaysMemoization(numDice, faces, total, memo)
    print(f"The number of ways to get the total is: {result}")


# Main
def main():
    numDice, faces, total = inputArguments()
    countWaysBruteForce(numDice, faces, total)
    
    numDice, faces, total = inputArguments()
    count_ways_brute_force_macro(numDice, faces, total)
    
    numDice, faces, total = inputArguments()
    countWaysDynamicProgramming(numDice, faces, total)
    
    numDice, faces, total = inputArguments()
    countWaysRecursionWithMemoization(numDice, faces, total)
    
if __name__ == "__main__":
    main()