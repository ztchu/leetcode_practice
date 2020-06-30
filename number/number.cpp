#include "number.h"

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

namespace test_number {
	float SqrtA() {
		float low = 1.0, high = 2.0;
		float mid_square = 0, mid = 0;
		do {
			mid = (low + high) / 2;
			mid_square = mid * mid;
			if (mid_square < 2) {
				low = mid;
			}
			else if (mid_square > 2) {
				high = mid;
			}
		} while (std::abs(mid_square - 2) > 0.000001);
		return mid;
	}

	float SqrtB() {
		float low = 1.0, high = 2.0;
		float mid_square = 0, mid = 0;
		while (1) {
			mid = (low + high) / 2;
			mid_square = mid * mid;
			if (std::abs(mid_square - 2) < 0.000001) {
				break;
			}
			if (mid_square < 2) {
				low = mid;
			}
			else if (mid_square > 2) {
				high = mid;
			}
		}
		return mid;
	}

	void Test() {
		std::cout << SqrtB() << std::endl;
	}

    class Solution {
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target) {
            std::unordered_map<int, int> hash_map;
            for (auto i = 0; i < nums.size(); ++i) {
                hash_map.insert({ nums[i], i });
            }

            for (auto i = 0; i < nums.size(); ++i) {
                auto iter = hash_map.find(target - nums[i]);
                if (iter != hash_map.end() && iter->second != i) {
                    auto min = iter->second > i ? i : iter->second;
                    auto max = iter->second > i ? iter->second : i;
                    return std::vector<int>{min, max};
                }
            }
            return std::vector<int>();
        }

        int reverse(int x) {
            if (x == 0) {
                return 0;
            }

            bool flag = true;
            unsigned long input = x;
            if (x < 0) {
                flag = false;
                input = static_cast<unsigned long>(0) - x;
            }

            while (input % 10 == 0) input /= 10;

            unsigned long ans = 0;
            size_t len = 0;
            while (input) {
                ans *= 10;
                ans += (input % 10);
                input /= 10;
                ++len;
            }

            if (len >= 10) {
                if (flag) {
                    if (ans > INT_MAX) {
                        return 0;
                    }
                }
                else {
                    if (ans - 1 > INT_MAX) {
                        return 0;
                    }
                }
            }

            if (!flag) {
                return 0 - ans;
            }
            return ans;
        }

        int reverseB(int x) {
            int rev = 0;
            while (x) {
                int pop = x % 10;
                x /= 10;

                if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
                if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
                rev = rev * 10 + pop;
            }
            return rev;
        }

        int removeDuplicates(std::vector<int>& nums) {
            auto len = nums.size();
            if (len == 0) {
                return 0;
            }

            int i = 0;
            while (i < len && i + 1 < len && nums[i] != nums[i + 1]) ++i;
            if (i + 1 >= len) {
                return i + 1;
            }

            int j = i + 1;
            while (1) {
                while (j < len && j + 1 < len && nums[j] == nums[j + 1]) ++j;
                ++i;
                if (i < len && j + 1 < len) {
                    nums[i] = nums[j + 1];
                    ++j;
                }
                else {
                    break;
                }
            }
            return i;
        }

        int maxSubArrayA(std::vector<int>& nums) {
            if (nums.empty()) {
                return 0;
            }
            std::vector<int> sum(nums.size(), 0);
            sum[0] = nums[0];
            for (int i = 1; i < nums.size(); ++i) {
                sum[i] += sum[i - 1] + nums[i];
            }

            int ans = sum[0];
            for (int i = 0; i < nums.size(); ++i) {
                for (int j = i + 1; j < nums.size(); ++j) {
                    if (sum[i] <= 0 && sum[j] - sum[i] > ans) {
                        ans = sum[j] - sum[i];
                    }
                    if (sum[i] > 0 && sum[j] > ans) {
                        ans = sum[j];
                    }
                }
            }
            return ans;
        }

        int maxSubArrayB(std::vector<int>& nums) {
            if (nums.empty()) {
                return 0;
            }
            int pre = 0, max = nums[0];
            for (int i = 0; i < nums.size(); ++i) {
                pre = std::max(pre + nums[i], nums[i]);
                max = std::max(pre, max);
            }
            return max;
        }

        int removeElement(std::vector<int>& nums, int val) {
            if (nums.empty()) return 0;
            int i = 0;
            while (i < nums.size() && nums[i] != val) ++i;
            int j = i + 1;
            for (; j < nums.size(); ++j) {
                if (nums[j] != val) {
                    nums[i] = nums[j];
                    ++i;
                }
            }

            return i;
        }
    };

    void TestTwoSum() {
        std::vector<int> input{ 3, 2, 4 };
        int target = 6;
        Solution so;
        auto ans = so.twoSum(input, target);
        for (int i = 0; i < ans.size(); ++i) {
            std::cout << ans[i] << " ";
        }
        std::cout << std::endl;
    }

    void TestReverse() {
        Solution so;
        int input = (int)(3648);
        std::cout << so.reverseB(input) << std::endl;
    }

    void TestRemoveDuplicates() {
        std::vector<int> input{1};
        Solution so;
        auto ans = so.removeDuplicates(input);
        std::cout << ans << std::endl;
        for (auto& item : input) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }

    void TestMaxSubArray() {
        Solution so;
        std::vector<int> input{ 0, 3, -1};
        auto ans = so.maxSubArrayB(input);
        std::cout << ans << std::endl;
    }

    void TestRemoveElements() {
        Solution so;
        std::vector<int> input{ 1, 3, 3 };
        auto ans = so.removeElement(input, 1);
        std::cout << ans << std::endl;
        for (int i = 0; i < input.size(); ++i) {
            std::cout << input[i] << " ";
        }
        std::cout << std::endl;
    }
}