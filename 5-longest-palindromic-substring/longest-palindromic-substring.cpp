class Solution {
public:
string longestPalindrome(string s) {
    // using 2 ptr
    int maxLen(1);
    int startPos(0);
    // odd length palindrome
    for(int i=0; i<s.size(); i++){
        int l(i), r(i);
        while(l>=0 && r<s.size() && s[l]==s[r]){
            if(r-l+1 > maxLen){
                maxLen = r-l+1;
                startPos = l;
            }
            l--; r++;
        } 
    }
    // check for even length palindrome
    for(int i=0; i<s.size(); i++){
        int l(i), r(i+1);
        while(l>=0 && r<s.size() && s[l]==s[r]) {
            if(r-l+1 > maxLen){
                maxLen = r-l+1;
                startPos = l;
            }
            l--; r++;
        }
    }
// cout << "pos " << startPos << " len " << maxLen;
    return s.substr(startPos, maxLen);
}
};