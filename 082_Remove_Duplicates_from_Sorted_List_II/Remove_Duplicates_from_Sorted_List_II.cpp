#include "leetcode_solutions.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        ListNode *pBefore(NULL), *pCurrent(head), *res(head);
        while(pCurrent != NULL){

            ListNode *p = pCurrent;
            while(p->next != NULL && p->val == p->next->val){
                p = p->next;
            }
            if(p != pCurrent){
                if(pCurrent == res){
                    res = p->next;
                    pBefore = NULL;
                    pCurrent = p->next;
                }else{
                    pBefore->next = p->next;
                    pCurrent = p->next;
                }
            }else{
                pBefore = pCurrent;
                pCurrent = pCurrent->next;
            }

        }

        return res;
    }
};


int main(){
    Solution s;
    ListNode *head =  CreateList({1,1,2,2,4,5,5,5,6,7,7,7});
    ListNode *res = s.deleteDuplicates(head);
    cout << *res << endl;
    return 0;
}
