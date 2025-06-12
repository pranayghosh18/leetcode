class Solution {
public:
int maxProduct(vector<int>& nums) {
    int maxProduct(nums[0]), minProduct(nums[0]);
    int res(*max_element(nums.begin(), nums.end()));
 
    for(int i=1; i<nums.size(); i++){
        if(nums[i] == 0) maxProduct = minProduct = 1;
        else{
            int temp = maxProduct;
            maxProduct = max({maxProduct*nums[i], minProduct*nums[i], nums[i]});
            minProduct = min({temp*nums[i], minProduct*nums[i], nums[i]});
            res = max(res, maxProduct);
        }
    }
    return res;
}
};