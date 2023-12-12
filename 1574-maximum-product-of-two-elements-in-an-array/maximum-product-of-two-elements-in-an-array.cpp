class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m(-1),n(-1);
        for(int i : nums) i >= m ? n=m, m=i : (i>n ? n=i : 0);
        return (m-1)*(n-1);
    }
};