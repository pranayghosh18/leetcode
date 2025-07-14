class Solution {
public:

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int ans(0), mul(1);
    for(int r=0, f=0; r<nums.size(); r++){
        mul *= nums[r];
        while(mul >= k && f <= r) mul /= nums[f++];
        ans += max(0,(r-f+1));
            // cout <<"r " << r << " f " << f << " len " << (r-f+1) << "\n";
    }
    return ans;
}
};