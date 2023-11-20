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
    
void dfs_1110(TreeNode*& root, vector<TreeNode*>& res, unordered_set<int> delNodes){
    if(!root) return;
   // cout << "called : " << root->val <<endl;
    dfs_1110(root->left, res, delNodes);
    dfs_1110(root->right, res, delNodes);

    if(delNodes.find(root->val) != delNodes.end()){
        if(root->left && delNodes.find(root->left->val) == delNodes.end()) res.push_back(root->left);
        if(root->right && delNodes.find(root->right->val) == delNodes.end()) res.push_back(root->right);

        root = nullptr;
    }
}
vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    vector<TreeNode*> res;
    unordered_set<int> delNodes = {to_delete.begin(), to_delete.end()};
    dfs_1110(root,res,delNodes);
    if(root) res.push_back(root);
    return res;
}
};