#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

namespace combination_sum {
    using namespace std;
    class Solution {
    public:
        void RecursiveCombinationSum(int start, int target) {
            if (target == 0) {
                ans_.push_back(path_);
                return;
            }

            auto len = input_.size();
            for (auto i = start; i < len && target - input_[i] >= 0; ++i) {
                path_.push_back(input_[i]);
                RecursiveCombinationSum(i, target - input_[i]);
                path_.pop_back();
            }
        }

        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            input_ = candidates;
            std::sort(input_.begin(), input_.end());
            RecursiveCombinationSum(0, target);
            return ans_;
        }

        void RecursiveCombinationSum2(int start, int target) {
            if (target == 0) {
                ans_.push_back(path_);
                return;
            }

            for (auto i = start; i < input_.size() && target - input_[i] >= 0; ++i) {
                path_.push_back(input_[i]);
                RecursiveCombinationSum2(i + 1, target - input_[i]);
                path_.pop_back();
                while (i + 1 < input_.size() && input_[i] == input_[i + 1]) ++i;
            }
        }

        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            input_ = candidates;
            std::sort(input_.begin(), input_.end());
            RecursiveCombinationSum2(0, target);
            return ans_;
        }

    private:
        std::vector<int> path_;
        std::vector<std::vector<int>> ans_;
        std::vector<int> input_;
    };

    void Test() {
        Solution so;
        std::vector<int> input{ 10,1,2,7,6,1,5 };
        auto ans = so.combinationSum2(input, 1);
        for (int i = 0; i < ans.size(); ++i) {
            for (int j = 0; j < ans[i].size(); ++j) {
                std::cout << ans[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

}