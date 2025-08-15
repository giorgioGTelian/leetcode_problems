# Intuition
The main idea is to find any substring of length 3 where all characters are the same.  
Since we want the **largest** in lexicographical order (which corresponds to the highest digit), we can scan the entire string and keep track of the best triple found so far.

# Approach
1. Iterate through the string starting from index 2.
2. At each step, check if the last three characters are equal.
3. If they are, take the substring of these three characters.
4. Compare this substring with the current maximum using `max` (works because numeric characters are ordered as their digit values in ASCII).
5. Return the largest triple found (or an empty string if none exist).

# Complexity
- **Time complexity:**  
  We traverse the string once → `O(n)`, where `n` is the length of `num`.  
  `substr` is `O(1)` since the length is fixed at 3.  
  Overall: **O(n)**.
  
- **Space complexity:**  
  We only store a few variables and a string of length at most 3.  
  Overall: **O(1)** extra space.

# Code
```cpp
#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  string largestGoodInteger(string num) {
    string ans;

    for (int i = 2; i < num.length(); ++i)
      if (num[i - 2] == num[i - 1] && num[i - 1] == num[i])
        ans = max(ans, num.substr(i - 2, 3));

    return ans;
  }
};
