//
// Created by xieyang on 19-1-23.
//

#include "leetcode_solutions.h"
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        vector<ListNode *> nodes;
        ListNode *curr(head);
        while(curr){
            if(nodes.size() == 0 || curr->val != nodes.back()->val) nodes.push_back(curr);
            curr = curr->next;
        }
        ListNode *res = nodes[0];
        res->next = NULL;
        curr = res;
        for(auto it = ++nodes.begin(); it != nodes.end(); ++it){
            (*it)->next = NULL;
            curr->next = *it;
            curr = curr->next;
        }
        return res;
    }
};

int main(){
    Solution s;
    ListNode *head = CreateList({1,1,2,2,3,3});
    cout << *s.deleteDuplicates(head);
}