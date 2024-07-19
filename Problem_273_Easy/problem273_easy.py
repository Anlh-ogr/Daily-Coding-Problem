# A fixed point in an array is an element whose value is equal to its index. 
# Given a sorted array of distinct elements, return a fixed point, if one exists. 
# Otherwise, return False.

# For example, given [-6, 0, 2, 40], you should return 2. 
# Given [1, 5, 7, 8], you should return False.


# Linear search
def find_Fixed_Point_Linear(array):
    for index, value in enumerate(array):
        if value == index:
            return index
    return False


# Binary search
def find_Fixed_Point_Binary(array):
    left = 0
    right = len(array) - 1
    while left <= right:
        mid = (left + right) // 2
        if array[mid] == mid:
            return mid
        elif array[mid] < mid:
            left = mid + 1
        else:
            right = mid - 1
    return False


# Binary search recursive
def find_Fixed_Point_Binary_Recursive(array, left, right):
    if left > right:
        return False
    mid = (left + right) // 2
    if array[mid] == mid:
        return mid
    elif array[mid] < mid:
        return find_Fixed_Point_Binary_Recursive(array, mid + 1, right)
    else:
        return find_Fixed_Point_Binary_Recursive(array, left, mid - 1)
    
def fixed_point(array):
    return find_Fixed_Point_Binary(array)


# Test cases
array_1 = [-6, 0, 2, 40]
array_2 = [1, 5, 7, 8]

# linear search
print(find_Fixed_Point_Linear(array_1))
print(find_Fixed_Point_Linear(array_2))

# binary search
print(find_Fixed_Point_Binary(array_1))
print(find_Fixed_Point_Binary(array_2))

# binary search recursive
print(find_Fixed_Point_Binary_Recursive(array_1, 0, len(array_1) - 1))
print(find_Fixed_Point_Binary_Recursive(array_2, 0, len(array_2) - 1))