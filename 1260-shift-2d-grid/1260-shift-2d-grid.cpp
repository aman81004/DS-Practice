#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> shiftGrid(std::vector<std::vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        
        // Optimize k to avoid redundant full-grid cycles
        k = k % total;
        
        // Initialize the result matrix with the same dimensions
        std::vector<std::vector<int>> result(m, std::vector<int>(n, 0));
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                // Flatten, shift, and wrap around using modulo math
                int newFlatIndex = (r * n + c + k) % total;
                
                // Extract the new 2D row and column indexes
                int newRow = newFlatIndex / n;
                int newCol = newFlatIndex % n;
                
                // Assign the original value to its new home
                result[newRow][newCol] = grid[r][c];
            }
        }
        
        return result;
    }
};