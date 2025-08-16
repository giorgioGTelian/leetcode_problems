class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        
        long int a = 1;
        
        while (a < n)
        {
            a *= 3;
        }
                
        return a == n;
    }
};
