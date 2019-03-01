#include "leetcode_solutions.h"

class Solution {
public:
	int trap(vector<int>& height) {
		if (height.size() < 3) return 0;
		size_t p(0), q(height.size() - 1);
		int maxP(0), maxQ(0), water(0);
		while (p <= q) {
			if (height[p] <= height[q]) {
				if (height[p] >= maxP) maxP = height[p];
				else water += maxP - height[p];
				p++;
			}
			else {
				if (height[q] >= maxQ) maxQ = height[q];
				else water += maxQ - height[q];
				q--;
			}
		}
		return water;
	}
};

int main() {
	Solution s;
	vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	cout << s.trap(height);
}
