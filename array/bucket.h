#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace bucket {

    class Solution {
    public:
        int maxArea(vector<int>& height) {
            auto len = height.size();
            if (len < 2) {
                return 0;
            }

            auto ans = 0;
            for (auto i = 0; i < len; ++i) {
                for (auto j = i + 1; j < len; ++j) {
                    auto min_height = std::min(height[i], height[j]);
                    auto temp = min_height * (j - i);
                    if (temp > ans) {
                        ans = temp;
                    }
                }
            }
            return ans;
        }

        int maxAreaA(vector<int>& height) {
            auto len = height.size();
            if (len < 2) {
                return 0;
            }

            int ans = 0;
            for (auto i = 0; i < len; ++i) {
                for (auto j = i + 1; j < len; ++j) {
                    if (height[j] >= height[i]) {
                        if (j + 1 < len && height[j + 1] >= height[i]) {
                            continue;
                        }
                        else {
                            auto temp = height[i] * (j - i);
                            if (temp > ans) {
                                ans = temp;
                            }
                        }
                    }
                    else {
                        auto temp = height[j] * (j - i);
                        if (temp > ans) {
                            ans = temp;
                        }
                    }
                }
            }
            return ans;
        }

        int maxAreaB(vector<int>& height) {
            auto len = height.size();
            if (len < 2) {
                return 0;
            }

            int ans = 0;
            for (std::size_t i = 0, j = len - 1; i < j;) {
                auto min_num = std::min(height[i], height[j]);
                auto temp = min_num * (j - i);
                if (temp > ans) {
                    ans = temp;
                }
                if (height[i] < height[j]) {
                    ++i;
                }
                else {
                    --j;
                }
            }
            return ans;
        }
    };

    void Test() {
        Solution so;
        std::vector<int> vec{ 1,8,6,2,5,4,8,3,7 };
        auto ans = so.maxAreaB(vec);
        std::cout << ans << std::endl;
    }
}