#pragma once

#include <iostream>
#include <string>

using namespace std;

namespace palindrome {
    class Solution {
    public:
        int FindLongestPalindrome(const std::string& str, int& i, int& j) {
            if (i < 0 || j > str.length()) {
                return 0;
            }

            int ret_len = 0;
            while (i >= 0 && j < str.length()) {
                if (str[i] == str[j]) {
                    ret_len += 2;
                    --i;
                    ++j;
                }
                else {
                    break;
                }
            }
            return ret_len;
        }
        string longestPalindrome(string s) {
            auto len = s.length();
            if (len <= 1) {
                return s;
            }

            std::string ans(1, s[0]);
            for (auto i = 0; (i < len) && (i + 1 < len);) {
                int ret_len1 = 0;
                int low1, high1;
                if (s[i] == s[i + 1]) {
                    low1 = i - 1;
                    high1 = i + 2;
                    ret_len1 = FindLongestPalindrome(s, low1, high1);
                    ret_len1 += 2;
                }

                int ret_len2 = 0;
                int low2, high2;
                if ((i - 1 >= 0) && (s[i - 1] == s[i + 1])) {
                    low2 = i - 2;
                    high2 = i + 2;
                    ret_len2 = FindLongestPalindrome(s, low2, high2);
                    ret_len2 += 3;
                }

                if (ret_len1 > ans.length() && ret_len1 > ret_len2) {
                    ans = s.substr(low1 + 1, ret_len1);
                }
                else if (ret_len2 > ans.length() && ret_len2 > ret_len1) {
                    ans = s.substr(low2 + 1, ret_len2);
                }
                ++i;
            }
            return ans;
        }
    };

    void Test() {
        Solution so;
        std::string str("abba");
        std::string ans = so.longestPalindrome(str);
        std::cout << ans << std::endl;
    }
}