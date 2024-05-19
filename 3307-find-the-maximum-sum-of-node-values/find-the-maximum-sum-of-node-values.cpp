class Solution {
public:
 long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
    long long res(0); 
    int minAffexted(1e9), xored(0);
    for(int i: nums){
        int xorVal = i^k;
        if(xorVal > i){
            res += (long long)xorVal;
            minAffexted = min(minAffexted, xorVal-i); 
            xored++;
        }
        else{
            res += (long long)i;
            minAffexted = min(minAffexted, i-xorVal);
        }
    }
    return res - (xored&1 ? (long long)minAffexted : 0);
}
};