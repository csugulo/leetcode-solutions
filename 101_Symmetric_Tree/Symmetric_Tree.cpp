#include "leetcode_solutions.h"

class Solution {
public:

    bool mirrorNode(TreeNode * p, TreeNode * q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;
        return mirrorNode(p->left, q->right) && mirrorNode(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return mirrorNode(root->left, root->right);
    }
};

int main(){
    Solution s;
    TreeNode* root = CreateTree({1,2,3,3,ETN,2});
    cout << s.isSymmetric(root) << endl;
}