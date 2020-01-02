#pragma once

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

namespace longest_substr {
    class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            if (s.length() <= 1) {
                return s.length();
            }
            int ret = 1;
            for (auto i = 0; i < s.length();) {
                std::set<char> temp_set{ s.at(i) };
                int j = i + 1;
                for (; j < s.length(); ++j) {
                    if (temp_set.find(s.at(j)) == temp_set.end()) {
                        temp_set.insert(s.at(j));
                    }
                    else {
                        break;
                    }
                }
                if (ret < temp_set.size()) {
                    ret = temp_set.size();
                }
                if (s.length() - i - 1 <= ret) {
                    break;
                }
                if (j < s.length()) {
                    i = j + 1;
                }
                else {
                    break;
                }
            }
            return ret;
        }

        int lengthOfLongestSubstringA(string s) {
            int i = 0, j = 0;
            int ans = 0;
            int len = s.length();
            std::set<char> temp_set;
            while (i < len && j < len) {
                if (temp_set.find(s[j]) == temp_set.end()) {
                    temp_set.insert(s[j++]);
                    ans = std::max<int>(ans, j - i);
                }
                else {
                    temp_set.erase(s[i++]);
                }
            }
            return ans;
        }

        int lengthOfLongestSubstringB(string s) {
            int i = 0, j = 0;
            int ans = 0;
            int len = s.length();
            std::map<char, int> temp_set;
            while (i < len && j < len) {
                if (temp_set.find(s[j]) != temp_set.end()) {
                    i = std::max<int>(temp_set[s[j]], i);
                }
                
                temp_set.insert({ s[j], j + 1});
                
                ans = std::max<int>(ans, j - i + 1);
                ++j;
            }
            return ans;
        }
    };

    void TestLongestSubstr() {
        Solution so;
        std::string str("abcabcbb");
        std::cout << so.lengthOfLongestSubstringB(str) << std::endl;
    }

}