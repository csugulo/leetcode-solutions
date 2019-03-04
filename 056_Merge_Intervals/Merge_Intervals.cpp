#include "leetcode_solutions.h"

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		sort(intervals.begin(), intervals.end(), 
			[](const Interval & i1, const Interval & i2) {
				return i1.start < i2.start;
			});
		vector<Interval> res;
		for (auto it = intervals.begin(); it != intervals.end(); ++it) {
			if (res.size() == 0) res.push_back(move(*it));
			else {
				if ((*it).start <= res.back().end)
					res.back().end = max((*it).end, res.back().end);
				else
					res.push_back(move(*it));
			}
		}
		return res;
	}
};

int main() {
	Solution s;
	vector<Interval> intervals1 = {Interval(1,3),Interval(2,6), Interval(8,10), Interval(15,18)};
	vector<Interval> intervals2 = { Interval(1,4),Interval(4,5)};
	cout << s.merge(intervals1)  << endl;
	cout << s.merge(intervals2) << endl;
}