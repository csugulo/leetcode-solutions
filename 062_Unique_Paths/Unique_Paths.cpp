#include "leetcode_solutions.h"

class Solution {
public:
	typedef unsigned long long ull;
	int uniquePaths(int m, int n) {
		ull res(1);
		if (n > m) {
			for (ull i = n; i <= n + m - 2; ++i) res *= i;
			for (ull i = 2; i <= m - 1; ++i) res /= i;
		}
		else {
			for (ull i = m; i <= n + m - 2; ++i) res *= i;
			for (ull i = 2; i <= n - 1; ++i) res /= i;
		}

		return res;
	}
};

int main() {
	Solution s;
	cout << s.uniquePaths(23,12);
}