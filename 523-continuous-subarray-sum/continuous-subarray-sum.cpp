class Solution {
public:
bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> sumIndex;
    sumIndex[0] = -1;
    int ps(0);
    for(int i=0; i<nums.size(); i++){
        ps += nums[i]%k;
        ps %= k;
        // cout << "i : " << i << " ps : " << ps << endl;
        if(sumIndex.find(ps) != sumIndex.end()){
            // cout << "last " << sumIndex[ps]+1 << endl; 
            if(sumIndex[ps]+1 < i) return true;
        }
        else sumIndex[ps] = i;
    }        
    return false;
}
};