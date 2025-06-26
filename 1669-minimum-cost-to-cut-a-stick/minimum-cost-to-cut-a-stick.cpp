class Solution {
public:
int dfs1547(vector<int>& cuts, int l, int r, vector<vector<int>>& memo){
    if(r - l <= 1) return 0;
    if( r - l == 2) return cuts[r] - cuts[l];
    if(memo[l][r] != -1) return memo[l][r];

    int minCut(1e9);
    for(int cutPos=l+1; cutPos<r; cutPos++){
        int leftCut = dfs1547(cuts, l, cutPos, memo);
        int rightCut = dfs1547(cuts, cutPos, r, memo);
        
        minCut = min(minCut, leftCut+rightCut);
    }
    return memo[l][r] = minCut + (cuts[r] - cuts[l]);
}
int minCost(int n, vector<int>& cuts) {
    cuts.push_back(0), cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> memo(cuts.size(), vector<int>(cuts.size(), -1));
    return dfs1547(cuts, 0, cuts.size()-1, memo);
}
};