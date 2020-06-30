#pragma once

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

namespace expression {
    class Solution {
    public:
        bool equationsPossible(std::vector<std::string>& equations) {
            std::vector<std::set<char>> equal;
            std::sort(equations.begin(), equations.end());
            for (auto& item : equations) {
                if (item[1] == '=' && item[2] == '=') {
                    for (auto& set : equal) {
                        if (set.find(item[0]) != set.end()) {
                            set.insert(item[3]);
                            continue;
                        }
                        if (set.find(item[3]) != set.end()) {
                            set.insert(item[0]);
                            continue;
                        }
                    }
                    equal.emplace_back(std::set<char>{item[0], item[3]});
                }
            }

            for (auto& item : equations) {
                if (item[1] == '!' && item[2] == '=') {
                    if (item[0] == item[3]) {
                        return false;
                    }
                    for (auto& set : equal) {
                        if (set.find(item[0]) != set.end() && set.find(item[3]) != set.end()) {
                            return false;
                        }
                    }
                }
            }
            return true;
        }

        int strStr(std::string haystack, std::string needle) {
            int len = needle.length();
            if (len == 0) {
                return 0;
            }
            for (int i = 0; i < haystack.size(); ++i) {
                if (haystack[i] == needle[0]) {
                    auto temp = haystack.substr(i, len);
                    if (temp == needle) {
                        return i;
                    }
                }
            }
            return -1;
        }

        int searchInsert(std::vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size() - 1;

            while (left <= right) {
                int mid = (left + right) / 2;
                if (nums[mid] == target) {
                    return mid;
                }
                else if (nums[mid] < target) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            return left;
        }


        int lengthOfLastWord(string s) {
            int ans = 0;
            int i = s.length() - 1;
            while (i >= 0 && s[i] == ' ') --i;

            for (; i >= 0; --i) {
                if (s[i] != ' ') {
                    ++ans;
                }
                else {
                    break;
                }
            }
            return ans;
        }

        std::vector<int> plusOne(std::vector<int>& digits) {
            bool flag = true;
            for (int i = digits.size() - 1; i >= 0; --i) {
                if (digits[i] + flag == 10) {
                    flag = true;
                    digits[i] = 0;
                }
                else {
                    flag = false;
                    digits[i] += 1;
                    break;
                }
            }
            if (flag) {
                digits.insert(digits.begin(), 1);
            }
            return digits;
        }

        std::string addBinary(std::string a, std::string b) {
            std::reverse(a.begin(), a.end());
            std::reverse(b.begin(), b.end());

            size_t lena = a.length();
            size_t lenb = b.length();
            size_t len = lena > lenb ? lena : lenb;
            std::string ans;
            bool flag = false;
            for (int i = 0; i < len; ++i) {
                char ch_a = '0', ch_b = '0';
                if (i < lena) {
                    ch_a = a[i];
                }
                if (i < lenb) {
                    ch_b = b[i];
                }
                char temp = (ch_a - '0') + (ch_b - '0') + flag;
                flag = false;
                if (temp >= 2) {
                    ans.push_back(temp - 2 + '0');
                    flag = true;
                }
                else {
                    ans.push_back(temp + '0');
                }
            }
            if (flag) {
                ans.push_back('1');
            }
            std::reverse(ans.begin(), ans.end());
            return ans;
        }

        int mySqrt(int x) {
            if (x <= 0) {
                return 0;
            }

            for (int i = 1; i <= x; ++i) {
                if (i <= x / i && (x / (i + 1) < i + 1)) {
                    return i;
                }
            }
            return 0;
        }

    };

    void TestExpression() {
        expression::Solution so;
        std::vector<std::string> input{ "a==b","e==c","b==c","a!=e"};
        if (so.equationsPossible(input)) {
            std::cout << "true";
        }
        else {
            std::cout << "false";
        }
    }

    void TestStrStr() {
        expression::Solution so;
        std::string input("lloo");
        std::string target("ll");
        auto ans = so.strStr(input, target);
        std::cout << ans << std::endl;
    }

    void TestSearchInsert() {
        expression::Solution so;
        std::vector<int> input{ 1, 2, 3, 5, 6 };
        auto ans = so.searchInsert(input, 7);
        std::cout << ans << std::endl;
    }

    void TestLastWord() {
        expression::Solution so;
        auto ans = so.lengthOfLastWord("a ");
        std::cout << ans << std::endl;
    }

    void TestPlusOne() {
        expression::Solution so;
        std::vector<int> input{ 9 };
        auto ans = so.plusOne(input);
        for (auto item : input) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }

    void TestAddBinary() {
        expression::Solution so;
        std::string a("1111");
        std::string b("1111");
        auto ans = so.addBinary(a, b);
        std::cout << ans << std::endl;
    }

    void TestMySqrt() {
        expression::Solution so;
        auto ans = so.mySqrt(8);
        std::cout << ans << std::endl;
    }
}


