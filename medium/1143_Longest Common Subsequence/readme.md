A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

## Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
## Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
## Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

# Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English character



# Intuition
When facing the problem of finding the longest common subsequence (LCS) between two strings, it's essential to consider each character in the strings and how they relate to one another. The key intuition is that if two characters in the respective strings are the same, they should contribute to the LCS. However, if they differ, we need to explore different combinations, either skipping a character in the first string or in the second, to find the longest matching sequence. This leads us to think about a recursive approach initially, which is then optimized using dynamic programming to avoid redundant calculations.

# Approach
The solution involves two functions:
1. `isSubSequence`: A recursive function that checks if `text1` is a subsequence of `text2`. This is more of a supplementary function and not directly used for solving the LCS problem.
2. `longestCommonSubsequence`: The main function that employs dynamic programming. We construct a 2D table `dp`, where `dp[i][j]` represents the length of the LCS of the strings `text1[0..i-1]` and `text2[0..j-1]`. We iterate through each character pair; if characters match, we increment the count from the previous best-known LCS (diagonally back in the table). If they don't match, we take the maximum of the LCS found by skipping one character either from `text1` or `text2` (left or top cell in the table).

# Complexity
- Time complexity: $$O(m \times n)$$, where \( m \) is the length of `text1` and \( n \) is the length of `text2`. This is because we need to fill each cell of our `dp` table once, and each cell's computation takes constant time.
- Space complexity: $$O(m \times n)$$, due to the usage of a 2D `dp` table of size \( m+1 \) by \( n+1 \).
