#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        if (nums.size() % 3 != 0) return {}; // Check if divisible by 3

        sort(nums.begin(), nums.end()); // Sort the array

        vector<vector<int>> result;
        vector<int> currentGroup;

        for (int i = 0; i < nums.size(); ++i) {
            currentGroup.push_back(nums[i]);

            if (currentGroup.size() == 3) {
                if (currentGroup.back() - currentGroup.front() > k) {
                    return {}; // Difference exceeds k
                }
                result.push_back(currentGroup);
                currentGroup.clear();
            }
        }

        return result;
    }
};
