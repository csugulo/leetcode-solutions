#include "leetcode_solutions.h"

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		stack<int> stack1, stack2;
		while (l1) { stack1.push(l1->val); l1 = l1->next; }
		while (l2) { stack2.push(l2->val); l2 = l2->next; }
		int carry = 0;
		ListNode * head = NULL;
		while (!stack1.empty() || !stack2.empty()) {
			int sum = (stack1.empty() ? 0 : stack1.top()) +
				(stack2.empty() ? 0 : stack2.top()) + carry;
			ListNode *pNode = new ListNode(sum % 10);
			carry = sum / 10;
			pNode->next = head;
			head = pNode;
			if(!stack1.empty()) stack1.pop(); 
			if(!stack2.empty()) stack2.pop();
		}

		if (carry == 1) {
			ListNode *pNode = new ListNode(1);
			pNode->next = head;
			head = pNode;
		}
		return head;
	}
};


int main() {
	ListNode * l1 = CreateList({ 7,6,5,4 });
	ListNode * l2 = CreateList({6,6,6});
	Solution s;
	cout << s.addTwoNumbers(l1, l2) << endl;

}

