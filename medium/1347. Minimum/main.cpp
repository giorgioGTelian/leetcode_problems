class Solution {
public:
    int minSteps(string s, string t) {
        //numbers of letters in the alfabet
        vector<int> count(26);

        //iterate throgh each input back and foward
        for (const char c : s) {
            ++count[c - 'a'];
        }
        for (const char c : t) {
            --count[c - 'a'];
        }
        
        return accumulate(count.begin(), count.end(), 0, [](int subtotal, int c) {return subtotal + abs(c); }) / 2;
    }
};
