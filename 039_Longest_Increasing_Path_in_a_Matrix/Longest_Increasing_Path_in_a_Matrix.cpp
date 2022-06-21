#include "leetcode_solutions.h"

class Solution {
public:
    void calc(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& lengths) {
        if (lengths[i][j] != -1) return; 
        int rows(matrix.size()), cols(matrix[0].size());
        int up(0), right(0), down(0), left(0);
        // up
        if (i != 0 && matrix[i][j] > matrix[i-1][j]) {
            if (lengths[i-1][j] == -1) {
                calc(matrix, i - 1, j, lengths);
            }
            up = lengths[i-1][j];
        }
        // left
        if (j != 0 && matrix[i][j] > matrix[i][j - 1]) {
            if (lengths[i][j - 1] == -1) {
                calc(matrix, i, j - 1, lengths);
            }
            left = lengths[i][j - 1];
        }
        // down
        if (i != rows -1 && matrix[i][j] > matrix[i+1][j]) {
            if (lengths[i + 1][j] == -1) {
                calc(matrix, i + 1, j, lengths);
            }
            down = lengths[i + 1][j];
        }
        // right
        if (j != cols - 1 && matrix[i][j] > matrix[i][j + 1]) {
            if (lengths[i][j + 1] == -1) {
                calc(matrix, i, j + 1, lengths);
            }
            right = lengths[i][j + 1];
        }
        lengths[i][j] = max(max(up, down), max(left, right)) + 1;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int rows(matrix.size()), cols(matrix[0].size()), m(0);
        vector<vector<int>> lengths(rows, vector<int>(cols, -1));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                calc(matrix, i, j, lengths);
                if(lengths[i][j] > m) m = lengths[i][j];
            }
        }
        return m;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // vector<vector<int>> mat = {{9,9,4},{6,6,8},{2,1,1}};
    vector<vector<int>> mat = {{3,4,5},{3,2,6},{2,2,1}};
    cout << s.longestIncreasingPath(mat) << endl;
    return 0;
}
