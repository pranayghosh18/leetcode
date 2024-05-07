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
    ListNode* doubleItUp(ListNode* head){
    ListNode *t, *p;
    int s(0), c(0);
    t = head;
    while (t)
    {
        s = t->val * 2 + c;
        t->val = s%10;
        c = s/10;
        
        p = t;
        t=t->next;
    }
    if(c>0){
        p->next = new ListNode(c);
    }
    return head;
}
ListNode* doubleIt(ListNode* head) {
    head = rev(head);
    head = doubleItUp(head);
    head = rev(head);
    return head;
}
};