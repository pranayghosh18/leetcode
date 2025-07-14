class Solution {

    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int ans = 0;
        int mul = 1;
        for(int r=0, f=0; r<nums.length; r++){
            mul *= nums[r];
            while (mul >= k && f <= r) mul /= nums[f++];
            ans += r-f+1;
        }
        return ans;
    }
}