#include "leetcode_solutions.h"

struct Label {
	int right = 0;
	int height = 0;
};


class Solution {
public:

	int largestRectangleArea(vector<int>& heights) {
		if (heights.size() == 0) return 0;
		int len(heights.size());

		vector<int> leftIdxs(len, 0), rightIdxs(len, len - 1);

		leftIdxs[0] = 0;
		for (int i = 1; i < len; ++i) {
			if (heights[i] > heights[i - 1]) {
				leftIdxs[i] = i;
			}
			else if (heights[i] == heights[i - 1]) {
				leftIdxs[i] = leftIdxs[i - 1];
			}
			else {
				for (int j = leftIdxs[i - 1] - 1; j >= 0; j--) {
					if (heights[j] < heights[i]) {
						leftIdxs[i] = j + 1;
						break;
					}
				}
			}
		}

		rightIdxs[len - 1] = len - 1;
		for (int i = len - 2; i >= 0; --i) {
			if (heights[i] > heights[i + 1]) {
				rightIdxs[i] = i;
			}
			else if (heights[i] == heights[i + 1]) {
				rightIdxs[i] = rightIdxs[i + 1];
			}
			else {
				for (int j = rightIdxs[i + 1] + 1; j < len; ++j) {
					if (heights[j] < heights[i]) {
						rightIdxs[i] = j - 1;
						break;
					}
				}
			}
		}


		int maxArea = 0;
		for (int i = 0; i < len; ++i) {
			maxArea = max(maxArea, heights[i] * (rightIdxs[i] - leftIdxs[i] + 1));
		}
		return maxArea;

	}

	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
		int rows(matrix.size()), cols(matrix[0].size());
		
		vector<vector<Label>> dp(rows, vector<Label>(cols));

		// right 
		for (int i = 0; i < rows; ++i) {
			for (int j = cols - 1; j >= 0; --j) {
				if (matrix[i][j] == '0') continue;
				if (j == cols - 1) dp[i][j].right = cols - 1;
				else {
					if (matrix[i][j + 1] == '1') dp[i][j].right = dp[i][j + 1].right;
					else dp[i][j].right = j;
				}
			}
		}

		// height
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j)
			{
				if (matrix[i][j] == '0') continue;
				if (i == 0) dp[i][j].height = 1;
				else {
					if (matrix[i - 1][j] == '1') dp[i][j].height = dp[i - 1][j].height + 1;
					else dp[i][j].height = 1;
				}
			}
		}

		// area
		int maxArea = 0;
		for (int i = 0; i < rows; ++i) {
			int j = 0;
			while (j < cols) {
				if (matrix[i][j] == '0') {
					++j;
					continue;
				}
				vector<int> heights;
				for (int k = j; k <= dp[i][j].right; ++k) heights.push_back(dp[i][k].height);
				int area = largestRectangleArea(heights);
				maxArea = max(area, maxArea);
				j = dp[i][j].right + 1;
			}
		}

		return maxArea;

	}
};


int main() {
	vector<vector<char>> matrix;
	matrix.push_back({ '1', '0', '1', '0', '0' });
	matrix.push_back({ '1', '0', '1', '1', '1' });
	matrix.push_back({ '1', '1', '1', '1', '1' });
	matrix.push_back({ '1', '0', '0', '1', '0' });

	Solution s;
	cout << s.maximalRectangle(matrix) << endl;
}