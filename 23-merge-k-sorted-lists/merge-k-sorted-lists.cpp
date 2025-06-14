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

struct CompareKLists {
    bool operator()(const pair<int, ListNode*>& a, const pair<int, ListNode*>& b) const {
        return a.first > b.first; // as its minHeap
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, CompareKLists> minHeap;
    for(auto t: lists){
        if(t) minHeap.push({t->val, t});
    }  
    ListNode *head(nullptr), *ptr;
    while (!minHeap.empty())
    {
        auto tp = minHeap.top();
        ListNode* smallest = tp.second;
        minHeap.pop();
        if(smallest->next) minHeap.push({smallest->next->val, smallest->next});
        if(!head) {
            head = smallest;
            ptr = head;
        }
        else{
            ptr->next = smallest;
            ptr = smallest;
        }
    }
    return head;
    return head;
}
};