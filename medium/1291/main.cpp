#include <vector>

class Solution {
public:
    std::vector<int> sequentialDigits(int low, int high) {
        std::vector<int> result;

        // Generate numbers with sequential digits
        for (int startDigit = 1; startDigit <= 9; ++startDigit) {
            int num = startDigit;
            for (int nextDigit = startDigit + 1; nextDigit <= 9; ++nextDigit) {
                num = num * 10 + nextDigit;
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }

        // Sort the result as the generated numbers might not be in order
        sort(result.begin(), result.end());
        return result;
    }
};
