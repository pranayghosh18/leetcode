class Solution {
public:

int minimumAddedCoins(vector<int>& coins, int target) {
    int maxPossible(0), require(0), nextSum;
    int i(0);
    sort(coins.begin(), coins.end());
    while(target > maxPossible){
        nextSum = maxPossible + 1;
        // can take current coin
        if(i<coins.size() && coins[i] <= nextSum){
            maxPossible += coins[i++];
        }
        // cant, so take a coin of nextSum value
        else{
            maxPossible += nextSum;
            require++;
        }
    }

    return require;
}
};