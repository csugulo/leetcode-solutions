#include "leetcode_solutions.h"

inline void swap(int & a, int & b) {
	int tmp = a;
	a = b;
	b = tmp;
}

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		size_t n = matrix.size();
		for (size_t i = 0; i < n / 2; ++i)
			for(size_t j = 0; j < n; ++j)
				swap(matrix[i][j], matrix[n - 1 - i][j]);
		for (size_t row = 0; row < n - 1; ++row)
			for (size_t col = row + 1; col < n; ++col)
				swap(matrix[row][col], matrix[col][row]);
	}
};

int main() {
	Solution s;
	vector<vector<int>> matrix = { {1,2,3},{4,5,6},{7,8,9} };
	s.rotate(matrix);
	cout<<matrix;
}