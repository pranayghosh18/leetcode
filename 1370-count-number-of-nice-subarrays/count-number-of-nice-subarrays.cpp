class Solution {
public:
    int getSubarrayHavingKorMoreOdds(vector<int>& nums, int k){
    int ans(0);
    for(int r=0, f=0; r<nums.size(); r++){
        if(nums[r]&1) k--;
        while(k == 0){
            ans += (nums.size()-r);
            if(nums[f] & 1) k++;
            f++;
        }
    }
    return ans;
}

int numberOfSubarrays(vector<int>& nums, int k) {
    return getSubarrayHavingKorMoreOdds(nums, k) - getSubarrayHavingKorMoreOdds(nums, k+1);
}
};