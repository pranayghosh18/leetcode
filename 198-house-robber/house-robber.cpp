class Solution {
public:

int rob(vector<int>& nums) {
    int include(nums[0]), exclude(0);
    for(int i=1; i<nums.size(); i++){
        int next_exclude = max(include, exclude);
        include = exclude + nums[i];
        exclude = next_exclude;
    }
    return max(include, exclude);
}
};