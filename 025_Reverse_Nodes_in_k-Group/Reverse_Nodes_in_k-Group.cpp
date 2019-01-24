//
// Created by xieyang on 19-1-23.
//

#include "leetcode_solutions.h"

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return NULL;
        ListNode * res(NULL), * lastEnd(NULL);
        vector<ListNode *> nodes;
        ListNode * pc = head;
        while(pc != NULL){
            size_t seglen;
            for(seglen = 0; seglen < k && pc != NULL; ++seglen){
                nodes.push_back(pc);
                pc = pc->next;
            }
            if(seglen == k){
                if(res == NULL) res = nodes[k - 1];
                ListNode * curr = nodes[k - 1];
                if(lastEnd != NULL) lastEnd->next = curr;
                nodes.pop_back();
                while(!nodes.empty()){
                    nodes[nodes.size() - 1]->next = NULL;
                    curr->next = nodes[nodes.size() - 1];
                    curr = nodes[nodes.size() - 1];
                    nodes.pop_back();
                }
                lastEnd = curr;
            }else{

                if(res == NULL) res = nodes[0];
                else lastEnd ->next = nodes[0];
            }

        }
        return res;
    }
};


int main(){
    ListNode *head = CreateList({1,2,3,4,5,6,7,8});
    Solution s;
    cout << *s.reverseKGroup(head, 9);

}