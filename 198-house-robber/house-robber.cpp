class Solution {
public:
    int rob(vector<int>& nums) {
        int i(0),e(0);
        for(int t : nums)
            {
                int pi = i; 
                i = max(e+t,i);
                e = max(pi,e);
            }
        return max(i,e);
    }
};