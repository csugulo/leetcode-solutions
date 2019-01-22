#include "leetcode_solutions.h"

class Solution{
public:
    ListNode* rotateRight(ListNode * head, int k){
        if(head == NULL) return head;
        ListNode *res(NULL), *pNode(head);
        vector<ListNode *> pNodes;
        size_t listSize = 0;
        while(pNode != NULL){
            ++listSize;
            pNodes.push_back(pNode);
            pNode = pNode->next;
        }
        int nMove = k % pNodes.size();
        if(nMove == 0) return head;
        int idxNewHead = pNodes.size() - nMove;
        res = pNodes[idxNewHead];
        pNodes[idxNewHead - 1]->next = NULL;
        pNodes[pNodes.size() - 1]->next = pNodes[0];
        return res;

    }
};


int main(){
    Solution s;
    ListNode *head =  CreateList({1,2,3,4,5});
    ListNode *res = s.rotateRight(head, 2);
    cout << *res << endl;
    return 0;
}
