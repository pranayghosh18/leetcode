
class Solution {
public:
// top down
int lisDfs(vector<int>& nums, int i, int last, vector<vector<int>>& dp){
    // base
    if(i == nums.size()) return 0;
    if(last != -1 && dp[i][last] != -1) return dp[i][last];
    // dont take
    int ignore = lisDfs(nums, i+1, last, dp);
    // take it
    int taken = 0;
    if(last == -1 || nums[i] > nums[last]) taken = 1 + lisDfs(nums, i+1, i, dp);

    if(last != -1) dp[i][last] = max(ignore, taken);
    return max(ignore, taken);
}
int lengthOfLIS(vector<int>& nums) {
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
    return lisDfs(nums, 0, -1, dp);
}
};
