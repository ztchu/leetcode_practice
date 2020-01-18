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
                if (start == end && target == nums[start]) {
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

        int RecursiveSearchDuplicate(std::vector<int>& nums, int start, int end, int target) {
            if (end <= start) {
                if (start == end && target == nums[start]) {
                    return start;
                }
                else {
                    return -1;
                }
            }

            int mid = (start + end) / 2;
            if (nums[mid] == nums[start] && nums[mid] == nums[end]) {
                while (start < mid && nums[++start] == nums[mid]);
                auto ret = RecursiveSearchDuplicate(nums, start, mid, target);
                if (ret == -1) {
                    while (end > mid && nums[--end] == nums[mid]);
                    return RecursiveSearchDuplicate(nums, mid, end, target);
                }
                return ret;
                /*if (nums[mid] == target) {
                    return mid;
                }
                while (start < mid && nums[++start] == nums[mid]);
                while (end > mid && nums[--end] == nums[mid]);
                return RecursiveSearchDuplicate(nums, start, end, target);*/
            }

            if (nums[mid] >= nums[start]) {
                if (target >= nums[start] && target <= nums[mid]) {
                    return BinarySearch(nums, start, mid, target);
                }
                else {
                    return RecursiveSearchDuplicate(nums, mid + 1, end, target);
                }
            }
            else {
                if (target >= nums[mid] && target <= nums[end]) {
                    return BinarySearch(nums, mid, end, target);
                }
                else {
                    return RecursiveSearchDuplicate(nums, start, mid - 1, target);
                }
            }
        }
        /*int search(vector<int>& nums, int target) {
            if (nums.size() < 1) {
                return -1;
            }
            return RecursiveSearch(nums, 0, nums.size() - 1, target);
        }*/

        bool search(vector<int>& nums, int target) {
            if (nums.size() < 1) {
                return false;
            }
            return RecursiveSearchDuplicate(nums, 0, nums.size() - 1, target) == -1 ? false : true;
        }
    };

    void Test() {
        Solution so;
        std::vector<int> input{1, 1 , 3, 1, 1, 1, 1};
        auto ans = so.search(input, 3);
        std::cout << std::boolalpha;
        std::cout << ans << std::endl;
    }
}