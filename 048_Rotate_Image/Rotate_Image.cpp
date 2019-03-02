#include "leetcode_solutions.h"

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		size_t n = matrix.size();
		for (size_t i = 0; i < n / 2; ++i)
			swap(matrix[i], matrix[n - 1 - i]);
		for (size_t row = 0; row < n - 1; ++row)
			for (size_t col = row + 1; col < n; ++col)
				swap(matrix[row][col], matrix[col][row]);
	}
};

int main() {
	Solution s;
	vector<vector<int>> matrix = { {1} };
	s.rotate(matrix);
	cout<<matrix;
}