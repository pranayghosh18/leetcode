class Solution {
public:
vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int m = rolls.size();
    int total(mean * (m+n));
    for(int i : rolls) total -= i;
    if(total > 6*n || total < n) return {};
    vector<int> ans(n,0);
    int i(0);
    while (total-- > 0)
    {
        ans[i]++;
        i = (i+1)%n;
    }
    return ans;
}
};