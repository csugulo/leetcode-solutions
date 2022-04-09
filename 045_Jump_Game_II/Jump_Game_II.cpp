#include "leetcode_solutions.h"

using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int n_jump = 0;
        int curr = nums.size() - 1;
        while (curr != 0)
        {
           for (int idx = 0; idx < curr; idx++) {
               if (nums[idx] + idx >= curr) {
                   n_jump ++;
                   curr = idx;
                   break;
               }
           }
        }
        return n_jump;
    }
};

int main() {
	Solution s;
	vector<int> nums = {1,2,1,1,1,4,4,1,5,2,3,4,1,4,2,5,2,6,4,4,2,2,5,6,2,3,4,5,4,4,2,3,1,4,1,6,2,3,5,3,6,6,1,2,5,3,3,4,6,1,1,5,3,3,4,5,1,4,2,6,6,4,1,4,1,2,1,4,4,2,1,2,2,5,6,5,4,4,3,6,5,2,5,6,1,4,3,4,3,3,1,2,6,5,3,6,1,2,6,4,2,3,3,4,6,3,5,3,2,3,3,1,3,2,4,1,3,5,1,1,5,2,4,2,2,5,3,4,2,1,3,3,1,2,4,5,4,6,2,5,6,4,6,5,2,2,1,4,6,4,2,4,1,6,3,3,6,1,4,5,4,5,1,2,3,6,1,4,3,2,5,1,5,2,5,1,2,3,3,6,6,3,5,2,6,1,6,4,3,4,1,2,5,1,5,6,5,3,1,5,6,3,6,3,5,6,2,2,6,3,4,1,4,1,1,3,4,1,5,6,5,4,2,5,3,6,4,1,2,3,5,6,5,2,3,6,1,3,4,6,3,2,5,5,1,6,6,6,2,3,5,5,4,5,2,1,6,6,2,5,1,3,2,5,1,2,3,4,1,1,5,1,4,1,2,2,6,1,4,3,2,1,6,5,1,6,2,3,5,3,6,6,5,2,1,4,4,5,3,5,5,1,3,2,6,1,6,6,4,6,5,3,3,1,6,2,6,4,2,4,1,2,2,2,2,1,5,4,3,6,3,2,5,5,4,6,4,1,5,2,4,6,2,4,5,5,3,4,6,6,1,6,6,5,3,1,4,6,5,3,5,3,5,2,3,4,6,2,5,6,6,2,5,6,1,1,5,4,5,6,6,5,5,3,3,4,4,5,2,6,5,1,3,2,3,1,3,1,2,3,5,2,5,3,2,2,3,4,4,2,6,5,1,3,4,6,1,6,4,4,2,4,5,2,5,6,6,1,3,1,1,4,6,5,6,4,1,3,1,1,6,2,6,4,5,5,3,5,3,6,6,2,1,3,2,5,5,3,5,3,3,5,3,2,1,2,2,6,1,6,4,2,2,2,6,2,4,2,5,5,2,3,1,1,5,6,6,3,4,6,2,1,2,1,4,2,5,6,5,5,3,2,1,5,1,3,2,2,5,1,6,1,6,5,6,2,6,3,6,5,1,4,6,3,3,6,6,4,1,4,6,3,4,1,4,2,5,5,5,4,2,5,6,6,3,1,5,4,2,3,6,1,6,4,1,5,5,6,4,5,4,4,6,5,2,5,1,4,3,2,6,1,5,2,6,2,6,1,2,3,5,5,4,4,5,4,2,1,4,1,4,6,1,1,2,6,2,3,6,4,4,5,6,6,4,1,6,3,2,4,1,4,5,5,2,6,6,4,2,5,4,6,6,5,2,4,1,1,4,1,1,4,6,1,5,2,4,6,5,1,6,6,6,2,1,6,1,5,5,4,5,2,3,2,2,2,6,4,6,2,4,6,4,5,1,3,2,4,2,6,6,4,3,3,1,1,4,4,5,5,4,1,6,5,1,3,3,6,5,5,3,6,3,5,2,4,3,4,6,5,2,6,6,1,2,3,4,6,1,5,6,4,6,6,1,1,2,4,6,4,1,1,6,6,2,1,1,2,3,6,5,3,1,6,1,3,6,2,4,5,3,2,5,3,5,5,2,1,3,4,4,6,2,4,3,3,1,5,3,3,1,2,5,2,5,2,2,4,2,2,4,6,3,1,4,2,3,4,2,2,6,3,2,6,3,3,5,5,5,2,3,1,6,5,4,5,2,6,5,2,1,2,2,2,2,2,3,2,6,3,1,5,6,1,4,6,5,3,3,5,5,6,5,1,4,3,5,5,3,4,6,4,6,3,2,1,1,6,2,2,5,5,3,1,3,5,6,3,6,2,5,6,2,1,4,4,2,2,6,2,1,5,6,1,1,3,3,5,5,3,2,5,2,1,3,2,4,3,5,2,5,5,4,1,1,3,4,3,1,3,5,5,4,5,5,1,3,5,4,6,5,4,2,1,2,6,6,4,4,5,6,6,6,3,4,3,5,2,5,6,5,2,1,4,5,3,1,6,4,1,5,4,5,2,5,1,4,2,6,3,3,5,1,3,4,3,3,6,6,5,5,5,4,5,3,6,6,6,4,2,4,4,1,2,2,2,3,2,2,5,6,5,6,3,3,1,1,4,1,6,6,5,3,2,6,5,2,1,6,1,4,6,4,1,2,1,2,5,1,1,6,3,2,5,4,5,2,6,5,6,2,2,1,5,5,1,6,2,1,3,4,5,4,3,1,5,6,5,4,1,2,3,4,2,2,6,2,4,3,2,5,3,2,2,5,6,3,3,2,1,4,5,2,3,2,5,3,1,3,6,3,6,4,2,5,3,6,1,6,5,2,1,5,2,1,1,4,3,3,1,1,2,2,1,1,4,1,6,5,5,6,4,6,6,2,2,2,6,1,1,1,1,5,2,2,1,6,5,6,1,3,1,6,4,1,2,1,5,1,1,3,6,4,5,4,2,3,4,1,5,2,2,1,6,2,3,2,3,3,1,1,4,5,5,3,5,3,6,4,5,4,4,4,2,2,1,4,6,0,0,0,0,0};
	cout << s.jump(nums) << endl;
	//  nums = {2,3,1,1,4};
	// cout << s.jump(nums)<< endl;
	//  nums = {2,3,0,1,4};
	// cout << s.jump(nums)<< endl;
	return 0;
}