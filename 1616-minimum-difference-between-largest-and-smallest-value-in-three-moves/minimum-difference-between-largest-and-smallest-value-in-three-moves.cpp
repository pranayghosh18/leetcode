class Solution {
public:

int minDifference(vector<int>& nums) {
    if(nums.size() <= 4) return 0;
    sort(nums.begin(), nums.end());
    // 42/61
    // int i(0), j(nums.size()-1), count(0);
    // while (count < 3)
    // {
    //     if(nums[i+1] - nums[i] > nums[j] - nums[j-1]) i++;
    //     else j--;

    //     count++;
    // }
    // return nums[j]-nums[i];

    // sliding window
    int i(0), j(nums.size()-4);
    int dif(2e9+9);
    while(j < nums.size()) dif=min(dif, nums[j]-nums[i]),i++,j++;
    return dif;
}
};