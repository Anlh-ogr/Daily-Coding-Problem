#include "iostream"
#include "vector"

int findDuplicate(const std::vector<int>& nums) {
    int tortoise = nums[0], hare = nums[0];

    // Step 1: Detect the cycle
    do {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    } while (tortoise != hare);

    // Step 2: Find the entrance to the cycle
    tortoise = nums[0];
    while (tortoise != hare) {
        tortoise = nums[tortoise];
        hare = nums[hare];
    }

    return hare;
}

int main() {
    std::vector<int> nums = {1, 3, 4, 2, 7, 6, 5, 4, 8};
    std::cout << "Duplicate number: " << findDuplicate(nums) << std::endl;

    return 0;
}