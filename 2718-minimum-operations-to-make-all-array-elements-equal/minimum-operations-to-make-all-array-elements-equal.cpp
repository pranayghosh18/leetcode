class Solution {
public:
#define ll long long
ll getRangeSum(vector<long long>& prefixSum, int l, int r) {
    ll right = prefixSum[r];
    ll left = l==0? 0 : prefixSum[l-1];
    return right-left;
}

ll getValue(vector<int>& nums, vector<ll>& prefixSum, ll q){
    auto lb = lower_bound(nums.begin(), nums.end(), q);
    ll leftSum(0), rightSum(0);
    int idx = lb-nums.begin();
    if(lb != nums.begin()){
        ll req = (ll)(idx) * q;
        ll have = getRangeSum(prefixSum, 0, idx-1);
        leftSum = req - have;
    }
    ll rightReq = (ll)(nums.size() - idx)*q;
    ll rightHave = getRangeSum(prefixSum, idx, nums.size()-1);
    rightSum = rightHave - rightReq;

    return (leftSum + rightSum);
}

vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
    sort(nums.begin(), nums.end());
    vector<ll> prefixSum(nums.size(), 0);
    prefixSum[0] = nums[0];
    for(int i=1; i<nums.size(); i++) prefixSum[i] = prefixSum[i-1] + nums[i];

    vector<ll> res;
    for(auto q : queries){
        res.push_back(getValue(nums, prefixSum, q));
    }
    return res;
}
};