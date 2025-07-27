class Solution {
public:
int countHillValley(vector<int>& nums) {
    int u(0);
    for(int i=1; i<nums.size(); i++) if(nums[i] != nums[u]) nums[++u] = nums[i];
    int i(1), count(0);
    while (i<u)
    {
        if(nums[i-1] > nums[i] && nums[i+1] > nums[i]) count++;
        if(nums[i-1] < nums[i] && nums[i+1] < nums[i]) count++;
        i++;
    }

    return count;  
}
};