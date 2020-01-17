#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

namespace circle_array {
    using namespace std;
    class Solution {
    public:
        int BinarySearch(std::vector<int>& nums, int start, int end, int target) {
            if (target < nums[start] || target > nums[end]) {
                return -1;
            }

            while (start <= end) {
                int mid = (start + end) / 2;
                if (nums[mid] < target) {
                    start = mid + 1;
                }
                else if (nums[mid] == target) {
                    return mid;
                }
                else {
                    end = mid - 1;
                }
            }

            return -1;
        }
        int RecursiveSearch(std::vector<int>& nums, int start, int end, int target) {
            if (end <= start) {
                if (target == nums[start]) {
                    return start;
                }
                else {
                    return -1;
                }
            }

            int mid = (start + end) / 2;
            if (nums[mid] >= nums[start]) {
                if (target >= nums[start] && target <= nums[mid]) {
                    return BinarySearch(nums, start, mid, target);
                }
                else {
                    return RecursiveSearch(nums, mid + 1, end, target);
                }
            }
            else {
                if (target >= nums[mid] && target <= nums[end]) {
                    return BinarySearch(nums, mid, end, target);
                }
                else {
                    return RecursiveSearch(nums, start, mid - 1, target);
                }
            }
        }
        int search(vector<int>& nums, int target) {
            if (nums.size() < 1) {
                return -1;
            }
            return RecursiveSearch(nums, 0, nums.size() - 1, target);
        }
    };

    void Test() {
        Solution so;
        std::vector<int> input{};
        auto ans = so.search(input, 1);
        std::cout << ans << std::endl;
    }
}