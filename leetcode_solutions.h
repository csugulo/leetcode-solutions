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

#endif //LEETCODE_SOLUTIONS_LEETCODE_SOLUTIONS_H
