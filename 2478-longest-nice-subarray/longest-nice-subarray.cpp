class Solution {
public:
    
void fillBits_2401(vector<int>& bitCount, int n){
    for(int i=0; i<32; i++) if((1<<i) & n) bitCount[i]++;
}
void delBits_2401(vector<int>& bitCount, int n){
    for(int i=0; i<32; i++) if((1<<i) & n) bitCount[i]--;
}
bool valid_2401(vector<int>& bitCount){
    // for(int i: bitCount) cout << i << "\t";
    // cout << endl;
    for(int i: bitCount) if(i>1) return false;
    return true;
}
int longestNiceSubarray(vector<int>& nums) {
    int f(0),r(0),len(-1);
    vector<int> space(32,0);
    fillBits_2401(space, nums[0]);
    // cout << "jeely \n";
    while(r<nums.size()){
        // cout << "appl \n";
        if(valid_2401(space)){
            len = max(len, r-f+1);
            r++;
            if(r<nums.size()) fillBits_2401(space, nums[r]);
        }
        else{
            delBits_2401(space, nums[f]);
            f++;
        }
    }
    return len;
}
};