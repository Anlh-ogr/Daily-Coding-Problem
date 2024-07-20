// A fixed point in an array is an element whose value is equal to its index. 
// Given a sorted array of distinct elements, return a fixed point, if one exists. 
// Otherwise, return False.

// For example, given [-6, 0, 2, 40], you should return 2. 
// Given [1, 5, 7, 8], you should return False.


// linear search
function find_Fixed_Point_Linear(array) {
    for (let index = 0; index < array.length; index++) {
        if (array[index] === index) {
            return index;
        }
    }
    return false;
}


// binary search
function find_Fixed_Point_Binary(array) {
    let left = 0;
    let right = array.length - 1;

    while (left <= right) {
        const mid = Math.floor((left + right) / 2);

        if (array[mid] === mid) {
            return mid;
        }
        else if (array[mid] < mid) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return false;
}


// binary search recursive
function find_Fixed_Point_Binary_Recursive(array, left, right) {
    if (left > right) {
        return false;
    }

    const mid = Math.floor((left + right) / 2);

    if (array[mid] == mid) {
        return mid;
    }
    else if (array[mid] < mid) {
        return find_Fixed_Point_Binary_Recursive(array, mid + 1, right);
    }
    else {
        return find_Fixed_Point_Binary_Recursive(array, left, mid - 1);
    }
}


// main function
function main() {
    const array1 = [-6, 0, 2, 40];
    const array2 = [1, 5, 7, 8];
    
    // linear search
    console.log(find_Fixed_Point_Linear(array1));
    console.log(find_Fixed_Point_Linear(array2));

    // binary search
    console.log(find_Fixed_Point_Binary(array1));
    console.log(find_Fixed_Point_Binary(array2));

    // binary search recursive
    console.log(find_Fixed_Point_Binary_Recursive(array1, 0, array1.length - 1));
    console.log(find_Fixed_Point_Binary_Recursive(array2, 0, array2.length - 1));
}
main()
