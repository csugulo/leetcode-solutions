#include "leetcode_solutions.h"

//#define USE_STD_PERMUTATION

class Solution {
public:

#ifdef USE_STD_PERMUTATION
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		do {
			res.push_back(nums);
		} while (next_permutation(nums.begin(), nums.end()));
		return res;
}
#else 
	void traverse(vector<int> & nums, int begin, vector<vector<int>> & res) {
		if (begin == nums.size() - 1) {
			res.push_back(nums);
			return;
		}
		for (size_t i = begin; i < nums.size(); ++i) {
			swap(nums[begin], nums[i]);
			traverse(nums, begin + 1, res);
			swap(nums[begin], nums[i]);
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		traverse(nums, 0, res);
		return res;
	}

#endif // USE_STD_PERMUTATION
};

int main() {
	Solution s;
	vector<int> nums = {1,2,3};
	cout << s.permute(nums);
	return 0;
}