class Solution {
public:
long long distributeCandies(int n, int limit) {
    long long res(0);

    for(int a=max(0, n-2*limit); a<=min(n,limit); a++){
        int b = min(limit, n-a) - max(0, n-a-limit) + 1;
        res += b;
    }        
    
    return res;
}
};