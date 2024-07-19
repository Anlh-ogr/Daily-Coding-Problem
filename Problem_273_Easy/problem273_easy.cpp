// A fixed point in an array is an element whose value is equal to its index. 
// Given a sorted array of distinct elements, return a fixed point, if one exists. 
// Otherwise, return False.

// For example, given [-6, 0, 2, 40], you should return 2. 
// Given [1, 5, 7, 8], you should return False.


#include <iostream>
#include <vector>


// linear search
int find_Fixed_Point_Linear(const std::vector<int>& array) {
    for(int index = 0; index < array.size(); ++index) {
        if(array[index] == index) {
            return index;
        }
    }
    return -1;
}


// binary search
int find_Fixed_Point_Binary(const std::vector<int>& array) {
    int left = 0;
    int right = array.size() - 1;
    
    while(left <= right) {
        int mid = left + (right - left) / 2;
        
        if(array[mid] == mid) {
            return mid;
        } else if(array[mid] < mid) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}


// binary search recursive
int find_Fixed_Point_Binary_Recursive(const std::vector<int>& array, int left, int right) {
    if(left > right) {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if(array[mid] == mid) {
        return mid;
    } else if(array[mid] < mid) {
        return find_Fixed_Point_Binary_Recursive(array, mid + 1, right);
    } else {
        return find_Fixed_Point_Binary_Recursive(array, left, mid - 1);
    }
}

int find_Fixed_Point_Binary_Recursive(const std::vector<int>& array) {
    return find_Fixed_Point_Binary_Recursive(array, 0, array.size() - 1);
}


// using vector
int find_Fixed_Point_Vector(const std::vector<int>& array) {
    for(int index = 0; index < array.size(); ++index) {
        if(array[index] == index) {
            return index;
        }
    }
    return -1;
}


// main function
int main() {
    std::vector<int> array1 = {-6, 0, 3, 40};
    std::vector<int> array2 = {1, 5, 7, 8};
    std::cout << std::endl;

    // linear search
    std::cout << find_Fixed_Point_Linear(array1) << std::endl;
    std::cout << find_Fixed_Point_Linear(array2) << std::endl;
    std::cout << std::endl;

    // binary search
    std::cout << find_Fixed_Point_Binary(array1) << std::endl;
    std::cout << find_Fixed_Point_Binary(array2) << std::endl;
    std::cout << std::endl;

    // binary search recursive
    std::cout << find_Fixed_Point_Binary_Recursive(array1) << std::endl;
    std::cout << find_Fixed_Point_Binary_Recursive(array2) << std::endl;
    std::cout << std::endl;

    // vector
    std::cout << find_Fixed_Point_Vector(array1) << std::endl;
    std::cout << find_Fixed_Point_Vector(array2) << std::endl;

    return 0;

}



