#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int max_count = 0; // Variable to track the maximum occurrence count
        int vecSize = nums.size();
        int element = -1; // Default value if no majority element is found

        // Loop to count occurrences and find the maximum occurrence count
        for (int i = 0; i < vecSize; i++) {
            int count = 1; // Counter to track the occurrence of each number
            for (int j = i + 1; j < vecSize; j++)
                if (nums[i] == nums[j]) // Checking if the element at index 'i' is equal to the element at index 'j'
                    count++; // Incrementing the counter for the same elements

            if (count > max_count) { // Checking if the current count is greater than the maximum count
                max_count = count; // Updating the maximum count with the new higher count
                element = nums[i]; // Storing the element with the maximum count
            }
        }

        // Checking if a majority element was found (occurs more than n/2 times)
        if (max_count > vecSize / 2) {
            return element;
        } else {
            return -1; // Return -1 if no majority element exists
        }
    }
};

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int max_count = 0; // Variable to track the maximum occurrence count
        int vecSize = nums.size();
        cout << "\nMost occurred number: "; // Output message to indicate displaying the most occurred number(s)

        // Loop to count occurrences and find the maximum occurrence count
        for (int i = 0; i < vecSize; i++) {
            int count = 1; // Counter to track the occurrence of each number
            for (int j = i + 1; j < vecSize; j++)
                if (nums[i] == nums[j]) // Checking if the element at index 'i' is equal to the element at index 'j'
                    count++; // Incrementing the counter for the same elements

            if (count > max_count) // Checking if the current count is greater than the maximum count
                max_count = count; // Updating the maximum count with the new higher count
        }

        // Loop to output the number(s) with the maximum occurrence count
        for (int i = 0; i < vecSize; i++)
        {
            int count = 1; // Counter to track the occurrence of each number
            for (int j = i + 1; j < vecSize; j++)
                if (nums[i] == nums[j]) // Checking if the element at index 'i' is equal to the element at index 'j'
                    count++; // Incrementing the counter for the same elements

            if (count == max_count) // Checking if the current count is equal to the maximum count
                return nums[i]; // Return the element with the maximum count
        }

        return -1; // Return -1 if no majority element is found
    }
};
