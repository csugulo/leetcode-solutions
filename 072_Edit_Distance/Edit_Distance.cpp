#include "leetcode_solutions.h"

class Solution {
public:
	int minDistance(string word1, string word2) {
		if (word1.size() == 0) return word2.size();
		if (word2.size() == 0) return word1.size();
		int rows(word1.size()), cols(word2.size());
		vector<vector<int>> dp(rows, vector<int>(cols));
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (i == 0 && j == 0) 
					dp[i][j] = word1[i] == word2[j] ? 0 : 1;
				else if (i == 0 && j != 0) 
					dp[i][j] = word1[i] == word2[j] ?
					max(dp[i][j - 1], j) : dp[i][j - 1] + 1;
				else if (i != 0 && j == 0) 
					dp[i][j] = word1[i] == word2[j] ?
					max(dp[i - 1][j], i) : dp[i - 1][j] + 1;
				else 
					dp[i][j] = word1[i] == word2[j] ?
					dp[i - 1][j - 1] :
					min(min(dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j]) + 1;
					
			}
		}
		return dp[rows - 1][cols - 1];
	}
};

int main() {
	Solution s;
	cout << s.minDistance("pneumonoultramicroscopicsilicovolcanoconiosis", "ultramicroscopically");
}