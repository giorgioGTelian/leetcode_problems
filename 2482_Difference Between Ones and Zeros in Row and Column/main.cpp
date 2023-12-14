class Solution {
public:
     vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> onesRow(m, 0);
        vector<int> onesCol(n, 0);
        vector<vector<int>> diff(m, vector<int>(n, 0));

        // Calculate the sum of ones in each row and column
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                onesRow[i] += grid[i][j];
                onesCol[j] += grid[i][j];
            }
        }

        // Calculate the difference matrix
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                diff[i][j] = onesRow[i] + onesCol[j] - (m - onesRow[i]) - (n - onesCol[j]);
            }
        }

        return diff;
    }
};
