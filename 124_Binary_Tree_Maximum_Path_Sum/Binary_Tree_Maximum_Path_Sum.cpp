#include "leetcode_solutions.h"

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int global_max = numeric_limits<int>::lowest();
        maxToRoot(root, &global_max);
        return global_max;
    }
private:
    int maxToRoot(TreeNode* node, int* global_max) {
        if (node == nullptr) return 0;
        int left = max(0, maxToRoot(node->left, global_max));
        int right = max(0, maxToRoot(node->right, global_max));
        if (left + right + node->val > *global_max) 
            *global_max = left + right + node->val;
        return max(left + node->val, right + node->val);
    }
};

int main(){

}