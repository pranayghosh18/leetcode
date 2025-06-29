class Solution {
public:
bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum & 1) return false;
    int target = sum/2;
    vector<bool> currentPossibilities(target+1, false);
    currentPossibilities[0] = true;
    for(int i:nums){
        vector<bool> nextPossibilites = currentPossibilities;
        for(int t=1; t<=target; t++) if(t - i >= 0) nextPossibilites[t] = nextPossibilites[t] || currentPossibilities[t-i];
        currentPossibilities = nextPossibilites;
    }
    return currentPossibilities.back();
}
};
