### Problem 273:

A fixed point in an array is an element whose value is equal to its index. Given a sorted array of distinct elements, return a fixed point, if one exists. Otherwise, return False.

For example, given [-6, 0, 2, 40], you should return 2. Given [1, 5, 7, 8], you should return False.



### Explaination:

We have two arrays: Array1 = [-6 , 0, 2, 4] ; Array2 = [1, 5, 7, 8] .

B1:	We need to sort array when we using solution algorithms.

B2:	As we know:

* Array1 has 4 positions begin 0 to 3 -> [0 : -6, 1 : 0, 2 : 2, 3 : 4]
* Array2 has 4 positions begin 0 to 3 -> [0 : 1, 1 : 5, 2 : 7, 3 : 8]

B3:	

* Array1[0] = -6 -> False
* Array1[1] = 0 -> False
* Array1[2] = 2-> True
* Array1[3] = 4 -> False
* Array2[0] = 1 -> False
* Array2[1] = 5 -> False
* Array2[2] = 7 -> False
* Array2[3] = 8 -> False

### Solutions:

We can use this ways below:

* Linear Search Algorithms
* Binary Search Algorithm or Binary Search Recursive
* Vector
