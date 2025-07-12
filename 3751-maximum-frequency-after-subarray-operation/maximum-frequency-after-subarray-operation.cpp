class Solution {
public:
int maxFrequency(vector<int>& nums, int k) {
    int kFreq(0);
    unordered_set<int> uniques;
    for(int i: nums) {
        uniques.insert(i);
        if(i == k) kFreq++;
    }
    int res(kFreq);
    for(int i : uniques){
        // apply the logic here
        int sum(0), maxSum(0), elem;
        for(int p=0; p<nums.size(); p++){
            if(nums[p] == k) elem = -1;
            else elem = nums[p] == i ? 1 : 0;

            sum = max(elem, elem+sum);
            maxSum = max(maxSum, sum);
        }
        res = max(res, kFreq + maxSum);
    }
    return res;
}
};