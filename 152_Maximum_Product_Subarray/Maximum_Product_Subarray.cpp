#include "leetcode_solutions.h"

inline int max(int a, int b, int c) {
	return max(max(a, b), c);
}

inline int min(int a, int b, int c) {
	return min(min(a, b), c);
}

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		vector<int> maxProd(nums.size());
		vector<int> minProd(nums.size());
		
		maxProd[0] = minProd[0] = nums[0];
		int res = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			maxProd[i] = max(nums[i], nums[i] * maxProd[i - 1], nums[i] * minProd[i - 1]);
			minProd[i] = min(nums[i], nums[i] * maxProd[i - 1], nums[i] * minProd[i - 1]);
			res = max(res, maxProd[i]);
		}
		return res;
	}
};

int main() {
	Solution s;
	vector<int> nums = {0,2};
	cout << s.maxProduct(nums) << endl;
}