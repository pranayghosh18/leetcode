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
 TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    unordered_map<int, TreeNode*> hm;
    unordered_map<int, bool> roots;
    for(auto d:descriptions){
        int parent = d[0];
        int child = d[1];
        int isLeft = d[2];

        TreeNode *parentNode, *childNode;
        if(hm.find(parent) != hm.end()) parentNode = hm[parent];
        else{
            parentNode = new TreeNode(parent);
            hm[parent] = parentNode;
        }
        
        if(hm.find(child) != hm.end()) childNode = hm[child];
        else{
            childNode = new TreeNode(child);
            hm[child] = childNode;
        }

        if(isLeft) parentNode->left = childNode;
        else parentNode->right = childNode;

        if(roots.find(parent) == roots.end()) roots[parent] = true;
        roots[child] = false;
    }

    for(auto r : roots) if(r.second == true) return hm[r.first];
    return nullptr;
}
};