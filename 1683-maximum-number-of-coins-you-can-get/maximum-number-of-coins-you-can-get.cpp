class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int res(0), idx(piles.size()-2), turns(piles.size()/3);
        while(turns-->0) res+=piles[idx], idx-=2;
        return res;
    }
};