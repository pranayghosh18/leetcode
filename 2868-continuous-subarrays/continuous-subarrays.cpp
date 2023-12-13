class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
    int f(0),r(0);
    long long res(0);
    multiset<int> windowElements;
    windowElements.insert(nums[0]);

    while(r<nums.size()){
        int smallest = *windowElements.begin();
        int biggest = *windowElements.rbegin();
        // valid
        if(biggest - smallest <= 2){
            res += (r-f+1);
            r++;
            if(r<nums.size()) windowElements.insert(nums[r]);
        }
        // invalid
        else{
            auto frontElemIterator = windowElements.find(nums[f]);
            windowElements.erase(frontElemIterator);
            f++;
        }
    }
    
    return res;
}
};