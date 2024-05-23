class Solution {
public:
int util_2597(vector<int>& nums, int& k, int i, unordered_map<int, int>& taken){
    if(i==nums.size()) return taken.size() > 0 ? 1 : 0;

    // not taken
    int dont = util_2597(nums, k, i+1, taken);
    int take = 0;

    if(!taken[nums[i]-k] && !taken[nums[i]+k]){
        // take current one
        taken[nums[i]]++;
        take = util_2597(nums, k, i+1, taken);
        // auto it = taken.find(nums[i]);
        // taken.erase(it);
        taken[nums[i]]--;
    }

    return dont+take;
}
int beautifulSubsets(vector<int>& nums, int k) {
    unordered_map<int, int> taken;
    return util_2597(nums, k, 0, taken);
}
};