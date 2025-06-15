class Solution {
public:
int findDuplicate(vector<int>& nums) {
    for(int i=0; i<nums.size(); i++){
        int elem = abs(nums[i]);
        // if(nums[elem] < 0) return elem;
        int effectivePosition = elem - 1;
        if(nums[effectivePosition] < 0) return elem;
        nums[effectivePosition] *= -1;
    }
    return -1;
}
};