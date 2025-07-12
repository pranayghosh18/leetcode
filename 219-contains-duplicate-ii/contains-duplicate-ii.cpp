class Solution {
public:
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    multiset<int> records;
    for(int r=0, f=0; r<nums.size(); r++){
        if(r-f > k){
            auto frontPtr = records.find(nums[f++]);
            if(frontPtr != records.end()) records.erase(frontPtr); 
        }
        if(records.find(nums[r]) != records.end()) return true;
        records.insert(nums[r]);
    }
    return false;
}
};