#include "leetcode_solutions.h"

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<TreeNode *> layer = {root};
        while(layer.size()){
            vector<int> layerVals;
            vector<TreeNode *> nextLayer;
            for(TreeNode * node : layer){
                layerVals.push_back(node ->val);
                if(node->left) nextLayer.push_back(node->left);
                if(node->right) nextLayer.push_back(node->right);
            }
            res.push_back(move(layerVals));
            layer = move(nextLayer);
        }
        return res;
    }
};

int main(){
    Solution s;
    TreeNode *root = CreateTree({3,9,20,ETN, ETN,15,7});
    cout << s.levelOrder(root) << endl;
}