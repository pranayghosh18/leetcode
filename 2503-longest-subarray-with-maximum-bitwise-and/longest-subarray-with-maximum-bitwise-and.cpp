class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end());
       int l(0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]==m){
                int ni=i;
                while(ni<nums.size() && nums[ni]==nums[i]) ni++;
               l = max(l, ni-i);
                i=ni-1;
            }
        }
       return l;
    }
};