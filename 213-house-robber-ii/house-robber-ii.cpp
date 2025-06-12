class Solution {
public:
    int robOne(vector<int>& nums, int first, int last) {
    int include(nums[first]), exclude(0);
    for(int i=first+1; i<=last; i++){
        int next_exclude = max(include, exclude);
        include = exclude + nums[i];
        exclude = next_exclude;
    }
    return max(include, exclude);
}
    int rob(vector<int>& nums) {
        if(nums.size() < 3) return *max_element(nums.begin(), nums.end());
        return max(robOne(nums,0,nums.size()-2), robOne(nums, 1, nums.size()-1));
    }
};