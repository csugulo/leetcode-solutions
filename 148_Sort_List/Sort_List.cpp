#include "leetcode_solutions.h"

class Solution {
public:
<<<<<<< HEAD
	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		return sort(head, NULL);

	}

	ListNode * sort(ListNode* begin, ListNode* end) {
		ListNode *left(begin), *right(begin), *mid(begin);
		if (begin->next == end) return begin;
		ListNode *curr = begin->next;
		begin->next = NULL;

		while (curr != end) {
			ListNode *next = curr->next;
			curr->next = NULL;
			if (curr->val < mid->val) {
				curr->next = left;
				left = curr;
			}
			else {
				right->next = curr;
				right = curr;
			}
			curr = next;
		}
		right->next = end;
		ListNode *leftHead = sort(left, mid);
		ListNode *rightHead = sort(mid->next, right->next);
		return left;
	}

};

int main() {
	Solution s;
	ListNode * head = CreateList({ 5,1,9,2 });
	head = s.sortList(head);
	cout << head;
	return 0;
=======
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
>>>>>>> 8ef7bed87b36d65d17c54b68e707c57773567bca
}