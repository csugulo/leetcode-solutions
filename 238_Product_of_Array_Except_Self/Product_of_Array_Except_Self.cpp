#include "leetcode_solutions.h"

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int zeroCount = 0;
		long long product = 1;
		for (auto i = 0; i < nums.size(); ++i) {
			if (nums[i] == 0) {
				zeroCount++;
				if (zeroCount == 2) return vector<int>(nums.size(), 0);
			}
			else product *= nums[i];
		}

		vector<int> res(nums.size(), 0);
		if (zeroCount == 1) {
			for (auto i = 0; i < res.size(); ++i) {
				if (nums[i] == 0) {
					res[i] = product;
					break;
				}
			}
		}
		else {
			for (auto i = 0; i < res.size(); ++i) {
				res[i] = product / nums[i];
			}
		}
		return res;
	}
};

int main() {
	Solution s;
	vector<int> nums = { 1,2,3,4 };
	cout << s.productExceptSelf(nums) << endl;
}