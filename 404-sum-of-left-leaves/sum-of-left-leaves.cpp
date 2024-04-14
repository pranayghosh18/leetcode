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
    int f(TreeNode* root, bool isleft){
        if(!root) return 0;
        //leaf
        if(!root->left && !root->right) return isleft ? root->val : 0;
        
        return f(root->left, true) + f(root->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return f(root,false);
    }
    /*
    int sumOfLeftLeaves(TreeNode* root, bool isleft = false) {
        if (!root) return 0;
        if (!root->left && !root->right) return isleft ? root->val : 0;
        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
    }
    */
};