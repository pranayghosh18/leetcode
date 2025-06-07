class Solution {
public:
int characterReplacement(string s, int k) {
    int mx(0), f(0), maxFreq(0);
    unordered_map<char, int> hm;
    for(int r=0; r<s.size(); r++){
        // put 
        hm[s[r]]++;
        maxFreq = max(maxFreq, hm[s[r]]);
        // filter
        while((r-f+1) - maxFreq > k){
            hm[s[f]]--;
            f++;
        }
        // record
        mx = max(mx, r-f+1);
    }
    return mx;
}
};