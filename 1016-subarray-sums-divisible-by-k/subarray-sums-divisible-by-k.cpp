class Solution {
public:
int mod(long x, int m){
    while(x<0) x+=m;
    return x%m;
}
int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int,int> hm;
    hm[0]=1;
    long ps(0), count(0);
    for(int i : nums){
        ps += i;
        int val = mod(ps,k);
        if(hm.find(val)!=hm.end()) count += hm[val];
        hm[val]++;
    }
    return count;
}
};