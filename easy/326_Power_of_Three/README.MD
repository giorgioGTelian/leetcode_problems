# Intuition

When thinking about whether a number is a power of three, the simplest approach is to repeatedly multiply or divide by three until we either reach the target number or exceed it. If we can exactly reach the number starting from 1 by multiplying by 3, it must be a power of three.

# Approach

We start from `1` (which is $3^0$) and keep multiplying by `3` until the current value is greater than or equal to `n`.

* If at any point the current value equals `n`, we return `true`.
* If the loop ends without finding a match, we return `false`.

This works because powers of three grow quickly, so the loop will run only a small number of times even for large `n`. The check `n <= 0` at the start filters out all non-positive numbers, since powers of three are strictly positive.

# Complexity

* **Time complexity:** $O(\log_3 n)$
  Each multiplication by 3 brings us closer to `n` exponentially, so the number of iterations is proportional to $\log_3 n$.
* **Space complexity:** $O(1)$
  We use only a constant amount of extra memory.

# Code

```cpp
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        
        long int a = 1;
        
        while (a < n) {
            a *= 3;
        }
                
        return a == n;
    }
};
```

