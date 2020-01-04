#pragma once

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

namespace ato_i {
    class Solution {
    public:
        int myAtoi(string str) {
            if (str.empty()) {
                return 0;
            }

            int flag = 0;
            int len = str.size();
            std::string str_num;
            bool first_char_find = false;
            for (auto i = 0; i < len; ++i) {
                if (!first_char_find) {
                    if (str[i] == ' ') {
                        continue;
                    }
                    else if (str[i] == '+') {
                        flag = 1;
                        first_char_find = true;
                    }
                    else if (str[i] == '-') {
                        flag = -1;
                        first_char_find = true;
                    }
                    else if (str[i] >= '0' && str[i] <= '9') {
                        str_num.push_back(str[i]);
                        first_char_find = true;
                    }
                    else {
                        break;
                    }
                }
                else {
                    if (str[i] >= '0' && str[i] <= '9') {
                        str_num.push_back(str[i]);
                    }
                    else {
                        break;
                    }
                }
            }

            str_num.erase(0, str_num.find_first_not_of('0'));

            if (str_num.empty()) {
                return 0;
            }

            if (str_num.size() >= 10) {
                if (flag == -1) {
                    if (str_num.size() > 10 || str_num >= "2147483648") {
                        return INT_MIN;
                    }
                }
                else if (flag != -1) {
                    if (str_num.size() > 10 || str_num >= "2147483647") {
                        return INT_MAX;
                    }
                }
            }

            if (flag == -1) {
                str_num = "-" + str_num;
            }
            return std::atoi(str_num.c_str());
        }
    };

    void Test() {
        Solution so;
        std::string str("  0000000000012345678");
        auto ans = so.myAtoi(str);
        std::cout << ans << std::endl;
    }
}