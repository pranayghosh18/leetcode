class Solution {
public:

int maxSubArray(vector<int>& nums) {
    // kadane
    int winSum(0), maxSum(-1e9);
    for(int i : nums){
        // should take prev contribution
        if(winSum >= 0) winSum += i;
        else winSum = i;

        maxSum = max(maxSum, winSum);
    }
    return maxSum;
}
};