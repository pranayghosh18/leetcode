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
    
int util_1038(TreeNode* root, int prev=0) {
    int l(0), r(0);
    if(root->right) r = util_1038(root->right, prev);
    root->val = root->val + prev + r;
    if(root->left) l = util_1038(root->left, root->val);

    return max(l, root->val);
}
void util_1038DFS(TreeNode* root, int& restSum){
    if(!root) return;
    util_1038DFS(root->right, restSum);
    restSum += root->val;
    root->val = restSum;
    util_1038DFS(root->left, restSum);
}
TreeNode* bstToGst(TreeNode* root) {
    int sum(0);
    util_1038DFS(root, sum);
    return root;
}
};