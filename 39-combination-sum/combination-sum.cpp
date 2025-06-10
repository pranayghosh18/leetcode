class Solution {
public:

void csUtil(vector<int>& nums, int target, int idx, vector<int>& temp, int tempSum, vector<vector<int>>& res){
    // end of data
    if(idx == nums.size()) return;
    // matching base
    if(tempSum == target){
        res.push_back(temp);
        return;
    }
    // overshooting
    if(tempSum > target) return;

    // either take current element
    temp.push_back(nums[idx]);
    tempSum += nums[idx];
    // recursive call
    csUtil(nums, target, idx, temp, tempSum, res);
    temp.pop_back();
    tempSum -= nums[idx];

    // or dont
    csUtil(nums, target, idx+1, temp, tempSum, res);
}
vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    vector<int> current;
    csUtil(nums, target, 0, current, 0, res);
    return res;
}
};