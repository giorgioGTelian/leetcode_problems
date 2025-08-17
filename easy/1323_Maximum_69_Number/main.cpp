class Solution {
public:
    // This method maximizes the value of the given number by changing at most 
    // one digit - change the first '6' to a '9'.
    int maximum69Number(int num) {
        // Convert the integer to a string to manipulate individual characters
        string numStr = to_string(num);

        // Iterate over the characters in the string
        for (char& ch : numStr) {
            // If the character is '6', change it to '9'
            if (ch == '6') {
                ch = '9';
                // After the first change, break out of the loop since we are 
                // allowed to change at most one digit
                break;
            }
        }
        // Convert the string back to an integer to obtain the final result
        return stoi(numStr);
    }
};
