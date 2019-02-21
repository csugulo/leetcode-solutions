#include "leetcode_solutions.h"

class Solution {
public:

	TreeNode* createTreeFromVector(const vector<int> & vec, int begin, int end) {
		if (begin < end) {
			TreeNode *root = new TreeNode(vec[(begin + end) / 2]);
			root->left = createTreeFromVector(vec, begin, (begin + end) / 2);
			root->right = createTreeFromVector(vec, (begin + end) / 2 + 1, end);
			return root;
		}else return NULL;
	}

	TreeNode* sortedListToBST(ListNode* head) {
		if (head == NULL) return NULL;
		vector<int> vec;
		while (head) {
			vec.push_back(head->val);
			head = head->next;
		}
		return createTreeFromVector(vec, 0, vec.size());
	}

};


int main() {
	ListNode *head = CreateList({ 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 });
	Solution s;
	TreeNode *root = s.sortedListToBST(head);
	cout << *root;
	
}