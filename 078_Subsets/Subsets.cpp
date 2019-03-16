#include "leetcode_solutions.h"

class Solution {

	typedef unsigned long long ull;
	typedef unsigned int ui;

public:

	vector<vector<int>> subsets(vector<int>& nums) {
		ull n = 1 << nums.size();
		vector<vector<int>> res;
		for (ull i = 0; i < n; ++i) {
			vector<int> subset;
			for (ui iDigit = 0; iDigit < nums.size(); ++iDigit) {
				ull mask = 1 << iDigit;
				if (!(mask & i)) 
					subset.push_back(nums[iDigit]);
			}
			res.push_back(subset);
		}
		return res;
	}
};

int main() {

	Solution s;
	vector<int> nums = {  };
	vector<vector<int>> res = s.subsets(nums);
	cout << res << endl;

}