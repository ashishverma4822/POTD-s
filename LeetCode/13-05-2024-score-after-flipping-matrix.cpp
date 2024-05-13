class Solution {
private:
    void toggleRow(vector<vector<int>>& grid, int row) {
        for (int j = 0; j < grid[0].size(); j++) {
            grid[row][j] = grid[row][j] == 0 ? 1 : 0;
        }
    }
    void toggleColumn(vector<vector<int>>& grid, int col) {
        for (int i = 0; i < grid.size(); i++) {
            grid[i][col] = grid[i][col] == 0 ? 1 : 0;
        }
    }
    int binaryToDecimal(vector<int>& binary) {
        int decimal = 0;
        for (int i = binary.size() - 1, j = 0; i >= 0; i--, j++) {
            decimal += binary[i] * pow(2, j);
        }
        return decimal;
    }
public:
    int matrixScore(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            if (grid[i][0] == 0) {
                toggleRow(grid, i);
            }
        }
        for (int j = 1; j < grid[0].size(); j++) {
            int countOnes = 0;
            for (int i = 0; i < grid.size(); i++) {
                countOnes += grid[i][j];
            }
            if (countOnes < grid.size() - countOnes) {
                toggleColumn(grid, j);
            }
        }
        int score = 0;
        for (int i = 0; i < grid.size(); i++) {
            score += binaryToDecimal(grid[i]);
        }
        return score;
    }
};
