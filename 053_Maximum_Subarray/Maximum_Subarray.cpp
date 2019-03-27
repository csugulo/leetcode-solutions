#include "leetcode_solutions.h"

class Solution {
public:

	int maxSubArray(vector<int>& nums) {
		int dp = nums[0];
		int res = dp;
		for (size_t i = 1; i < nums.size(); ++i) {
			dp = nums[i] + (dp > 0 ? dp : 0);
			res = max(dp, res);
		}
		return res;
	}
};

int main() {
	Solution s;
	vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
	cout << s.maxSubArray(nums);
}