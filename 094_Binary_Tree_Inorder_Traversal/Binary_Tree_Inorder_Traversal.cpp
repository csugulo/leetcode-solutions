#include "leetcode_solutions.h"

class Solution {
public:

	void traversal(TreeNode * root, vector<int> & vals) {
		if (root == NULL) return;
		traversal(root->left, vals);
		vals.push_back(root->val);
		traversal(root->right, vals);
	}

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		traversal(root, res);
		return res;
	}
};


int main() {
	TreeNode  * root = CreateTree({1,2,3,4,5});
	Solution s;
	cout << s.inorderTraversal(root) << endl;
}