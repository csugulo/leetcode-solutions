#include "leetcode_solutions.h"

class Solution {
public:

	void traverse(vector<int> & candidates, vector<vector<int>> & res,
		int candiStart, vector<int> & nums, int target) {
		if(target == 0 && nums.size() != 0) res.push_back(nums);
		else {
			for (int i = candiStart; i < candidates.size() && candidates[i] <= target; ++i) {
				nums.push_back(candidates[i]);
				traverse(candidates, res, i, nums, target - candidates[i]);
				nums.pop_back();
			}
		}

	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		vector<int> nums;
		sort(candidates.begin(), candidates.end());
		traverse(candidates, res, 0, nums, target);
		return res;
	}
};

int main() {
	Solution s;
	vector<int> candidates = {2,3,6,7};
	vector<vector<int>> res = s.combinationSum(candidates, 7);
	for_each(res.begin(), res.end(), [](vector<int> v) {
		for (auto it = v.begin(); it != v.end(); ++it) {
			cout << *it << '\t';
		}
		cout << endl;
	});
}