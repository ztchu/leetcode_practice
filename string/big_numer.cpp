#include "big_numer.h"

#include <algorithm>
#include <iostream>

BigNumber::BigNumber(const std::string& num)
    :num_(num) {}

BigNumber operator+(const BigNumber& lhs, const BigNumber& rhs) {
    std::string result;
    std::string first(lhs.num_);
    std::reverse(first.begin(), first.end());
    std::string second(rhs.num_);
    std::reverse(second.begin(), second.end());

    auto len = first.length() > second.length() ? first.length() : second.length();
    uint8_t carry_flag = 0;
    for (auto i = 0; i < len; ++i) {
        uint8_t first_operator = 0;
        if (i < first.length()) {
            first_operator = first.at(i) - '0';
        }

        uint8_t second_operator = 0;
        if (i < second.length()) {
            second_operator = second.at(i) - '0';
        }

        uint8_t ret = (first_operator + second_operator + carry_flag) % 10;
        carry_flag = (first_operator + second_operator + carry_flag) / 10;
        result.push_back('0' + ret);
    }
    if (carry_flag) {
        result.push_back('0' + carry_flag);
    }

    std::reverse(result.begin(), result.end());
    return BigNumber(result);
}

void TestBigNumber() {
    BigNumber first("9873");
    BigNumber second("3549");

    auto ret = first + second;
    std::cout << ret.Value() << std::endl;
}