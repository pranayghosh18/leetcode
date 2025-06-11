class Solution {
public:
int countSubstrings(string s) {
    int res(0), l, r;
    for(int i=0; i<s.size(); i++){
        // odd length palindromes
        l = r = i;
        while (l>=0 && r<s.size() && s[l]==s[r]) res++, l--, r++;
        // even length palidromes
        l = i, r = i+1;
        while (l>=0 && r<s.size() && s[l]==s[r]) res++, l--, r++;
    }
    return res;
}
};