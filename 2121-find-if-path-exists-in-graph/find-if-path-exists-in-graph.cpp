class Solution {
public:
    
bool dfs_1971(vector<vector<int>>& adj, vector<bool>& vis, int src, int dest){
    // cout << "src: " << src << "  dest : " << dest << endl;
    if(src == dest) return true;
    if(vis[src]) return false;
    vis[src] = true;
    for(int v : adj[src]) if(dfs_1971(adj, vis, v, dest)) return true;
    return false;
}
bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    vector<vector<int>> grph(n);
    vector<bool> vis(n, false);
    for(auto e : edges) grph[e[0]].push_back(e[1]), grph[e[1]].push_back(e[0]);

    return dfs_1971(grph, vis, source, destination);
}
};