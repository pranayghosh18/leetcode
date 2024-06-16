class Solution {
public:

int minPatches(vector<int>& nums, int n) {
    long long req(0), nextNum(1), i(0), sum(0);
    while(nextNum <= n){
        if(i<nums.size() && nums[i] <= nextNum){
            sum += (long long)nums[i];
            i++;
        }
        else{
            sum += nextNum;
            req++;
        }
        nextNum = sum+(long long)1;
    }  
    return req;
}
};