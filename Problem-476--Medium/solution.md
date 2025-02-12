# Solution of #476 [`Medium`]

- Using Floyd's Tortoise and Hare Algorithm (Cycle Detection)
  
  This approach treats the array as a linked list where each index points to the value at that index. Using Floyd's cycle detection algorithm:
  1. Use two pointers,slow pointer (`tortoise`) and a fast pointer(`hare`).
  2. Move the tortoise one step at a time and the hare two steps at a time until they meet (detecting a cycle).
  3. Reset one pointer to the start of the array and move both pointers one step at a time. The point where they meet is the duplicate.
   

- Marking Visited Elements
    
    Since the elements of the array are within the range {1,2,...,n}, you can mark visited elements:
    1. Traverse the array, treating the absolute value of each element as an index.
    2. Negate the value at that index to mark it as visited.
    3. If you encounter a negative value at an index, the corresponding number is the duplicate.


- Binary Search on Value Range

    using binary search on the range {1,2,...,n}:
    1. Count how many elements are less than or equal to the mid-point of the range.
    2. If the count exceeds the mid-point, the duplicate is in the lower half; otherwise, it's in the upper half.
    3. Repeat until the range is narrowed down to one number.


# Implementation
**Step 1:** Understand the Problem: We have an array with `n+1` elements where each element is between `1` and `n` inclusive, except for one number which appears exactly twice. Our goal is to identify this duplicate number efficiently.

**Step 2:** Sum of Natural Numbers: The sum of the first `n` natural numbers can be calculated using the formula S = $\frac{n(n+1)}{2}$.

**Step 3:** Calculate Actual Sum: Compute the sum of all elements in the given array.

**Step 4:** Find Duplicate: Subtract the expected sum (S) from the actual sum to find the duplicate number, as this difference will be equal to the extra occurrence of the duplicate element.

# Example
- Let `n = 3` and the array be `[1, 3, 2, 1]`.
- Expected sum: $S = \frac{3(3+1)}{2} = 6$.
- Actual sum: $1 + 3 + 2 + 1 = 7$.
- The duplicate number is `7 - 6 = 1`.


# Complexity Analysis
- Time Complexity: O(N) because we traverse the array with two pointers.
- Space Complexity: O(1) as no extra space is used beyond a few variables.