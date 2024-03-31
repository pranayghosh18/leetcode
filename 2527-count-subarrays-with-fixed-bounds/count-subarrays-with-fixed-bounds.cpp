class Solution {
public:
    
long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    long long res(0);
    int newWindow(0), minKStartingIndex, maxKStartingIndex;
    bool minKElemSeen(false), maxKElemSeen(false);

    for(int i=0; i<nums.size(); i++){
        if(nums[i] < minK || nums[i] > maxK) newWindow=i+1, minKElemSeen=false, maxKElemSeen=false;
        if(nums[i] == minK) minKStartingIndex=i, minKElemSeen=true;
        if(nums[i] == maxK) maxKStartingIndex=i, maxKElemSeen=true;
        if(minKElemSeen && maxKElemSeen) res += (long long)(min(minKStartingIndex, maxKStartingIndex) - newWindow + 1);
    }
    return res;
}
};