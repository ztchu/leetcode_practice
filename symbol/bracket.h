#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace bracket {
    using namespace std;
    class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            std::vector<std::string> ans;
            Bracket(n, n, "", ans);
            return ans;
        }

        void Bracket(int left, int right, const std::string& out, std::vector<std::string>& ans) {
            if (left < 0 || right < 0 || left > right) {
                return;
            }

            if (left == 0 && right == 0) {
                ans.push_back(out);
                return;
            }

            Bracket(left - 1, right, out + "(", ans);
            Bracket(left, right - 1, out + ")", ans);
        }
    };

    void Test() {
        Solution so;
        auto ans = so.generateParenthesis(3);
        std::for_each(ans.begin(), ans.end(), [](const std::string& sr) { std::cout << sr << std::endl; });
    }
}