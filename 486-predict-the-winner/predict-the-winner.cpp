class Solution {
public:
    // bool PredictTheWinner(vector<int>& nums) {
    //     if(nums.size()&1 == 0) return true;
    //     int l(0),r(0);
    //     for(int i=0; i<nums.size()/2; i++){
    //         l += nums[i];
    //         r += nums[nums.size()-1-i];
    //     }
    //     int m = nums[nums.size()/2];
    //     //cout <<"l : " << l << " m : "<< m <<" r : "<<r;
    //     return ((r >= l+m) || (l >= r+m));
    // }
    
vector<vector<int>> dp;
int util_486(vector<int>& nums, int i, int j){
    // 3. dp
    if(dp[i][j] != 0) return dp[i][j];
    // 2. base
    //if(j-i<2) return dp[i][j] = max(nums[i], nums[j]);
    if(i == j) return nums[i];
    // 1. recursive
    int left_picked = nums[i] - util_486(nums,i+1,j);
    int right_picked = nums[j] - util_486(nums,i,j-1);

    return dp[i][j] = max(left_picked, right_picked);
}
bool predictTheWinner(vector<int>& nums) {
    dp.resize(nums.size(), vector<int>(nums.size(),0));
    int waste = util_486(nums, 0, nums.size()-1);
    return (dp[0][nums.size()-1] >= 0);
}
// bool PredictTheWinner(vector<int>& nums) {
//     vector<vector<int>> dp(nums.size(), vector<int>(nums.size(),0));
//     for(int d=0; d<nums.size(); d++){
//         for(int i=0, j=i+d; j<nums.size(); i++, j++) dp[i][j] = (i==j)? nums[i] : max(nums[i]-dp[i+1][j], nums[j]-dp[i][j-1]);
//     }
//     return (dp[0][nums.size()-1] >= 0);
// }
};