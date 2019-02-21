//
// Created by xieyang on 19-1-22.
//

#ifndef LEETCODE_SOLUTIONS_LEETCODE_SOLUTIONS_H
#define LEETCODE_SOLUTIONS_LEETCODE_SOLUTIONS_H

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <deque>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

inline ostream & operator<<(ostream & os, const ListNode & head){
    const ListNode * pNode = &head;
    os << '[';
    while(pNode != NULL){
        os << pNode->val;
        if(pNode->next  != NULL) os << ',';
        pNode = pNode->next;
    }
    os << ']';
    return os;
}

inline ListNode * CreateList(initializer_list<int> list){
    ListNode *pHead(NULL), *pLast(NULL);
    for(auto it = list.begin(); it != list.end(); ++it){
        ListNode *pNode = new ListNode(*it);
        if(it == list.begin()){
            pHead = pNode;
            pLast = pHead;
        }else{
            pLast->next = pNode;
            pLast = pNode;
        }
    }
    return pHead;
}


struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

// empty tree node
#define ETN int(-2147483648)

inline TreeNode * CreateTree(initializer_list<int> list){
    if(list.size() == 0) return NULL;
    vector<int> vals(list);
    vector<TreeNode *> nodes;
    nodes.resize(list.size());
    for(size_t i = 0; i < vals.size(); ++i){
        if(vals[i] != ETN){
            TreeNode * node = new TreeNode(vals[i]);
            nodes[i] = node;
            if(i != 0){
                int idxParent = (i - 1) / 2;
                if((i % 2) != 0) nodes[idxParent]->left = node;
                else nodes[idxParent] -> right = node;
            }
        }
    }
    return nodes[0];
}

inline int maxDepthOfTree(const TreeNode & root) {
	if (&root == NULL) return 0;
	else {
		int lDepth = maxDepthOfTree(*root.left);
		int rDepth = maxDepthOfTree(*root.right);
		return lDepth > rDepth ? lDepth + 1 : rDepth + 1;
	}
}

inline ostream & operator<<(ostream & os, const TreeNode & root){
	int depth = maxDepthOfTree(root);
	if (depth == 0) return os;
	vector<const TreeNode *> treeVec;
	treeVec.resize(pow(2,depth) - 1);
	treeVec[0] = &root;
	for (size_t i = 0; i < depth - 1; ++i) {
		for (size_t j = pow(2, i) - 1; j < pow(2, i + 1) - 1; ++j) {
			if (treeVec[j] != NULL) {
				treeVec[2 * j + 1] = treeVec[j]->left;
				treeVec[2 * j + 2] = treeVec[j]->right;
			}
		}
	}

	for (size_t i = 0; i < depth; ++i) {
		for (size_t j = pow(2, i) - 1; j < pow(2, i + 1) - 1; ++j) {
			if (treeVec[j] != NULL) os << treeVec[j]->val << '\t';
			else os << "null\t";
		}
		os << endl;
	}
	
    return os;
}

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
#endif //LEETCODE_SOLUTIONS_LEETCODE_SOLUTIONS_H
