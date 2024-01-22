#include <vector>
#include <iostream>
#include <algorithm> // For std::sort

class Solution {
public:
    std::vector<int> findErrorNums(std::vector<int>& nums) {
        int m = nums.size();
        std::sort(nums.begin(), nums.end()); // Sort the vector first

        int duplicate = -1, missing = 1;
        for (int i = 0; i < m; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                duplicate = nums[i];
            }
        }

        for (int i = 1; i <= m; ++i) {
            if (!std::binary_search(nums.begin(), nums.end(), i)) {
                missing = i;
                break;
            }
        }

        std::vector<int> result = {duplicate, missing};
        return result;
    }
};
