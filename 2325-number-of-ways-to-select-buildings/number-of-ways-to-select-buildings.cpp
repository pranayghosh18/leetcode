class Solution {
public:
long long numberOfWays(string s) {
    long long ans(0);
    long long zerosLeft(0), totalZeros(0);
    for(char c : s) if(c == '0') totalZeros++;
    if(s[0] == '0') zerosLeft++;
    for(int i=1; i<s.size()-1; i++){
        if(s[i] == '1'){
            // get 0's left
            // get 0's right
            long long rightZeros = totalZeros - zerosLeft;
            ans += zerosLeft * rightZeros; 
        }
        else{
            // get 1's left
            long long onesLeft = (long long)i - zerosLeft;
            // get 1's right
            // chars on right = (long long)s.size() - i -1
            // zeros on right except this = totalZeros - zerosLeft - 1
            long long onesRight = (long long)s.size() - (long long)i - 1 - totalZeros + zerosLeft + 1;
            ans += onesLeft*onesRight;

            zerosLeft++;
        }
    }
    return ans;
}
};