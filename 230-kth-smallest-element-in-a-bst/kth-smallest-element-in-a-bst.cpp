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
void kthSmallestDFS(TreeNode* root, int& k, int& ans) {
    if(ans != -1) return;
    if(!root) return;
    kthSmallestDFS(root->left, k, ans);
    // inorder work
    k--;
    if(k == 0) ans = root->val;
    kthSmallestDFS(root->right, k, ans);
}
int kthSmallest(TreeNode* root, int k) {
    int ans = -1;
    kthSmallestDFS(root, k, ans);
    return ans;
}
};