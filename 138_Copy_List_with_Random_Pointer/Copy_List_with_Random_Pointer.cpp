#include "leetcode_solutions.h"

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == NULL) return NULL;
		map<RandomListNode *, RandomListNode *> copyMap;
		map<RandomListNode *, RandomListNode *> randomMap;
		RandomListNode *p = head;
		RandomListNode *res = new RandomListNode(0) , *last(res);
		while (p) {
			RandomListNode *pNode = new RandomListNode(p->label);
			copyMap[p] = pNode;
			if (p->random) randomMap[p] = p->random;
			last->next = pNode;
			last = pNode;
			p = p->next;
		}

		p = head;
		while (p) {
			if (p->random) copyMap[p]->random = copyMap[randomMap[p]];
			p = p->next;
		}

		return res->next;
	}
};

int main() {
	RandomListNode n0(0), n1(1), n2(2), n3(3);
	n0.next = &n1; n1.next = &n2; n2.next = &n3;
	n0.random = &n1; n2.random = &n3;
	Solution s;
	RandomListNode * copy = s.copyRandomList(&n0);
	cout << copy << endl;
	cout << 1;
}