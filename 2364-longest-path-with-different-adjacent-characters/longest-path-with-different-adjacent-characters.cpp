class Solution {
public:

// contributor, child's CHAR
pair<int, char> dfs2246(int par, string& s, vector<vector<int>>& graph, int& ans){
    // if leaf 
    if(graph[par].size() == 0) return {1, s[par]};

    int maxLen(0), secondMaxLen(0);
    for(auto child : graph[par]){
        auto childRes = dfs2246(child, s, graph, ans);
        int len = childRes.first;
        char childChar = childRes.second;

        if(s[par] != childChar) {
            if(len >= maxLen){
                secondMaxLen = maxLen;
                maxLen = len;
            }
            else if(len > secondMaxLen) secondMaxLen = len;
        }
    }
    // leaders philosophy
    ans = max(ans, maxLen + secondMaxLen + 1);
    return {maxLen+1, s[par]};
}
int longestPath(vector<int>& parent, string s) {
    // prepare graph
    vector<vector<int>> graph(parent.size());
    for(int i=1; i<parent.size(); i++) graph[parent[i]].push_back(i); 
    int ans(1);
    dfs2246(0, s, graph, ans);
    return ans;
}
};