/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> clones;
        if(node == nullptr) return nullptr;
        clones[node] = new Node(node->val);

        queue<Node*> bfs;
        bfs.push(node);
        while (!bfs.empty())
        {
            Node *top = bfs.front();
            Node *top_copy = clones[top];
            bfs.pop();

            for(Node *u : top->neighbors) {
                // if(u != nullptr) {
                // unvisted child
                if(clones.find(u) == clones.end()) {
                    clones[u] = new Node(u->val);
                    bfs.push(u);
                }
                top_copy->neighbors.push_back(clones[u]);
                // }
            }
        }
        return clones[node];
    }
};