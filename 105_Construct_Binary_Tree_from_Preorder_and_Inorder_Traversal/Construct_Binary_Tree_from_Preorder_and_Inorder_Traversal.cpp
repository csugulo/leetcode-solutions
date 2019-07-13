#include "leetcode_solutions.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return nullptr;
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode * build(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
        if (ps == pe) {
            TreeNode * root = new TreeNode(preorder[ps]);
            return root;
        }
        // find preorder[ps] in inorder
        int rootInIdx;
        for (int i = is; i <= ie; ++i){
            if(inorder[i] == preorder[ps]){
                rootInIdx = i;
                break;
            }
        }
        TreeNode * root = new TreeNode(preorder[ps]);
        TreeNode *left(nullptr), *right(nullptr);
        if (rootInIdx != is){   // left tree exist
            left = build(preorder, inorder, ps + 1, ps + (rootInIdx - is), is, rootInIdx - 1);
        }
        if (rootInIdx != ie){   // right tree exist
            right = build(preorder, inorder, ps + (rootInIdx - is) + 1, pe, rootInIdx + 1, ie);
        }
        root -> left = left;
        root -> right = right;
        return root;
    }
};

int main(){
    vector<int> preorder = {1,2};
    vector<int> inorder = {2,1};
    Solution s;
    cout << s.buildTree(preorder, inorder) << endl;
}