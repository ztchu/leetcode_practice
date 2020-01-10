#pragma once

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

namespace three_number {
    using namespace std;
    class Solution {
    public:
        //vector<vector<int>> threeSum(vector<int>& nums) {
        //    std::vector<std::vector<int>> ans;
        //    if (nums.size() < 3) {
        //        return ans;
        //    }
        //    std::sort(nums.begin(), nums.end());

        //    for (int i = 0, j = nums.size() - 1; i < j; ) {
        //        auto temp = nums[i] + nums[j];
        //        if (temp > 0) {
        //            int k = i + 1;
        //            for (; k < j; ++k) {
        //                if (nums[k] + temp < 0) {
        //                    continue;
        //                }
        //                else if (nums[k] + temp == 0) {
        //                    ans.push_back({ nums[i], nums[k], nums[j] });
        //                    ++i;
        //                    break;
        //                }
        //                else {
        //                    --j;
        //                    break;
        //                }
        //            }
        //            if (k == j) {
        //                --j;
        //            }
        //        }
        //        else if (temp == 0) {
        //            /*if ((i + 1 < j) && nums[i + 1] == 0) {
        //                ans.push_back({ nums[i], nums[i + 1], nums[j] });
        //            }
        //            else if ((j - 1 > i) && nums[j - 1] == 0) {
        //                ans.push_back({ nums[i], nums[j - 1], nums[j] });
        //            }
        //            else {
        //                break;
        //            }*/
        //            if (std::binary_search(nums.begin(), nums.end(), 0)) {
        //                ans.push_back({ nums[i], 0, nums[j] });
        //            }
        //            ++i;
        //        }
        //        else if (temp < 0) {
        //            auto k = j - 1;
        //            for (; k > i; --k) {
        //                if (nums[k] + temp < 0) {
        //                    ++i;
        //                    break;
        //                }
        //                else if (nums[k] + temp == 0) {
        //                    ans.push_back({ nums[i], nums[k], nums[j] });
        //                    --j;
        //                }
        //                else {
        //                    continue;
        //                }
        //            }
        //            if (k == i) {
        //                ++i;
        //            }
        //        }
        //    }
        //}

        vector<vector<int>> threeSum(vector<int>& nums) {
            std::vector<std::vector<int>> ans;
            if (nums.size() < 3) {
                return ans;
            }

            std::multimap<int, std::pair<int, int>> binary_pair;
            std::set<std::pair<int, int>> unique_set;
            for (auto i = 0; i < nums.size(); ++i) {
                for (auto j = i + 1; j < nums.size(); ++j) {
                    std::pair<int, int> two_num(std::min(nums[i], nums[j]), std::max(nums[i], nums[j]));
                    if (unique_set.find(two_num) == unique_set.end()) {
                        unique_set.insert(two_num);
                        binary_pair.insert({ 0 - nums[i] - nums[j], {i, j } });
                    }
                }
            }

            using map_iter = std::multimap<int, std::pair<int, int>>::iterator;
            for (auto i = 0; i < nums.size(); ++i) {
                auto low_boundary = binary_pair.lower_bound(nums[i]);
                auto upper_boundary = binary_pair.upper_bound(nums[i]);
                if (low_boundary != upper_boundary) {
                    for (auto iter = low_boundary; iter != upper_boundary; ++iter) {
                        if (i != iter->second.first && i != iter->second.second) {
                            std::vector<int> vec{ nums[i], nums[iter->second.first], nums[iter->second.second] };
                            std::sort(vec.begin(), vec.end());
                            if (std::find(ans.begin(), ans.end(), vec) == ans.end()) {
                                ans.push_back(std::move(vec));
                            }
                        }
                    }
                }
            }
            std::sort(ans.begin(), ans.end());
            return ans;
        }

        vector<vector<int>> threeSumA(vector<int>& nums) {
            std::vector<std::vector<int>> ans;
            int nums_len = nums.size();
            if (nums_len < 3) {
                return ans;
            }

            std::sort(nums.begin(), nums.end());

            std::set<std::pair<int, int>> unique_set;
            int j_init = nums_len - 1;
            for (auto i = 0; i < nums_len; ) {
                auto test_value = 0 - nums[i] - nums[j_init];
                if (test_value > nums[j_init]) {
                    ++i;
                    continue;
                }
                else if (test_value < nums[i]) {
                    --j_init;
                    if (j_init <= i) {
                        break;
                    }
                    continue;
                }
                else {
                    for (auto j = j_init; j > i; --j) {
                        if (unique_set.find({ nums[i], nums[j] }) == unique_set.end()) {
                            unique_set.insert({ nums[i], nums[j] });
                        }
                        else {
                            continue;
                        }
                        auto value = 0 - nums[i] - nums[j];
                        if (value < nums[i]) {
                            break;
                        }
                        auto begin_iter = nums.begin();
                        std::advance(begin_iter, i + 1);

                        auto end_iter = nums.end();
                        std::advance(end_iter, j - nums_len);

                        if (std::binary_search(begin_iter, end_iter, value)) {
                            ans.push_back({ nums[i],std::min(value, nums[j]), std::max(value, nums[j]) });
                        }
                    }
                    ++i;
                }
            }

            return ans;
        }

        vector<vector<int>> threeSumB(vector<int>& nums) {
            std::vector<std::vector<int>> ans;
            int nums_len = nums.size();
            if (nums_len < 3) {
                return ans;
            }

            std::sort(nums.begin(), nums.end());

            int low_index = 0;
            if (2 * nums.back() < 0 - nums.front()) {
                auto iter = std::lower_bound(nums.begin(), nums.end(), 0 - 2 * nums.back());
                low_index = std::distance(nums.begin(), iter);
            }
            int high_index = nums_len - 1;
            if (2 * (0 - nums.front()) < nums.back()) {
                auto iter = std::upper_bound(nums.begin(), nums.end(), 2 * (0 - nums.front()));
                high_index = std::distance(nums.begin(), iter);
            }

            for (int left = low_index; left < high_index && nums[left] <= 0; ++left) {
                int temp = 0 - nums[left];
                int right_index = high_index;
                int mid = left + 1;
                if (left > 0 && nums[left] == nums[left - 1]) {
                    continue;
                }
                while (mid < right_index) {
                    if (nums[mid] + nums[right_index] < temp) {
                        ++mid;
                        continue;
                    }
                    else if (nums[mid] + nums[right_index] == temp) {
                        auto mid_value = nums[mid];
                        auto right_value = nums[right_index];
                        ans.push_back({ nums[left], mid_value, right_value });
                        while (mid < right_index && nums[--right_index] == right_value) {
                            continue;
                        }
                        while (mid < right_index && nums[++mid] == mid_value) {
                            continue;
                        }
                    }
                    else {
                        --right_index;
                    }
                }
            }
            return ans;
        }

        vector<vector<int>> threeSumC(vector<int>& nums) {
            std::vector<std::vector<int>> ans;
            int nums_len = nums.size();
            if (nums_len < 3) {
                return ans;
            }

            std::sort(nums.begin(), nums.end());

            int high_index = nums_len - 1;
            for (int low_index = 0; low_index < nums_len && nums[low_index] <= 0; ++low_index) {
                if (2 * nums[high_index] < 0 - nums[low_index]) {
                    auto begin_iter = nums.begin();
                    std::advance(begin_iter, low_index);
                    auto end_iter = nums.end();
                    std::advance(end_iter, high_index - nums_len + 1);
                    auto iter = std::lower_bound(begin_iter, end_iter, 0 - 2 * nums[high_index]);
                    low_index = std::distance(nums.begin(), iter);
                }

                if (low_index >= nums_len) {
                    break;
                }

                if (2 * (0 - nums[low_index]) < nums[high_index]) {
                    auto begin_iter = nums.begin();
                    std::advance(begin_iter, low_index);
                    auto end_iter = nums.end();
                    std::advance(end_iter, high_index - nums_len + 1);
                    auto iter = std::upper_bound(begin_iter, end_iter, 2 * (0 - nums[low_index]));
                    high_index = std::distance(nums.begin(), iter);
                }

                if (high_index >= nums_len) {
                    break;
                }

                int temp = 0 - nums[low_index];
                int right_index = high_index;
                int mid = low_index + 1;
                if (low_index > 0 && nums[low_index] == nums[low_index - 1]) {
                    continue;
                }
                while (mid < right_index) {
                    if (nums[mid] + nums[right_index] < temp) {
                        ++mid;
                        continue;
                    }
                    else if (nums[mid] + nums[right_index] == temp) {
                        auto mid_value = nums[mid];
                        auto right_value = nums[right_index];
                        ans.push_back({ nums[low_index], mid_value, right_value });
                        while (mid < right_index && nums[--right_index] == right_value) {
                            continue;
                        }
                        while (mid < right_index && nums[++mid] == mid_value) {
                            continue;
                        }
                    }
                    else {
                        --right_index;
                    }
                }
            }
            return ans;
        }
    };

    

    void Test() {
        std::vector<int> input{
            -4, -2, -1

        };
        Solution so;
        auto ans = so.threeSumC(input);
        for (auto i = 0; i < ans.size(); ++i) {
            std::for_each(ans[i].begin(), ans[i].end(), [](int num) { std::cout << num << " "; });
            std::cout << std::endl;
        }
    }
}