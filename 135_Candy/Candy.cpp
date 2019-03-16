#include "leetcode_solutions.h"

class Solution {
public:
	int candy(vector<int>& ratings) {
		if (ratings.size() == 0) return 0;
		vector<int> candies(ratings.size(), 1);
		for (int i = 1; i < ratings.size(); ++i)
			candies[i] = ratings[i] > ratings[i - 1] ? candies[i - 1] + 1 : 1;
		
		int res = candies[ratings.size() - 1];
		for (int i = ratings.size() - 2; i >= 0; --i) {
			if(ratings[i] > ratings[i + 1])
				candies[i] =  max(candies[i + 1] + 1, candies[i]);
			res += candies[i];
		}
		return res;
	}
};


int main() {
	Solution s;
	vector<int> ratings = {1,0,2};
	cout << s.candy(ratings);
}