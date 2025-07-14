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
    void reverse(std::bitset<32> &b) {
        for(std::size_t i = 0; i < 16; ++i) {
            bool t = b[i];
            b[i] = b[31-i];
            b[31-i] = t;
            }
    }
    int getDecimalValue(ListNode* h) {
        //bitset<32> b;
        //int idx(0);
        //string s;
        int res(0);
        while(h) {
            //b[idx] = h->val;
            //s.push_back(h->val+'0');
            res = res*2 + h->val;
            h=h->next;
            //idx++;
        }
        //reverse(b);
        //int r = b.to_llong();
        //std::reverse(s.begin(),s.end());
        //int r(0);
        //for()
        return res;
    }
};