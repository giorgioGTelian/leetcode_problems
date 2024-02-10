#include<iostream>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
         int n = s.length();
        int count = 0;

        for (int center = 0; center <= 2*n-1; ++center) {
            int left = center / 2;
            int right = left + center % 2;
            
            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
        }
        return count;
    }
};
/*
#include<iostream>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n,i,f;
        string P = s;

        reverse(P.begin(), P.end());

        if (s == P) {
        int n = s.size()+s.size();
        return n;
        } else { 
              for(int i = 0; i<s.length(); i++) {
            	for (int j = i + 1; j < s.length(); j++) {
			// if a character is repeated
			if (s[i] == s[j]) {
                cout<< "the string is not unique";
            }
            int f = s.size();
            return f;
            }
    }
}
return 0;
}
};
*/
