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

int getChildSum(TreeNode *root, int& maxGather){
    if(!root) return 0;
    int leftSum = max(0, getChildSum(root->left, maxGather));
    int rightSum = max(0, getChildSum(root->right, maxGather));

    int leader = root->val + rightSum + leftSum;
    maxGather = max(maxGather, leader);
    int contributor = max(leftSum, rightSum) + root->val;

    return contributor;
}

int maxPathSum(TreeNode* root) {
    int maxGather = -1e9;
    int _ = getChildSum(root, maxGather);
    return maxGather;
}
};