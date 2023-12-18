class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
     // Step 1: Sort the array
    std::sort(nums.begin(), nums.end());

    // Step 2 & 3: Find the maximum and minimum product pairs
    int n = nums.size();
    int maxProduct = nums[n - 1] * nums[n - 2]; // Product of the two largest elements
    int minProduct = nums[0] * nums[1];         // Product of the two smallest elements

    // Step 4: Calculate the product difference
    int productDifference = maxProduct - minProduct;

    // Step 5: Return the result
    return productDifference;
}
};
