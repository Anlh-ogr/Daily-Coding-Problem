# Explanation of #477 [`Easy`]

❓**What does the code prints:**
- The code snippet prints 9 ten times.
    ``` bash
    9
    9
    9
    9
    9
    9
    9
    9
    9
    9
    ```


❓**Why does this happen:**
- In Python, the **lambda function** captures variables **by reference**, not by value. This means the `lambda` function does not store the current value of `i` at the time it is defined but instead refers to the value od `i` in the surrounding scope when the lambda is executed.

- When the loop completes, the value of `i` is `9` (the last value in the range). Therefore, every lambda in the list refers to the same `i` variable, which is now `9`.


❓**How to fix this:**
- To fix this, we need to make sure each lambda function captures the current value of `i` at the time it is created. This can be achieved by using **default arguments** in the lambda function. Default arguments are evaluated at the time the function is created, not when it's called.
- Code has been fixed: 
[Problem 477 [Easy]](Problem_477.py).
