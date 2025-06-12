class Solution {
public:
int maxProduct(vector<int>& nums) {
    vector<int> maxProduct(nums.size()), minProducts(nums.size());
    int res(*max_element(nums.begin(), nums.end()));
    maxProduct[0] = minProducts[0] = nums[0];
    for(int i=1; i<nums.size(); i++){
        if(nums[i] == 0) maxProduct[i] = minProducts[i] = 1;
        else{
            maxProduct[i] = max({maxProduct[i-1]*nums[i], minProducts[i-1]*nums[i], nums[i]});
            minProducts[i] = min({maxProduct[i-1]*nums[i], minProducts[i-1]*nums[i], nums[i]});
            res = max(res, maxProduct[i]);
        }
    }
    return res;
}
};