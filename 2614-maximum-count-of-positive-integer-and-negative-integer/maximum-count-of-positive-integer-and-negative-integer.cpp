class Solution {
public:
int maximumCount(vector<int>& nums) {
    auto zeroUb = upper_bound(nums.begin(), nums.end(), 0);
    int positives = nums.end() - zeroUb;
    cout<< "pos " << positives << endl;
    
    auto zeroLb = lower_bound(begin(nums), end(nums), 0);
    int negatives(0);
    if(zeroLb != nums.end() && *zeroLb == 0){
        if(zeroLb == nums.begin()) negatives = 0; 
        else{
            zeroLb--;
            negatives = zeroLb - nums.begin() + 1;
        }
    }
    else{
        negatives = zeroLb - nums.begin();
    }
    
    cout<< "neg " << negatives << endl;
    return max(positives, negatives);
}
};