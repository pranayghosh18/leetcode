/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
int coinsReq(TreeNode *root, int& move){
    if(!root) return 0;
    int leftReq = coinsReq(root->left, move);
    int rightReq = coinsReq(root->right, move);
    move += abs(leftReq) + abs(rightReq);
    return root->val + leftReq + rightReq - 1;
}
int distributeCoins(TreeNode* root) {
    int move(0);
    coinsReq(root, move);
    return move;
}
};