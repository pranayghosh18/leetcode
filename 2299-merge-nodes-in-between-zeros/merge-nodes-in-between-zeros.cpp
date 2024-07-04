/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
ListNode* mergeNodes(ListNode* head) {
    ListNode *cur, *nex;
    cur = head;
    while (cur->next)
    {
        nex = cur->next;
        while (nex->val != 0)
        {
            cur->val += nex->val;
            nex = nex->next;
        }
        if(nex->next) cur->next = nex;
        else cur->next = nullptr;
        cur = nex;
    }
    return head;
}
};