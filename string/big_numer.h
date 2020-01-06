#pragma once

#include <array>
#include <iostream>
#include <string>
#include <vector>

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

namespace rome {
    using namespace std;
    class Solution {
    public:
        char rome_table[4][3] = { {'I', 'V', 'X'}, {'X', 'L', 'C'},
                                  {'C', 'D', 'M'}, {'M', 'Z', 'Z' } };
        string intToRoman(int num) {
            std::vector<unsigned char> single_bit;
            while (num) {
                single_bit.push_back(num % 10);
                num /= 10;
            }
            
            std::string ans;
            for (int i = single_bit.size() - 1; i >= 0; --i) {
                if (single_bit[i] >= 0 && single_bit[i] <= 3) {
                    ans.insert(ans.end(), single_bit[i], rome_table[i][0]);
                }
                else if (single_bit[i] == 4) {
                    ans.push_back(rome_table[i][0]);
                    ans.push_back(rome_table[i][1]);
                }
                else if (single_bit[i] >= 5 && single_bit[i] < 9) {
                    ans.push_back(rome_table[i][1]);
                    ans.insert(ans.end(), single_bit[i] - 5, rome_table[i][0]);
                }
                else {
                    ans.push_back(rome_table[i][0]);
                    ans.push_back(rome_table[i][2]);
                }
            }
            return ans;
        }
    };

    void Test();
}