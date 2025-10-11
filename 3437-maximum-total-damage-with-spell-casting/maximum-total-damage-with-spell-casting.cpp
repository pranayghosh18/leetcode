class Solution {
public:
   long long maximumTotalDamage(vector<int>& power) {
    unordered_map<int, long long> hm;
    for(int i:power) hm[i]++;
    vector<pair<long long,long long>>v;
    for(auto i : hm) v.push_back({i.first, i.second});
    sort(v.begin(), v.end());
    vector<long long> dp(v.size(), 0), maxdp(v.size(), 0);
    long long res(0);

    // for(int i=0; i<v.size(); i++){
    //     long long take(0);
    //     for(int j=i-1; j>=max(0, i-3); j--){
    //         if(v[i].first - v[j].first < 2) take = max(take, dp[j]);
    //     }
    //     dp[i] = take + (v[i].first * v[i].second);
    //     res = max(res, dp[i]);
    // }      

    dp[0] = v[0].first * v[0].second;
    maxdp[0] = dp[0];
    res = dp[0];

    for(int i=1; i<v.size(); i++){
        int j = i;
        while(j>=0 && v[i].first - v[j].first <= 2) j--;

        long long take = j==-1 ? 0 : maxdp[j];

        dp[i] = take + (v[i].first * v[i].second);
        maxdp[i] = max(dp[i], maxdp[i-1]);

        res = max(res, dp[i]);
    }      
    return res;
}
};