class Solution {
public:
int onesInList(vector<int>& lis){
    // for(int i: lis) cout << i << "\t";
    // cout<< endl;
    
    int sum(0), maxSum(0);
    for(int i: lis){
        sum = max(0, sum+i);
        maxSum = max(maxSum, sum);
    }
    // cout << maxSum;
    // cout<< endl;
    return maxSum;
}

int maxFrequency(vector<int>& nums, int k) {
    int kFreq(0);
    unordered_set<int> uniques;
    for(int i: nums) {
        uniques.insert(i);
        if(i == k) kFreq++;
    }
    int res(kFreq);
    for(int i : uniques){
        vector<int> clone(nums.size());
        for(int p=0; p<nums.size(); p++){
            if(nums[p] == k) clone[p] = -1;
            else clone[p] = nums[p] == i ? 1 : 0;
        }
        res = max(res, kFreq + onesInList(clone));
    }
    return res;
}
};