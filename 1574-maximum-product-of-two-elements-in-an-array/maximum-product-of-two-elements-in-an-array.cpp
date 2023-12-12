class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m(-1),n(-1);
        for(int i : nums) i >= m ? n=m, m=i : (i>n ? n=i : n=n);
        return (m-1)*(n-1);
    }
};