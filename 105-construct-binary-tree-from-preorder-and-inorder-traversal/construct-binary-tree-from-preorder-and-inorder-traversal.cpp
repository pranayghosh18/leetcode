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

TreeNode* buildDfs(vector<int>& preorder, vector<int>& inorder, int& preIndex, int beg, int end, unordered_map<int,int>& inorderPosition) {
    if(beg > end) return nullptr;
    if(beg == end){
        TreeNode *node = new TreeNode(preorder[preIndex++]);
        return node;
    }
    int mid = inorderPosition[preorder[preIndex]];
    TreeNode *node = new TreeNode(preorder[preIndex++]);
    node->left = buildDfs(preorder, inorder, preIndex, beg, mid-1, inorderPosition);
    node->right = buildDfs(preorder, inorder, preIndex, mid+1, end, inorderPosition);
    return node;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int,int> inorderPosition;
    for(int i=0; i<inorder.size(); i++) inorderPosition[inorder[i]] = i;
    int preIndex(0);
    return buildDfs(preorder, inorder, preIndex, 0, inorder.size()-1, inorderPosition);
}
};