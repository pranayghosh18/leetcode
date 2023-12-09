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
    
vector<int> result_94;
TreeNode* getPredecessor(TreeNode* root){
    TreeNode* rootCopy = root;
    rootCopy = rootCopy->left;
    while(rootCopy->right && rootCopy->right != root) rootCopy = rootCopy->right;
    cout << rootCopy->val << endl;
    return rootCopy;
}
void morrisInorder(TreeNode* root){
    while(root){
        if(!root->left){
            result_94.push_back(root->val);
            root = root->right;
        }
        else{
            TreeNode* Predecessor = getPredecessor(root);
            cout << "root " << root->val << "  pred " << Predecessor->val << endl;
            if(Predecessor->right == root){
                Predecessor->right = nullptr;
                result_94.push_back(root->val);
                root = root->right;
            }
            else{
                Predecessor->right = root;
                root = root->left;
            }
        }
    }
    
}
vector<int> inorderTraversal(TreeNode* root) {
    morrisInorder(root);
    return result_94;
}
};