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
 
pair<int,int> minMaxFromChildren(TreeNode *root, bool& validityFlag){
    if(!root) return {-1e9, 1e9};
    if(root->left == nullptr && root->right == nullptr) return {root->val, root->val};

    int minLeft(root->val), maxRight(root->val);
    if(root->left){
        pair<int,int> lefts = minMaxFromChildren(root->left, validityFlag);
        if(root->val <= lefts.second) validityFlag = false;
        minLeft = min(lefts.first, minLeft);
    }

    if(root->right){
        pair<int,int> rights = minMaxFromChildren(root->right, validityFlag);
        if(root->val >= rights.first) validityFlag = false;
        maxRight = max(maxRight, rights.second);
    }
    
    return {minLeft, maxRight};
}

bool isValidBST(TreeNode* root) {
    if(!root) return true;
    bool validityFlag = true;
    pair<int,int> _ = minMaxFromChildren(root, validityFlag);
    return validityFlag;     
}

};