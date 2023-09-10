class Solution {
public:
    int countOrders(int n) {
    int mod = 1e9+7;
    long ans(1);
    for(int i=1; i<=2*n; i++){
        if(i&1) {
            ans = ans*(long)i;
            ans %= mod;
            }
        else{
            ans = ans*(long) (i/2);
            ans %= mod;
        }
    }
    return ans;
}
};