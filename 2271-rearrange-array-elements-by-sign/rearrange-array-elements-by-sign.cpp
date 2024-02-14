class Solution {
public:
// not optimized max O(N) O(N)
vector<int> rearrangeArray(vector<int>& nums) {
    int i(0);
    int posIdx(0), negIdx(1);    
    vector<int> ans(nums.size());
    while (i<nums.size())
    {
        bool isPositive = (nums[i]>=0);
        bool isPositiveExpected = ((i+1)%2);

        if(isPositive){
            ans[posIdx] = nums[i];
            posIdx += 2;
        }   
        else{
            ans[negIdx] = nums[i];
            negIdx += 2;
        }

        i++;
    }
    return ans;
}
};