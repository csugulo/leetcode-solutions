//
// Created by xieyang on 19-1-23.
//

#include "leetcode_solutions.h"

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL) return head;
        int start = m - 1, end = n - 1;
        ListNode *pPre(head);
        if(start == 0) pPre = NULL;
        else for(auto i = 1; i < start ; ++i) pPre = pPre->next;

        vector<ListNode *> nodes;
        ListNode *pLast = pPre == NULL ? head : pPre->next;
        for(auto i = 0; i < end -start + 1; ++i){
            nodes.push_back(pLast);
            pLast = pLast->next;
        }

        if(pPre == NULL){
            for(size_t i = nodes.size() - 1; i > 0; --i){
                nodes[i]->next = nodes[i - 1];
            }
            nodes[0]->next = pLast;
            return nodes[nodes.size() - 1];
        }else{
            ListNode *curr = pPre;
            for(auto rit = nodes.rbegin(); rit != nodes.rend(); ++rit){
                (*rit)->next = NULL;
                curr->next = *rit;
                curr = *rit;
            }
            curr->next = pLast;
            return head;
        }



    }
};


int main(){
    Solution s;
    ListNode *head = CreateList({1,2,3,4,5});
    cout << *s.reverseBetween(head,2,4);
}