# Problem 2966: Divide Array Into Arrays With Max Difference

**Difficulty**: Medium

### Description

Given an integer array `nums` of size `n` and a positive integer `k`, the task is to divide the array into one or more arrays of size 3 with the following conditions:

- Each element of `nums` should be in exactly one array.
- The difference between any two elements in one array is less than or equal to `k`.

The goal is to return a 2D array containing all the arrays. If it is impossible to satisfy the conditions, return an empty array. If there are multiple answers, return any of them.

### Examples

**Example 1:**

- **Input**: `nums = [1,3,4,8,7,9,3,5,1]`, `k = 2`
- **Output**: `[[1,1,3],[3,4,5],[7,8,9]]`
- **Explanation**: The array can be divided into [1,1,3], [3,4,5], and [7,8,9]. The difference between any two elements in each array is less than or equal to 2. The order of elements is not important.

**Example 2:**

- **Input**: `nums = [1,3,3,2,7,3]`, `k = 3`
- **Output**: `[]`
- **Explanation**: It is not possible to divide the array satisfying all the conditions.

### Constraints

- `n == nums.length`
- `1 <= n <= 105`
- `n` is a multiple of 3.
- `1 <= nums[i] <= 105`
- `1 <= k <= 105`

