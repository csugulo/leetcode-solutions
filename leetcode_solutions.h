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
#define ETN -2147483648

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

inline ostream & operator<<(ostream & os, const TreeNode & root){
    // TODO implement print Tree
    return os;
}
#endif //LEETCODE_SOLUTIONS_LEETCODE_SOLUTIONS_H
