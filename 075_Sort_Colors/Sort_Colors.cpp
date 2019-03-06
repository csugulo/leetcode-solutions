#include "leetcode_solutions.h"

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int lastZero(-1), firstTwo(nums.size());
		int p = 0;
		while (p < firstTwo) {
			if (nums[p] == 2) swap(nums[p], nums[--firstTwo]);
			else if (nums[p] == 0) {
				if (p == lastZero + 1) {
					p++; lastZero++;
				}
				else {
					swap(nums[p], nums[++lastZero]);
					p = lastZero + 1;
				}
			}
			else  p++;
		}
		
	}
};

int main() {
	Solution s;
	vector<int> nums = { 2,0,2,1,1,0 };
	s.sortColors(nums);
	cout << nums << endl;
}