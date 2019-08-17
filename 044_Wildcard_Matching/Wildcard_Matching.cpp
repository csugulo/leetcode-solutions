#include "leetcode_solutions.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        // dp[i + 1][j + 1] mean p[:i] match s[:j] 
        vector<vector<bool>> dp(p.size() + 1, vector<bool>(s.size() + 1, false));
        dp[0][0] = true; // "" match ""
        for(int i = 1; i <= p.size(); ++i) {
            if (p[i - 1] == '*') dp[i][0] = true;
            else break;
        }
        for (int i = 1; i <= p.size(); ++i) {
            for (int j = 1; j <= s.size(); ++j) {
                if (p[i - 1] == '*') {
                   dp[i][j] =  dp[i][j - 1] || dp[i - 1][j];
                } else if (p[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j - 1] && p[i - 1] == s[j - 1];
                }
            }
        }
        return dp[p.size()][s.size()];
    }
};

int main(){
    Solution s;
    cout << s.isMatch("a", "a*") << endl;
}