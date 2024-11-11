class Solution {
public:
    bool isPrime(int n){
    for(int i=2; i*i<=n; i++) if(n%i == 0) return false;
    return true;
}
vector<int> heyPrimes(int limit){
    vector<int> primes = {0,2};
    for(int i=3; i<=limit; i++){
        if(isPrime(i)) primes.push_back(i);
    }
    return primes;
}

bool primeSubOperation(vector<int>& nums) {
    // get primes     
    int maxNum = *max_element(nums.begin(), nums.end());
    vector<int> primes = heyPrimes(maxNum);   
    int prev(0);
    for(int i : nums){
        if(prev >= i) return false;
        // downgrade i
        int del = i-prev;
        auto minusPos = lower_bound(primes.begin(), primes.end(), del);
        minusPos--;
        int minus = *minusPos;
        prev = i-minus;
    }
    return true;
}
};