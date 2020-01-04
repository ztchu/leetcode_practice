#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace z_string {
    class Solution {
    public:
        string convert(string s, int numRows) {
            int len = s.size();
            if (numRows <= 1 || len <= 1 || len <= numRows) {
                return s;
            }
            std::vector<std::string> vec(numRows);
            int cycle = numRows * 2 - 2;
            for (auto i = 0; i < len; ++i) {
                int index = i % cycle;
                if (index >= numRows) {
                    index = cycle - index;
                }
                vec[index].push_back(s[i]);
            }
            
            for (auto i = 1; i < numRows; ++i) {
                vec[0].append(vec[i]);
            }
            return vec[0];
        }
    };

    void Test() {
        Solution so;
        std::string str("LEETCODEISHIRING");
        auto ans = so.convert(str, 50);
        std::cout << ans << std::endl;
    }
}