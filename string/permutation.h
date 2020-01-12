#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace permutation {
    using namespace std;
    class Solution {
    public:
        
        vector<string> letterCombinations(string digits) {
            std::vector<std::vector<char>> table{ {'a', 'b', 'c'}, {'d', 'e', 'f'},
                {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'},
                {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'} };
            std::vector<std::string> ans;
            for (auto i = 0; i < digits.size(); ++i) {
                auto index = digits[i] - '2';
                if (ans.empty()) {
                    for (auto j = 0; j < table[index].size(); ++j) {
                        std::string temp;
                        temp.push_back(table[index][j]);
                        ans.push_back(std::move(temp));
                    }
                }
                else {
                    std::vector<std::string> mid_ans;
                    for (auto j = 0; j < ans.size(); ++j) {
                        for (auto k = 0; k < table[index].size(); ++k) {
                            std::string temp(ans[j]);
                            temp.push_back(table[index][k]);
                            mid_ans.push_back(std::move(temp));
                        }
                    }
                    ans.swap(mid_ans);
                }
            }
            return ans;
        }
    };

    void Test() {
        Solution so;
        std::string digits("32");
        auto ans = so.letterCombinations(digits);
        std::for_each(ans.begin(), ans.end(), [](const std::string& str) { std::cout << str << " "; });
    }
}