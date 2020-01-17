#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

namespace test_permutation {
    using namespace std;
    class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            std::next_permutation(nums.begin(), nums.end());
        }
    };

    void Test() {
        Solution so;
        std::vector<int> input{ 1, 2, 3 };
        std::for_each(input.begin(), input.end(), [](int val) { std::cout << val << " "; });
        std::cout << std::endl;
        so.nextPermutation(input);
        std::for_each(input.begin(), input.end(), [](int val) { std::cout << val << " "; });
    }

}
