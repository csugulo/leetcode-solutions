#include "leetcode_solutions.h"

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        sort(dummy, NULL);
        return dummy->next;

    }

    void sort(ListNode* pre, ListNode* end){
        if(pre->next == end || pre->next->next == end) return;
        ListNode *mid(pre->next), *left(pre->next), *right(pre->next);
        ListNode *curr(pre->next->next);

        while(curr != end){
            ListNode *next = curr->next;
            if(curr->val < mid->val){
                curr->next = left;
                left = curr;
            }else{
                right->next = curr;
                right = curr;
            }
            curr = next;
        }
        pre->next = left;
        right->next = end;
        
        sort(pre, mid);
        sort(mid, end);
    }

};

int main(){
    Solution s;
    ListNode * head = CreateList({9,8,7,6,5,4});
    head =  s.sortList(head);
    cout << head;
    return 0;
}
