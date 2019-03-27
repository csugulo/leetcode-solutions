#include "leetcode_solutions.h"

struct Range {
	long long min = numeric_limits<long long>::lowest();
	long long max = numeric_limits<long long>::max();
};

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return check(root, Range());
	}

	bool check(TreeNode* root, Range range) {
		if (!root) return true;
		if (root->val < range.min || root->val > range.max) return false;

		Range leftRange(range), rightRange(range);
		leftRange.max = (long long)root->val - 1;
		rightRange.min = (long long)root->val + 1;

		return check(root->left, leftRange) && check(root->right, rightRange);
	}

};

int main() {
	//TreeNode *root = CreateTree({5,1,4, ETN, ETN, 3,6});
	//TreeNode *root = CreateTree({ 10,5,15,ETN,ETN,6,20});
	TreeNode *root = CreateTree({ 2147483647 });
	cout << root << endl;
	Solution s;
	cout << s.isValidBST(root) << endl;
	return 0;
}