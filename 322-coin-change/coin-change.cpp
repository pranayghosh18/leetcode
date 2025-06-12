class Solution {
public:
    
int coinChange(vector<int>& coins, int amount) {
    vector<int> ddp(amount+1, 1e9);
    ddp[0] = 0;
    for(int i=1; i<=amount; i++){
        for(int c : coins){
            if(i-c >= 0) ddp[i] = min(ddp[i], 1+ddp[i-c]);
        }
    }    
    return ddp[amount] == 1e9 ? -1 : ddp[amount];
}
};