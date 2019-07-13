#include "leetcode_solutions.h"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return 1;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return max(leftDepth, rightDepth) + 1;
    }
};

int main(){
    TreeNode * root = CreateTree({3, 9, 20, ETN, ETN, 15, 7});
    Solution s;
    cout << s.maxDepth(root) << endl;
    return 0;
}