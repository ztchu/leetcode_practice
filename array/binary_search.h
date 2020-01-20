#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

namespace bound {
    using namespace std;
    class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            auto low = std::lower_bound(nums.begin(), nums.end(), target);
            auto high = std::upper_bound(nums.begin(), nums.end(), target);
            if (low == high) {
                return { -1, -1 };
            }

            auto low_index = std::distance(nums.begin(), low);
            auto high_index = std::distance(nums.begin(), high);
            return { low_index, high_index - 1 };
        }

        vector<int> searchRangeB(vector<int>& nums, int target) {
            auto ret = std::equal_range(nums.begin(), nums.end(), target);
            if (ret.first == ret.second) {
                return { -1, -1 };
            }

            auto low_index = std::distance(nums.begin(), ret.first);
            auto high_index = std::distance(nums.begin(), ret.second);
            return { low_index, high_index - 1 };
        }
    };

    void Test() {
        Solution so;
        std::vector<int> input{ 5,7,7,8,8,10 };
        auto ans = so.searchRangeB(input, 8);
        std::cout << ans[0] << " " << ans[1] << std::endl;
    }
}