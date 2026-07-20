// problem 1260     
// link: https://leetcode.com/problems/shift-2d-grid/
// given a 2D grid of size m x n and an integer k. You need to shift the grid k times.
// example: 
// Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
// Output: [[9,1,2],[3,4,5],[6,7,8]]
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        // Number of rows
        int n = grid.size();

        // Number of columns
        int m = grid[0].size();

        // Create the answer matrix
        vector<vector<int>> ans(n, vector<int>(m));

        // Total number of cells
        int total = n * m;

        // Reduce extra rotations
        k %= total;

        // Visit every element
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Convert current 2D position into 1D index
                int idx = i * m + j;

                // Find new index after shifting right by k
                int newIdx = (idx + k) % total;

                // Convert new 1D index back into row and column
                int newRow = newIdx / m;
                int newCol = newIdx % m;

                // Place the element in its new position
                ans[newRow][newCol] = grid[i][j];
            }
        }

        // Return the shifted grid
        return ans;
    }
};