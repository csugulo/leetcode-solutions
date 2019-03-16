#include "leetcode_solutions.h"

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
};

int main() {
	Solution s;
	vector<int> heights = { 2,1,5,6,2,3 };
	cout << s.largestRectangleArea(heights) << endl;
}