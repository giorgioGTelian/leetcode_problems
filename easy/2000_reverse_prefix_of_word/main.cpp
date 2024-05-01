#include <string>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        
        
        if(word.find(ch) != string::npos) {
            size_t pos = word.find(ch); 
            string wordUntilCH = word.substr(0, pos);
            string remainingWord = word.substr(pos + 1); // Extract substring up to the found character
            reverse(wordUntilCH.begin(), wordUntilCH.end()); // Reverse the substring
            string result = ch + wordUntilCH + remainingWord;
            return result;
        } else {
            return word;
        }
        
    }
};
