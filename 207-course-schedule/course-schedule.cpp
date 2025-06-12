class Solution {
public:

bool findCycle(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& revisited){
    visited[node] = true;
    revisited[node] = true;

    for(auto u : adj[node]){
        if(revisited[u]) return true;
        if(!visited[u]){
            if(findCycle(u, adj, visited, revisited)) return true;
        }
    }
    revisited[node] = false;
    return false;
}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // creatre graph, directed 
    vector<vector<int>> adj(numCourses);
    for(auto vu : prerequisites){
        int v = vu[0];
        int u = vu[1];
        adj[u].push_back(v);
    }
    vector<bool> visited(numCourses, false), revisited(numCourses, false);
    for(int i=0; i<numCourses; i++) {
        if(!visited[i] && findCycle(i, adj, visited, revisited)) return false;
    }
    return true;
}
};