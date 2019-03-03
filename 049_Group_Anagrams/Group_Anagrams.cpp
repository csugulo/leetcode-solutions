#include "leetcode_solutions.h"

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		map<string, vector<string>> map;
		for (auto it = strs.begin(); it != strs.end(); ++it) {
			string str = *it;
			sort(str.begin(), str.end());
			map[str].push_back(std::move(*it));
		}

		for (auto it = map.begin(); it != map.end(); ++it)
			res.push_back(std::move((*it).second));

		return res;
	}
};

int main() {
	Solution s;
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	cout << s.groupAnagrams(strs) << endl;
}