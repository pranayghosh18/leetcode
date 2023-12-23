class Solution {
public:
    
vector<long long> coin100141;
   long long max(long long a, long long b){
    return a > b ? a : b;
}
   long long getVal100141(vector<long long> vec){
    if(vec.size() < 3) return 1;
    sort(vec.begin(), vec.end());
    long long min1 = vec[0];
    long long min2 = vec[1];
    int sz = vec.size();
    long long max1 = vec[sz-1];
    long long max2 = vec[sz-2];
    long long max3 = vec[sz-3];
    long long zero = 0;
    long long maxx = max(min1*min2, max2*max3); 
       long long  res = max(maxx*max1, zero); 
    return res;

}
vector<long long> dfs100141(int node, int par,unordered_map<int,vector<int>>& adj, vector<int>& cost){
    
    vector<long long> containers;
    // rec call
    for(int v : adj[node]){
        if(v != par){
        vector<long long> adj_v = dfs100141(v, node, adj, cost);
        for(long long val : adj_v) containers.push_back(val);
        }
    }
    long long curCost = cost[node];
    containers.push_back(curCost);

    // populate the value
    long long res = getVal100141(containers);
    coin100141[node] = res;

    sort(containers.begin(), containers.end());
    if(containers.size() > 6){
        // first 2 for mins, last 3 for maxs
        vector<long long> containerCpy;
        containerCpy.push_back(containers[0]);
        containerCpy.push_back(containers[1]);
        int sz = containers.size();
        containerCpy.push_back(containers[sz-1]);
        containerCpy.push_back(containers[sz-2]);
        containerCpy.push_back(containers[sz-3]);
        return containerCpy;
    }
    // cout <<"node : " << node << " adj  size " << containers.size() << " res : " << res << endl;
    return containers;
}
vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
    // create graph
    // cout <<"=============\n";
    unordered_map<int,vector<int>> adj;
    int n(0);
    for(auto e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
        n = std::max({n, e[0], e[1]});
        }
    coin100141.resize(n+1, -2);
    // for(int i=0; i<=n; i++){
    //     if(coin100141[i] == -2) dfs100141(i,-1,adj,cost);
    // }
    dfs100141(0,-1,adj,cost);
    return coin100141;
}
};