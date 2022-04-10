#include "leetcode_solutions.h"

class Solution {
public:

    int binaryRow(vector<vector<int>>& matrix, int p, int q, int target) {
        if (p == q) {
            if (matrix[p][0] <= target) return p;
            else return -1; 
        }
        int mid = (q + p) / 2;
        if (matrix[mid+1][0] > target) return binaryRow(matrix, p, mid, target);
        else return binaryRow(matrix, mid+1, q, target);
    };

    bool binaryCol(vector<int>& row, int p, int q, int target) {
        if (p == q) {
            if (row[p] == target) return true;
            else return false;
        }
        int mid = (q + p) / 2;
        if (row[mid] >= target) return binaryCol(row, p, mid, target);
        else return binaryCol(row, mid + 1, q, target);

    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int row_id = binaryRow(matrix, 0, matrix.size() - 1, target);
        if (row_id == -1) return false;
        return binaryCol(matrix[row_id], 0, matrix[row_id].size() - 1, target);
    }
};


int main(){
	Solution s;
    vector<vector<int>> mat = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
	cout << s.searchMatrix(mat, 70);
}