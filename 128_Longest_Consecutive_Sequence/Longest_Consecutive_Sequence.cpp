#include "leetcode_solutions.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return nums.size();
        int res = 0;
        unordered_set<int> set(nums.begin(), nums.end());
        for(int val : nums){
            if(!set.count(val)) continue;
            set.erase(val);
            int pre(val - 1), after(val + 1);
            while(set.count(pre)) set.erase(pre--);
            while(set.count(after)) set.erase(after++);
            res = max(res, after - pre - 1);
        }
        return res;
    }
};

int main(){
    vector<int> nums = {100,4,200,1,3,2};
    Solution s;
    cout << s.longestConsecutive(nums) << endl;
    return 0;
}