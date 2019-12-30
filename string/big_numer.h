#pragma once

#include <string>

class BigNumber {
public:
    BigNumber(const std::string& num);
    friend BigNumber operator+(const BigNumber& lhs, const BigNumber& rhs);

    std::string Value() const {
        return num_;
    }

private:
    std::string num_;
};

void TestBigNumber();