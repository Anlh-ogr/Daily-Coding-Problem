def findDuplicate(arr):
    number = len(arr) - 1
    expected_sum = number * (number + 1) // 2
    actual_sum = sum(arr)
    return actual_sum - expected_sum

arr = [1, 3, 4, 2, 7, 6, 5, 4, 8]
print(f"The duplicate number is {findDuplicate(arr)}")