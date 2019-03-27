#include "leetcode_solutions.h"

class Solution {
public:
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
}