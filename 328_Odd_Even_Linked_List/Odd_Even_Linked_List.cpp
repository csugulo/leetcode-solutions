//
// Created by xieyang on 19-1-24.
//
#include "leetcode_solutions.h"

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode emptyOdd(0), emptyEven(0), * oddLast = &emptyOdd, * evenLast = &emptyEven, *p(head);
        while(true){
            if(p != NULL){
                oddLast->next = p;
                p = p->next;
                oddLast = oddLast ->next;
                oddLast->next = NULL;
            }else{
                break;
            }

            if(p != NULL){
                evenLast->next = p;
                p = p->next;
                evenLast = evenLast ->next;
                evenLast ->next = NULL;
            }else{
                break;
            }
        }

        oddLast -> next = emptyEven.next;
        return emptyOdd.next;
    }
};

int main(){
    ListNode * head = CreateList({1,2});
    Solution s;
    cout << *s.oddEvenList(head);
    return 0;
}