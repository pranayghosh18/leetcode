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
    
ListNode* rev(ListNode* head){
    ListNode *c, *p, *n;
    p = nullptr;
    c = head;

    while(c){
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    head = p;

    return head;
}

ListNode* removeLeftGreater(ListNode* head) {
    int left(0);
    ListNode *c, *p;
    c = head;
    while(c){
        if(left > c->val) {
            p->next = c->next;
        }
        else{
            p = c;
            left = max(left,c->val);
        }
        c = c->next;
    }
    return head;
}

ListNode* removeNodes(ListNode* head) {
    head = rev(head);
    head = removeLeftGreater(head);
    head = rev(head);

    return head;
}
};