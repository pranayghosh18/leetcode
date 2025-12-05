class Solution {
    
        public int countPartitions(int[] nums) {
            int ans = 0;
            int totalSum = 0;
            for (int i : nums) totalSum += i;

            int leftSum = 0;
            for (int divider=0; divider<nums.length-1; divider++) {
                leftSum += nums[divider];
                if ((totalSum - 2*leftSum) % 2 == 0) ans++;
            }
            return ans;
        }
}