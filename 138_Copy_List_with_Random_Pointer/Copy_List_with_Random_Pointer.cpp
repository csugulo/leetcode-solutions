#include "leetcode_solutions.h"

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == NULL) return NULL;
		RandomListNode * randomListNode = new RandomListNode(head->label);
		if (head->next != NULL) randomListNode->next = copyRandomList(head->next);
		if (head->random != NULL) randomListNode->random = copyRandomList(head->random);
		return randomListNode;
	}
};