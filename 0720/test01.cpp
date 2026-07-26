// 二分查找
#include <iostream>
#include <vector>

int binarySearch(std::vector<int>& nums, int target, int left, int right) {
    int mid;
    while (left <= right) {
        mid = left + ((right - left) >> 1);
        if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int binarySearchRec(std::vector<int>& nums, int target, int left, int right) {
    int mid;
    if (left <= right) {
        mid = left + ((right - left) >> 1);
        if (nums[mid] > target) {
            return binarySearchRec(nums, target, left, mid - 1);
        } else if (nums[mid] < target) {
            return binarySearchRec(nums, target, mid + 1, right);
        } else {
            return mid;
        }
    }
    return -1;
}

int main() {
    std::vector<int> nums = {1, 2, 5, 6, 9, 10, 20, 88};
    int idx = binarySearch(nums, 88, 0, nums.size() - 1);
    if (idx == -1) {
        std::cout << "not found" << "\n";
    } else {
        std::cout << "index = " << idx << "\n";
    }
    int idxR = binarySearchRec(nums, 20, 0, nums.size() - 1);
    if (idxR == -1) {
        std::cout << "not found" << "\n";
    } else {
        std::cout << "index = " << idxR << "\n";
    }
}