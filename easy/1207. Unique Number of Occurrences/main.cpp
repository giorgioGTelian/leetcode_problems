//first solution

#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> countMap;  // To store counts of each element
        for (int num : arr) {
            countMap[num]++;
        }

        unordered_set<int> countSet;  // To check for unique counts
        for (auto& pair : countMap) {
            if (!countSet.insert(pair.second).second) {
                // If the count is already in the set, return false
                return false;
            }
        }

        return true;  // All counts are unique
    }
};


//second solution
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_set<int> seenCounts;

        int i = 0;
        while (i < arr.size()) {
            int count = 1;
            while (i + count < arr.size() && arr[i] == arr[i + count]) {
                count++;
            }
            if (!seenCounts.insert(count).second) {
                return false;  // Duplicate count found
            }
            i += count;
        }
        return true;  // All counts are unique
    }
};
