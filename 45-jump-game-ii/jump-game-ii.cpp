class Solution {
public:
int jump(vector<int>& nums) {
    int jump(0), canGoTill(0);
    multiset<int, greater<int>> jumps;

    for(int i=0; i<nums.size(); i++){
        if(canGoTill < i) return -1;
        if(i == nums.size()-1) return jump;
        jumps.insert(i+nums[i]);
        if(i == canGoTill){
            int maxJump = *jumps.begin();
            jumps.erase(jumps.begin());
            canGoTill = maxJump;
            jump++;
        }
    }
    return jump;
}
};