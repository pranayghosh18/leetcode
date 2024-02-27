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
    
int height(TreeNode* par, int& res){
    if(!par) return 0;
    int l = height(par->left, res);
    int r = height(par->right, res);

    int contribute = 1 + max(l,r);
    int leader = l + r;
    res = max(res, leader);

    return contribute;
}
int diameterOfBinaryTree(TreeNode* root) {
    int res(0);
    int dump = height(root,res);
    return res;
}
};