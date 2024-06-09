class Solution {
public:
int helpVec(vector<int>&ar, int i, int sum, vector<vector<int>>& rec){
    if(sum > 4000) return 0;
    if(i==ar.size()) return sum;

    if(rec[i][sum] != -1) return rec[i][sum];
    int tk(0), nt(0);

    if(ar[i] > sum) tk = helpVec(ar, i+1, sum+ar[i], rec);
    nt = helpVec(ar, i+1, sum, rec);

    return rec[i][sum] = max(tk, nt);
}

int maxTotalReward(vector<int>& rv) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sort(rv.begin(), rv.end());        
    vector<vector<int>> rec(rv.size()+1, vector<int>(4000, -1));
    return helpVec(rv, 0, 0, rec);
}

};