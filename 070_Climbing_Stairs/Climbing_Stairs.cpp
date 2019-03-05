#include "leetcode_solutions.h"
class Solution {
public:
	int climbStairs(int n) {
		vector<int> dp(n);
		for (int i = 0; i < n; ++i) {
			if (i == 0 || i == 1) dp[i] = i + 1;
			else dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n - 1];
	}
};

int main() {
	Solution s;
	cout << s.climbStairs(26);
}