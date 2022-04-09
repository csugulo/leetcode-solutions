#include "leetcode_solutions.h"

class Solution {
public:
	string minWindow(string s, string t) {
		vector<int> map(128, 0);
		for (auto c : t) map[c]++;
		int counter = t.size(), begin = 0, end = 0, d = numeric_limits<int>::max(), head = 0;
		while (end < s.size()) {
			if (map[s[end++]]-- > 0) counter--; //in t
			while (counter == 0) { //valid
				if (end - begin < d)  d = end - (head = begin);
				if (map[s[begin++]]++ == 0) counter++;  //make it invalid
			}
		}
		return d == numeric_limits<int>::max() ? "" : s.substr(head, d);
	}
};


int main(){
	Solution s;
	cout << s.minWindow("ADOBECODEBANC","ABC");
}